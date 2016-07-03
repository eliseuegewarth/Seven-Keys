/**
 * room.cpp
 * Class that implements the room of game. The room will contais objects like enemies and obstacles.
 * Licença: LGPL. Sem copyright.
 */

#include <cassert>
#include <string>
#include <iostream>
#include <list>

#include "core/font.hpp"
#include "core/rect.hpp"
#include "core/environment.hpp"
#include "core/canvas.hpp"
#include "core/image.hpp"

#include "room.hpp"
#include "7keys.hpp"

ActionID Room::guardDeathID { "guardDeathID()" };

static int randint(int a, int b)
{
    int N = b - a + 1;
    int r = rand() % N;

    return a + r;
}

Room::Room(Object *parent, ObjectID id, string type, Room *left, Room *top,
           Room *right, Room *bottom, int s_id)
{
    assert((parent != NULL) && "parent can't be NULL");
    assert((not id.empty()) && "id can't be empty");
    assert((not type.empty()) && "id can't be empty");
    Object(parent, id);
    room_in_left = left;
    room_in_right = right;
    room_in_top = top;
    room_in_bottom = bottom;
    type = type;
    stage_id = s_id;
    m_doors = false;
    Environment *env = Environment::get_instance();
    quad = new Quadtree(0, new Rect(0, 0, env->canvas->width(), env->canvas->height()));

    fill_floor("tile");
    add_walls("parede");
    add_corners("canto");
    add_items(stage_id);
    add_guard("guard");
    add_ghost("ghost");

    if(room_in_left)
    {
        room_in_left->notify_creation("right");
        this->add_door("normal", 'l', 0, 320);
    }else{
        //do nothing
    }
    if(room_in_top)
    {
        room_in_top->notify_creation("bottom");
        this->add_door("normal",'t', 600, 0);
    }else{
        //do nothing
    }
    if(room_in_right)
    {
        room_in_right->notify_creation("left");
        this->add_door("normal",'r', 1200, 320);
    }else{
        //do nothing
    }
    if(room_in_bottom)
    {
        room_in_bottom->notify_creation("top");
        this->add_door("normal",'b', 600, 640);
    }else{
        //do nothing
    }

    if(type == "Final")
    {
        add_final_door();
    }else{
        //do nothing
    }

    add_observer(this);
}

Room::~Room()
{
}
/**
 * [Room::room_type returns the type of the room in which the player is]
 * @method Room::room_type
 * @return [returns "cell" if the player is in a cell or other]
 */
string Room::room_type()
{
	if (this->type == "CelaH" || this->type == "CelaV")
    {
		return "Cela";
    }else{
        //do nothing
    }
	return this->type;
}

//Add_items add the items in the room as the bench, bottles, chairs, etc.]
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
        int horizontal_position, vertical_position;
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

    int total_widtheight = 0;

    for (auto item : items)
    {
        total_widtheight += item.weight;
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
	}else{
        //do nothing
    }

    static const int MAX_ITENS = 15;
    int num_items = randint(0, MAX_ITENS);

    for (int i = 0; i < num_items and (not items.empty()); ++i)
    {
        int p = randint(1, total_widtheight);
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
        {
            sprintf(prepath,"res/items/");
        }else
        {
            sprintf(prepath,"res/tile_sheets/");
        }

        if(it->variations)
        {
            int variation = randint(1, it->variations);
            sprintf(path, "%s%s%d.png", prepath, it->name.c_str(), variation);
        }else
        {
            sprintf(path, "%s%s.png", prepath, it->name.c_str());
        }

        double horizontal_position = it->horizontal_position;
        double vertical_position = it->vertical_position;

        Item* item = new Item(this, it->name, path, horizontal_position,vertical_position, it->mass, it->walkable);

        if (place(item, horizontal_position, vertical_position))
            {add_child(item);
        }else
        {
            delete item;
        }
        if(it->unique)
        {
            total_widtheight -= it->weight;
            items.erase(it);
        }else{
            //do nothing
        }
    }
}

//Adds the previous state of the items the room when the player returns to her
void Room::add_list(Object  * item)
{
    assert((item != NULL) && "Item should be diferent of NULL");
	this->items.push_back(item);
}

/**
 * [Room::get_items Gets the state of the items the room when the player leaves]
 * @method Room::get_items
 * @return []
 */
const list<Object *>& Room::get_items()
{
	return children();
}


void Room::check_entry()
{
	Environment *env = Environment::get_instance();
	if(this->room_in_left)
	{
		Rect l_door {0, 340, 80, 80};
		env->canvas->draw(l_door, Color::WHITE);

	}else{
        //do nothing
    }
	if(this->room_in_top)
	{
		Rect t_door {600, 0, 80, 80};
		env->canvas->draw(t_door, Color::WHITE);

	}else{
        //do nothing
    }
	if(this->room_in_right)
	{
		Rect room_in_door {1200, 340, 80, 80};
		env->canvas->draw(room_in_door, Color::WHITE);

	}else{
        //do nothing
    }
	if(this->room_in_bottom)
	{
		Rect b_door {600, 640, 80, 80};
		env->canvas->draw(b_door, Color::WHITE);

	}else{
        //do nothing
    }
}

void
Room::draw_id(Room * anterior, Room * sala, int horizontal_position, int vertical_position)
{
    //assert((anterior != NULL) && "Room can't be NULL");
	Environment *env = Environment::get_instance();
	shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
	env->canvas->set_font(font);
	env->canvas->draw(sala->id(), horizontal_position, vertical_position, Color::RED);

	if(sala->room_in_left && sala->room_in_left != anterior)
	{
		env->canvas->draw("-", horizontal_position - 20,vertical_position,Color::RED);
		draw_id(sala, sala->room_in_left, horizontal_position - 100, vertical_position);
	}else{
        //do nothing
    }
	if(sala->room_in_top && sala->room_in_top != anterior)
	{
		env->canvas->draw("|", horizontal_position + 20, vertical_position - 30,Color::RED);
		draw_id(sala, sala->room_in_top, horizontal_position, vertical_position - 60);
	}else{
        //do nothing
    }
	if(sala->room_in_right && sala->room_in_right != anterior)
	{
		env->canvas->draw("-", horizontal_position + 80,vertical_position,Color::RED);
		draw_id(sala, sala->room_in_right, horizontal_position + 100, vertical_position);
	}else{
        //do nothing
    }
	if(sala->room_in_bottom && sala->room_in_bottom != anterior)
	{
		env->canvas->draw("|", horizontal_position + 20, vertical_position + 25,Color::RED);
		draw_id(sala, sala->room_in_bottom, horizontal_position, vertical_position + 60);
	}else{
        //do nothing
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
Room::add_door(string type, char direction, int horizontal_position, int vertical_position)
{
    assert((not type.empty()) && "type can't be empty");
    char doorID[128];
    char dooroom_in_sprite[256];
    int stages = 1;
    if(stage_id < 3)
    {
        stages = 1;
    }
    else if(stage_id < 4)
    {
        stages = 3;
    }
    else
    {
        stages = 4;
    }
    if(type == "normal")
    {
        sprintf(dooroom_in_sprite, "res/tile_sheets/porta%d%c.png", stages, direction);
        sprintf(doorID, "porta%c%s", direction, id().c_str());
        Item *porta = new Item(this, "door", dooroom_in_sprite, horizontal_position,vertical_position, INFINITE, true);

        add_child(porta);
    }
    else if (type == "finalDoor")
    {
        sprintf(doorID, "%s", SevenKeys::ScreenType::STAGE.c_str());
        sprintf(dooroom_in_sprite, "res/door/porta%c.png", direction);
        Item *porta = new Item(this, "finalDoor", dooroom_in_sprite, horizontal_position,vertical_position, INFINITE, true);

        add_child(porta);
    }else{
        //do nothing
    }

    const list<Object *> items = this->children();
    for (auto item : items)
    {
        char buffer[256];
        sprintf(buffer, "parede");
        if(strcmp(item->id().c_str(), buffer) == 0)
        {
            if((item->horizontal_position() > horizontal_position - item->width() && item->horizontal_position() < horizontal_position + item->width()) && item->vertical_position() == vertical_position)
            {
                item->set_walkable(true);
            }else{
                //do nothing
            }
        }else{
            //do nothing
        }
    }
}

void
Room::add_final_door()
{
    double horizontal_position = 0 + (room_in_top || room_in_bottom)*600 + (bool)room_in_left*1200;
    double vertical_position = 0 + (room_in_left || room_in_right)*320 + (bool)room_in_top*640;
    char dir;
    if(this->room_in_right)
    {
        dir = 'l';
    }
    else if(this->room_in_bottom)
    {
        dir = 't';
    }
    else if(this->room_in_left)
    {
        dir = 'r';
    }
    if(this->room_in_top)
    {
        dir = 'b';
    }else{
        //do nothing
    }

    add_door("finalDoor", dir, horizontal_position, vertical_position);
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
    {
        stages = 1;
    }
    else if(stage_id < 4)
    {
        stages = 3;
    }
    else
    {
        stages = 4;
    }

    sprintf(path, "res/tile_sheets/%s%d.png", name.c_str(), stages);

    Image *image = new Image(nullptr, name, path);

    if (not image)
    {
        return;
    }else{
        //do nothing
    }

    Environment *env = Environment::get_instance();
    Canvas *canvas = env->canvas;

    int width = canvas->width() / image->width();
    int height = canvas->height() / image->height();

    center_area.set_position(image->width(), image->height());
    center_area.set_dimensions(canvas->width() - 2*image->width(), canvas->height() - 2*image->height());

    for(int i = 1; i < width - 1; i++)
	{
		for(int j = 1; j < height - 1; j++)
		{
			Item *floor = new Item(this, name, path, i*image->width(), j*image->height(), INFINITE, true);
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
        {
            stages = 1;
        }
        else if(stage_id < 4)
        {
            stages = 3;
        }
        else
        {
            stages = 4;
        }

        sprintf(path, "res/tile_sheets/%s%d%c.png", name.c_str(), stages, pos[i]);

        Image *image = new Image(nullptr, name, path);

        if (not image)
        {
            cout << path << " nao existe" << endl;
            continue;
        }else{
            //do nothing
        }

        for(int j = 1; j < 15; j++)
        {

            for(int k = 1; k < 8; k++)
            {
                double horizontal_position = i % 2;
                if(i % 2 != 0){
                {
                    horizontal_position = image->width()*j;
                }
                }else
                {
                    horizontal_position = i/2 * (canvas->width() - image->width());
                }
                double vertical_position = i % 2;
                if(i % 2 != 0){
                {
                    vertical_position = i/2 * (canvas->height() - image->height());
                }
                }else
                {
                    vertical_position = image->height()*k;
                }

                Item *wall = new Item(this, name, path, horizontal_position,vertical_position, INFINITE, false);
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
        {
            sprintf(path, "res/tile_sheets/%s%d.png", name.c_str(), i + 1);
        }
        else
        {
            int stages = 1;
            if(stage_id < 3)
            {
                stages = 1;
            }
            else if(stage_id < 4)
            {
                stages = 3;
            }
            else
            {
                stages = 4;
            }
            sprintf(path, "res/tile_sheets/%s%d%d.png", name.c_str(),stages, i + 1);
        }

        Image *image = new Image(nullptr, name, path);

        if (not image)
        {
            continue;
        }

        double horizontal_position = 0;
        if(i % 3 != 0){
        {
            horizontal_position = canvas->width() - image->width();
        }
        }else{
             horizontal_position = 0;
        }
        double vertical_position = 0;
        if(i/2 != 0){
        {
            vertical_position = canvas->height() - image->height();
        }
        }else{
            vertical_position = 0;
        }
        delete image;

	    Item *corner = new Item(this, name, path, horizontal_position,vertical_position, INFINITE, false);
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
    {
        type = "easy";
    }
    if(random < 2)
    {
        type = "normal";
    }
    else
    {
        type = "hard";
    }

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
Room::place(Object *object, double horizontal_position, double vertical_position)
{
    assert((object != NULL) && "Object can't be NULL");
    int width = center_area.width();
    int height = center_area.height();

    int tries = 0;
    bool ok, randomize = horizontal_position < 0 and vertical_position < 0;

    do {
        ok = true;
        ++tries;

        if (randomize)
        {
            horizontal_position = (rand() % width) + center_area.horizontal_position();
            vertical_position = (rand() % height) + center_area.vertical_position();
        }

        if (horizontal_position + object->width() > width + center_area.horizontal_position())
        {
            horizontal_position = width + center_area.horizontal_position() - object->width();
        }

        if (vertical_position + object->height() > height + center_area.vertical_position())
        {
            vertical_position = height + center_area.vertical_position() - object->height();
        }

        for (auto obj : children())
        {
            if (obj->walkable())
            {
                continue;
            }

            Rect a { horizontal_position,vertical_position, object->width(), object->height() };
            Rect b = obj->bounding_box();
            Rect c = a.intersection(b);

            if (c.width() or c.height())
            {
                ok = false;
                break;
            }
        }

        if (tries > 10)
        {
            break;
        }

    } while (not ok and randomize);

    object->set_position(horizontal_position, vertical_position);

    return ok;
}

void Room::notify_creation(const string& position)
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
    }else{
        //do nothing
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
        {
            quad->insert(npc);
        }
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
                Guard * guard = (Guard*) npc2;

                if(npc->walkable() == false)
                {
                    if (c.width() > 5 and c.height() > 5)
                    {
                        if(guard->m_old_type == "hard")
                        {
                            if(abs(a.horizontal_position() - b.horizontal_position()) > abs(a.vertical_position() - b.vertical_position()))
                            {
                                if(a.horizontal_position() > b.horizontal_position())
                                {
                                    npc->set_horizontal_position(a.horizontal_position() - b.width() + 1);
                                }
                                else if(a.horizontal_position() < b.horizontal_position())
                                {
                                    npc->set_horizontal_position(a.horizontal_position() + a.width() - 1);
                                }else{
                                    //do nothing
                                }
                            }else
                            {
                                if(a.vertical_position() > b.vertical_position())
                                {
                                    npc->set_vertical_position(a.vertical_position() - b.height() + 1);
                                }
                                else if(a.vertical_position() < b.vertical_position())
                                {
                                    npc->set_vertical_position(a.vertical_position() + a.height() - 1);
                                }else{
                                    //do nothing
                                }
                            }
                        }
                        else
                        {
                            if(abs(a.horizontal_position() - b.horizontal_position()) > abs(a.vertical_position() - b.vertical_position()))
                            {
                                if(a.horizontal_position() < b.horizontal_position())
                                {
                                    npc2->set_horizontal_position(b.horizontal_position() - a.width() + 1);
                                }
                                else if(a.horizontal_position() > b.horizontal_position())
                                {
                                    npc2->set_horizontal_position(b.horizontal_position() + b.width() - 1);
                                }else{
                                    //do nothing
                                }
                            }
                            else
                            {
                                if(a.vertical_position() < b.vertical_position())
                                {
                                    npc2->set_vertical_position(b.vertical_position() - a.height() + 1);
                                }
                                else if(a.vertical_position() > b.vertical_position())
                                {
                                    npc2->set_vertical_position(b.vertical_position() + b.height() - 1);
                                }else{
                                    //do nothing
                                }
                            }
                        }
                    }else{
                        //do nothing
                    }
                }else{
                    //do nothing
                }
            }else{
                //do nothing
            }
        }


        if(npc->id() == "guard")
        {
            Guard * guard = (Guard*) npc;
            if (guard->health() < 1)
            {
                Ghost *ghost = new Ghost(this, "ghost", 0, 0, 9999, true, guard->m_old_type, randint(0,3));
                string path;
                if(guard->m_old_type != "hard")
                {
                    path = "res/sprites/death_guard1.png";
                }
                else
                {
                    path = "res/sprites/death_guard2.png";
                }
                Item *body = new Item(this, "body", path, 0, 0, 9999, true);
                place(body, npc->horizontal_position(), npc->vertical_position());
                remove_child(npc);
                add_child(body);
                place(ghost, npc->horizontal_position(), npc->vertical_position());
                add_child(ghost);

                notify(guardDeathID, "guard");
            }else{
                //do nothing
            }
        }else{
            //do nothing
        }
    }
}
