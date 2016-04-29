#include <cassert>
#include <string>
#include <iostream>
#include <list>

#include <core/font.h>
#include <core/rect.h>
#include <core/environment.h>
#include <core/canvas.h>
#include <core/image.h>

#include "room.h"

ActionID Room::guardDeathID { "guardDeathID()" };

static int randint(int a, int b)
{
    int N = b - a + 1;
    int r = rand() % N;

    return a + r;
}

Room::Room(Object *parent, ObjectID id, string type, Room *left, Room *top, Room *right, Room *bottom, int s_id)
: Object(parent, id), r_left(left), r_right(right), r_top(top), r_bottom(bottom), type(type), stage_id(s_id),
    m_doors(false)
{
    assert((parent != NULL) && "parent can't be NULL");
    assert((not id.empty()) && "id can't be empty");
    assert((not type.empty()) && "id can't be empty");

    Environment *env = Environment::get_instance();
    quad = new Quadtree(0, new Rect(0, 0, env->canvas->w(), env->canvas->h()));

    fill_floor("tile");
    add_walls("parede");
    add_corners("canto");
    add_items(stage_id);
    add_guard("guard");
    add_ghost("ghost");

    if(r_left)
    {
        r_left->notify_creation("right");
        this->add_door("normal", 'l', 0, 320);
    }
    if(r_top)
    {
        r_top->notify_creation("bottom");
        this->add_door("normal",'t', 600, 0);
    }
    if(r_right)
    {
        r_right->notify_creation("left");
        this->add_door("normal",'r', 1200, 320);
    }
    if(r_bottom)
    {
        r_bottom->notify_creation("top");
        this->add_door("normal",'b', 600, 640);
    }

    if(type == "Final")
    {
        add_final_door();
    }

    add_observer(this);
}

Room::~Room()
{
}

string Room::room_type()
{
	if (this->type == "CelaH" || this->type == "CelaV")
		return "Cela";

	return this->type;
}

void Room::add_items(int stage_id)
{
    typedef struct _ItemInfo {
        string name;
        string type;
        int variations;
        int weight;
        bool walkable;
        bool unique;
        double mass;
        int x, y;
    } ItemInfo;

    list<ItemInfo> items;

    if(stage_id < 3)
    {
        items = {
            {"Bancada", "tile_sheet", 2, 20, false, true, INFINITE, 520, 240},
            {"Cadeira", "tile_sheet", 2, 40, false, false, 5.0, -1, -1},
            {"CadeiraseMesa", "tile_sheet", 3, 40, false, false, 25.0, -1, -1},
            {"Mesa", "tile_sheet", 2, 40, false, false, 20.0, -1, -1},
            {"Papeis", "tile_sheet", 0, 70, true, false, 0.0, -1, -1},
            {"Pill1", "item", 0, 10, true, false, 0.0, -1, -1},
            {"Pill2", "item", 0, 15, true, false, 0.0, -1, -1},
            {"Garrafa", "item", 0, 70, true, false, 0.0, -1, -1},
            {"Relogio", "tile_sheet", 0, 5, true, false, 20.0, -1, -1},
        };

    }

    else
    {
        items  = {
            {"Armario2", "tile_sheet", 0, 20, false, false, 20.0, -1, -1},
            {"ArmarioDeArquivos", "tile_sheet", 0, 40, false, false, 20.0, -1, -1},
            {"ArmarioDeArquivosPapeis", "tile_sheet", 0, 40, false, 25.0, false, -1, -1},
            {"Cama", "tile_sheet", 0, 40, false, false, 20.0, -1, -1},
            {"Papeis", "tile_sheet", 0, 70, true, false, 0.0, -1, -1},
            {"Pill1", "item", 0, 10, true, false, 0.0, -1, -1},
            {"Pill2", "item", 0, 15, true, false, 0.0, -1, -1},
            {"Garrafa", "item", 0, 5, true, false, 0.0, -1, -1},
            {"MesaHospitalar", "tile_sheet", 0, 40, false, false, 25.0, -1, -1},
            {"MesaHospitalarCust", "tile_sheet", 0, 40, false, false, 5.0, -1, -1},
            {"PiaGrande", "tile_sheet", 0, 40, false, false, 5.0, -1, -1},
            {"CaixasEmpilhadas", "tile_sheet", 0, 40, false, false, 25.0, -1, -1},
            {"Caixa", "tile_sheet", 0, 40, false, false, 5.0, -1, -1},

        };
    }

    int total_weight = 0;

    for (auto item : items)
    {
        total_weight += item.weight;
    }

	if (room_type() == "KeyRoom")
	{
        char prepath[256];
        sprintf(prepath,"res/items/");
        char newpath[256];
        if(stage_id < 5)
            sprintf(newpath, "%skey%d.png",prepath, stage_id);
        else
            sprintf(newpath, "%skey5.png", prepath);
        Item* item = new Item(this, "key", newpath, 300, 300, 1.0, true);

        while (not place(item, -1, -1));

        add_child(item);
	}

    static const int MAX_ITENS = 15;
    int num_items = randint(0, MAX_ITENS);

    for (int i = 0; i < num_items and (not items.empty()); ++i)
    {
        int p = randint(1, total_weight);
        auto it = items.begin();
        int total = it->weight;

        while (p > total)
        {
            ++it;
            total += it->weight;
        }

        char path[512];
        char prepath[256];
        if(it->type == "item")
            sprintf(prepath,"res/items/");
        else
            sprintf(prepath,"res/tile_sheets/");

        if (it->variations)
        {
            int variation = randint(1, it->variations);
            sprintf(path, "%s%s%d.png", prepath, it->name.c_str(), variation);
        } else
        {
            sprintf(path, "%s%s.png", prepath, it->name.c_str());
        }

        double x = it->x;
        double y = it->y;

        Item* item = new Item(this, it->name, path, x, y, it->mass, it->walkable);

        if (place(item, x, y))
            add_child(item);
        else
            delete item;

        if (it->unique)
        {
            total_weight -= it->weight;
            items.erase(it);
        }
    }
}

void
Room::add_list(Object  * item)
{
    assert((item != NULL) && "Item should be diferent of NULL");
	this->items.push_back(item);
}

const list<Object *>&
Room::get_items()
{
	return children();
}


void Room::check_entry()
{
	Environment *env = Environment::get_instance();
	if(this->r_left)
	{
		Rect l_door {0, 340, 80, 80};
		env->canvas->draw(l_door, Color::WHITE);

	}
	if(this->r_top)
	{
		Rect t_door {600, 0, 80, 80};
		env->canvas->draw(t_door, Color::WHITE);

	}
	if(this->r_right)
	{
		Rect r_door {1200, 340, 80, 80};
		env->canvas->draw(r_door, Color::WHITE);

	}
	if(this->r_bottom)
	{
		Rect b_door {600, 640, 80, 80};
		env->canvas->draw(b_door, Color::WHITE);

	}
}

void
Room::draw_id(Room * anterior, Room * sala, int x, int y)
{
    //assert((anterior != NULL) && "Room can't be NULL");
	Environment *env = Environment::get_instance();
	shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
	env->canvas->set_font(font);
	env->canvas->draw(sala->id(),x,y,Color::RED);

	if(sala->r_left && sala->r_left != anterior)
	{
		env->canvas->draw("-", x - 20, y,Color::RED);
		draw_id(sala, sala->r_left, x - 100, y);
	}
	if(sala->r_top && sala->r_top != anterior)
	{
		env->canvas->draw("|", x + 20, y - 30,Color::RED);
		draw_id(sala, sala->r_top, x, y - 60);
	}
	if(sala->r_right && sala->r_right != anterior)
	{
		env->canvas->draw("-", x + 80, y,Color::RED);
		draw_id(sala, sala->r_right, x + 100, y);
	}
	if(sala->r_bottom && sala->r_bottom != anterior)
	{
		env->canvas->draw("|", x + 20, y + 25,Color::RED);
		draw_id(sala, sala->r_bottom, x, y + 60);
	}
}

void
Room::draw_self()
{
    Environment *env = Environment::get_instance();
    draw_id(NULL, this, 640, 360);
    Rect square {635, 355, 80, 40};
    env->canvas->draw(square, Color::RED);
}

void
Room::add_door(string type, char direction, int x, int y)
{
    assert((not type.empty()) && "type can't be empty");
    char doorID[128];
    char door_sprite[256];
    int stages = 1;
    if(stage_id < 3)
        stages = 1;
    else if(stage_id < 4)
        stages = 3;
    else
        stages = 4;

    if(type == "normal")
    {
        sprintf(door_sprite, "res/tile_sheets/porta%d%c.png", stages, direction);
        sprintf(doorID, "porta%c%s", direction, id().c_str());
        Item *porta = new Item(this, "door", door_sprite, x, y, INFINITE, true);

        add_child(porta);
    }
    else if (type == "finalDoor")
    {
        sprintf(doorID, "stage");
        sprintf(door_sprite, "res/door/porta%c.png", direction);
        Item *porta = new Item(this, "finalDoor", door_sprite, x, y, INFINITE, true);

        add_child(porta);
    }

    const list<Object *> items = this->children();
    for (auto item : items)
    {
        char buffer[256];
        sprintf(buffer, "parede");
        if(strcmp(item->id().c_str(), buffer) == 0)
        {
            if((item->x() > x - item->w() && item->x() < x + item->w()) && item->y() == y)
            {
                item->set_walkable(true);
            }
        }
    }
}

void
Room::add_final_door()
{
    double x = 0 + (r_top || r_bottom)*600 + (bool)r_left*1200;
    double y = 0 + (r_left || r_right)*320 + (bool)r_top*640;
    char dir;
    if(this->r_right)
    {
        dir = 'l';
    }
    else if(this->r_bottom)
    {
        dir = 't';
    }
    else if(this->r_left)
    {
        dir = 'r';
    }
    if(this->r_top)
    {
        dir = 'b';
    }

    add_door("finalDoor", dir, x, y);
}

void
Room::remove_item(Object *item)
{
    assert((item != NULL) && "item can't be NULL");
	remove_child(item);
}

void
Room::fill_floor(const string& name)
{
    assert((not name.empty()) && "name can't be empty");
    char path[512];
    int stages = 1;
    if(stage_id < 3)
        stages = 1;
    else if(stage_id < 4)
        stages = 3;
    else
        stages = 4;

    sprintf(path, "res/tile_sheets/%s%d.png", name.c_str(), stages);

    Image *image = new Image(nullptr, name, path);

    if (not image)
    {
        return;
    }

    Environment *env = Environment::get_instance();
    Canvas *canvas = env->canvas;

    int w = canvas->w() / image->w();
    int h = canvas->h() / image->h();

    center_area.set_position(image->w(), image->h());
    center_area.set_dimensions(canvas->w() - 2*image->w(), canvas->h() - 2*image->h());

    for(int i = 1; i < w - 1; i++)
	{
		for(int j = 1; j < h - 1; j++)
		{
			Item *floor = new Item(this, name, path, i*image->w(), j*image->h(), INFINITE, true);
	 		add_child(floor);
		}
	}

    delete image;
}

void
Room::add_walls(const string& name)
{
    assert((not name.empty()) && "name can't be empty");
    Environment *env = Environment::get_instance();
    Canvas *canvas = env->canvas;

    char pos[4] = {'l', 't', 'r', 'b'};
    for (int i = 0; i < 4; ++i)
    {
        char path[512];
        int stages = 1;
        if(stage_id < 3)
        stages = 1;
        else if(stage_id < 4)
            stages = 3;
        else
            stages = 4;

        sprintf(path, "res/tile_sheets/%s%d%c.png", name.c_str(), stages, pos[i]);

        Image *image = new Image(nullptr, name, path);

        if (not image)
        {
            cout << path << " nao existe" << endl;
            continue;
        }

        for(int j = 1; j < 15; j++)
        {

            for(int k = 1; k < 8; k++)
            {
                double x = i % 2 ? image->w()*j : i/2 * (canvas->w() - image->w());
                double y = i % 2 ? i/2 * (canvas->h() - image->h()) : image->h()*k;

                Item *wall = new Item(this, name, path, x, y, INFINITE, false);
                add_child(wall);
            }

        }
        delete image;
    }
}

void
Room::add_corners(const string& name)
{
    assert((not name.empty()) && "name can't be empty");
    Environment *env = Environment::get_instance();
    Canvas *canvas = env->canvas;

    for (int i = 0; i < 4; ++i)
    {
        char path[512];
        if(stage_id < 3)
            sprintf(path, "res/tile_sheets/%s%d.png", name.c_str(), i + 1);
        else
        {
            int stages = 1;
            if(stage_id < 3)
                stages = 1;
            else if(stage_id < 4)
                stages = 3;
            else
                stages = 4;
            sprintf(path, "res/tile_sheets/%s%d%d.png", name.c_str(),stages, i + 1);
        }

        Image *image = new Image(nullptr, name, path);

        if (not image)
            continue;

        double x = i % 3 ? canvas->w() - image->w() : 0;
        double y = i/2 ? canvas->h() - image->h() : 0;

        delete image;

	    Item *corner = new Item(this, name, path, x, y, INFINITE, false);
	    add_child(corner);
    }
}

void
Room::add_guard(const string& name)
{
    assert((not name.empty()) && "name can't be empty");
    string type = "easy";
    int random = randint(0,2);

    if(random < 1)
        type = "easy";
    if(random < 2)
        type = "normal";
    else
        type = "hard";


    for(int i = 0; i < (stage_id / 3) + 1; i++)
    {
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        place(guard, -1, -1);
	    add_child(guard);
    }
}

void
Room::add_ghost(const string& name)
{
    assert((not name.empty()) && "name can't be empty");
    string type = "easy";

    for(int i = 0; i < (stage_id / 3); i++)
    {
        Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));
        place(ghost, -1, -1);
        add_child(ghost);
    }
}

bool
Room::place(Object *object, double x, double y)
{
    assert((object != NULL) && "Object can't be NULL");
    int w = center_area.w();
    int h = center_area.h();

    int tries = 0;
    bool ok, randomize = x < 0 and y < 0;

    do {
        ok = true;
        ++tries;

        if (randomize)
        {
            x = (rand() % w) + center_area.x();
            y = (rand() % h) + center_area.y();
        }

        if (x + object->w() > w + center_area.x())
            x = w + center_area.x() - object->w();

        if (y + object->h() > h + center_area.y())
            y = h + center_area.y() - object->h();

        for (auto obj : children())
        {
            if (obj->walkable())
                continue;

            Rect a { x, y, object->w(), object->h() };
            Rect b = obj->bounding_box();
            Rect c = a.intersection(b);

            if (c.w() or c.h())
            {
                ok = false;
                break;
            }
        }

        if (tries > 10)
            break;

    } while (not ok and randomize);

    object->set_position(x, y);

    return ok;
}

void
Room::notify_creation(const string& position)
{
    assert((not position.empty()) && "position can't be empty");
    //Environment *env = Environment::get_instance();
    //Canvas *canvas = env->canvas;

    if(position == "left")
    {
        add_door("normal", 'l', 0, 320);
    }
    else if(position == "top")
    {
        add_door("normal", 't', 600, 0);
    }
    else if(position == "right")
    {
        add_door("normal", 'r', 1200, 320);
    }
    else if(position == "bottom")
    {
       add_door("normal", 'b', 600, 640);
    }
}

void
Room::update_self(unsigned long)
{
    const list<Object *> npcs = children();
    quad->clear();
    for (auto npc : npcs)
    {
        if(npc->id() == "guard")
            quad->insert(npc);
    }

    for(auto npc: npcs)
    {
        list<Object*> returnObjects;
        returnObjects.erase(returnObjects.begin(), returnObjects.end());

        returnObjects = quad->retrieve(returnObjects, npc);

        for(auto npc2 : returnObjects)
        {
            Rect a = npc2->bounding_box();
            Rect b = npc->bounding_box();
            Rect c = a.intersection(b);

            if(npc2->id()== "guard")
            {
                Guard * guarda = (Guard*) npc2;

                if(npc->walkable() == false)
                {
                    if (c.w() > 5 and c.h() > 5)
                    {
                        if(guarda->m_old_type == "hard")
                        {
                            if(abs(a.x() - b.x()) > abs(a.y() - b.y()))
                            {
                                if(a.x() > b.x())
                                {
                                    npc->set_x(a.x() - b.w() + 1);
                                }
                                else if(a.x() < b.x())
                                {
                                    npc->set_x(a.x() + a.w() - 1);
                                }
                            }
                            else
                            {
                                if(a.y() > b.y())
                                {
                                    npc->set_y(a.y() - b.h() + 1);
                                }
                                else if(a.y() < b.y())
                                {
                                    npc->set_y(a.y() + a.h() - 1);
                                }
                            }
                        }
                        else
                        {
                            if(abs(a.x() - b.x()) > abs(a.y() - b.y()))
                            {
                                if(a.x() < b.x())
                                {
                                    npc2->set_x(b.x() - a.w() + 1);
                                }
                                else if(a.x() > b.x())
                                {
                                    npc2->set_x(b.x() + b.w() - 1);
                                }
                            }
                            else
                            {
                                if(a.y() < b.y())
                                {
                                    npc2->set_y(b.y() - a.h() + 1);
                                }
                                else if(a.y() > b.y())
                                {
                                    npc2->set_y(b.y() + b.h() - 1);
                                }
                            }
                        }
                    }
                }
            }
        }


        if(npc->id() == "guard")
        {
            Guard * guarda = (Guard*) npc;
            if (guarda->health() < 1)
            {
                Ghost *ghost = new Ghost(this, "ghost", 0, 0, 9999, true, guarda->m_old_type, randint(0,3));
                string path;
                if(guarda->m_old_type != "hard")
                    path = "res/sprites/death_guard1.png";
                else
                    path = "res/sprites/death_guard2.png";
                Item *body = new Item(this, "body", path, 0, 0, 9999, true);
                place(body, npc->x(), npc->y());
                remove_child(npc);
                add_child(body);
                place(ghost, npc->x(), npc->y());
                add_child(ghost);

                notify(guardDeathID, "guarda");
            }
        }
    }
}
