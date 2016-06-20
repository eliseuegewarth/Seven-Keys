#include <list>
#include <utility>
#include <ijengine/core/environment.h>
#include <ijengine/core/rect.h>
#include <map>

#include <cassert>
#include "map.hpp"


using namespace std;

Map::Map(int qnt_salas, int stage_id) : current_room(nullptr), m_boss(NULL)
{
	GenerateMap(qnt_salas, stage_id);

    Boss *boss = new Boss(this, "boss", 0, 0, 999, true, Boss::LEFT);
    assert((boss != NULL) && "");
    m_boss = boss;


}
// Room Criation
void Map::CreateRoom(Room *room, int *id,int x, int y, int qnt, int stage_id)
{
	int randomVar;
    int randomType = rand() % 3;
    string type;

	randomVar = rand() % 100+1;

    if(randomVar <= 25)
    {
        randomVar = LEFT;
    }

    if(randomVar > 25 && randomVar <= 50)
    {
        randomVar = RIGHT;
    }

    if(randomVar > 50 && randomVar <= 75)
    {
        randomVar = TOP;
    }

    if(randomVar > 75 && randomVar <= 100)
    {
        randomVar = BOTTOM;
    }

    char sala[256];
    sprintf(sala, "sala %d", *id);

    if(randomType < 2)
        type = "None";
    else if (randomType < 3)
        type = "Cela";
    if(*id == (int)(qnt*0.5))
        type = "KeyRoom";
    if(*id == (int)(qnt*0.9))
        type = "Final";



    if(room->type == "Final")
    {
        *id-=1;
        return;
    }

	switch(randomVar)
	{
		case LEFT:
			if(room->room_in_left != nullptr)
				CreateRoom(room->room_in_left, id, x-1, y, qnt, stage_id);
			else if(x-1 >= 0 && matriz[x-1][y] == false && (room->room_type() != "Cela" || (room->room_type() == "Cela" && room->room_in_right)))
            {
                if(type == "Cela")
                    type += 'H';

            	room->Room::room_in_left = new Room(this, sala, type, nullptr, nullptr, room, nullptr, stage_id);
                room_list.push_back(room->room_in_left);
                room->room_in_left->pos_x = x-1;
                room->room_in_left->pos_y = y;
                matriz[x-1][y] = true;
            }
            else
            {
                *id-=1;
                return;
            }
			break;

		case RIGHT:
			if(room->room_in_right != nullptr)
				CreateRoom(room->room_in_right, id, x+1, y, qnt, stage_id);
			else if(x+1 < qnt && matriz[x+1][y] == false && (room->room_type() != "Cela" || (room->room_type() == "Cela" && room->room_in_left)))
            {
                if(type == "Cela")
                    type += 'H';

            	room->room_in_right = new Room(this, sala, type, room, nullptr, nullptr, nullptr, stage_id);
                room_list.push_back(room->room_in_right);
                room->room_in_right->pos_x = x+1;
                room->room_in_right->pos_y = y;
                matriz[x+1][y] = true;
            }
            else
            {
                *id-=1;
                return;
            }
			break;

		case TOP:
			if(room->room_in_top != nullptr)
				CreateRoom(room->room_in_top, id, x, y-1, qnt, stage_id);
			else if(y-1 >= 0 && matriz[x][y-1] == false && (room->room_type() != "Cela" || (room->room_type() == "Cela" && room->room_in_bottom)))
            {
                if(type == "Cela")
                    type += 'V';

				room->room_in_top = new Room(this, sala, type, nullptr, nullptr, nullptr, room, stage_id);
                room_list.push_back(room->room_in_top);
                room->room_in_top->pos_x = x;
                room->room_in_top->pos_y = y-1;
                matriz[x][y-1] = true;
            }
            else
            {
                *id-=1;
                return;
            }
			break;

		case BOTTOM:
			if(room->room_in_bottom != nullptr)
				CreateRoom(room->room_in_bottom, id, x, y+1, qnt, stage_id);
			else if(y+1 < qnt && matriz[x][y+1] == false && (room->room_type() != "Cela" || (room->room_type() == "Cela" && room->room_in_top)))
            {
                if(type == "Cela")
                    type += 'V';

				room->room_in_bottom = new Room(this, sala, type, nullptr, room, nullptr, nullptr, stage_id);
                room_list.push_back(room->room_in_bottom);
                room->room_in_bottom->pos_x = x;
                room->room_in_bottom->pos_y = y+1;
                matriz[x][y+1] = true;
            }
            else
            {
                *id-=1;
                return;
            }
			break;
	}
}

// Generate all the map
void Map::GenerateMap(int quantidade_salas, int stage_id)
{

    int x = quantidade_salas/2;
    int y = quantidade_salas/2;
    int id = 1;

    matriz = (bool**) malloc(sizeof(bool*)*(quantidade_salas));

    for(int i = 0; i < quantidade_salas; i++)
    {
    	matriz[i] = (bool*) malloc(sizeof(bool)*(quantidade_salas));
        for(int j = 0; j < quantidade_salas; j++)
	        {
            matriz[i][j] = false;
        }
    }

	Room *room = new Room(this, "sala 0", "None", nullptr, nullptr, nullptr, nullptr, stage_id);
    assert((room != NULL) && "Failed to pick up the instance of environment");
    room_list.push_back(room);
    set_current(room);
    last_room = room;

	matriz[x][y] = true;

    Room * aux = room_list.at(rand() % id);
    aux->pos_x = x;
    aux->pos_y = y;

	for(int id = 1; id < quantidade_salas; id++)
	{
        Room * aux = room_list.at(rand() % id);
		CreateRoom(aux, &id, aux->pos_x, aux->pos_y, quantidade_salas, stage_id);
        aux ++;
	}
    for(int i=quantidade_salas-1; i>=0; i--)
    {
        free (matriz[i]);
    }
    free(matriz);
}

void Map::remove_item(Object *item)
{
    assert((item != NULL) && "Failed to pick up the instance of environment the room");
    current_room->remove_item(item);
}

Room * Map::room()
{
	return current_room;
}

void Map::set_current(Room *nova)
{
    if(current_room != NULL)
    {
        remove_observer(current_room);
        remove_child(current_room);
        current_room->remove_observer(this);
    }

	current_room = nova;
    add_child(current_room);
    add_observer(current_room);
    current_room->add_observer(this);

    if(m_boss != NULL)
    {

        remove_child(m_boss);
        m_boss->set_summoned(false);
        last_summon = -1;
    }
}

const list<Object *>& Map::items()
{
    return current_room->get_items();
}

bool Map::on_message(Object *, MessageID id, Parameters p)
{
    assert((not id.empty()) && "id needs to be different drom the empty");

    if(id == Room::guardDeathID)
    {
        notify(id,p);
        return true;
    }
    if(id == Stage::summonBossID)
    {
        if(m_boss != NULL)
        {
            m_boss->set_created(true);
            Environment *env = Environment::get_instance();
            assert((env != NULL) && "Failed to pick up the instance of environment");
            env->sfx->play("res/sounds/esposagritando.wav", 1);
        }
    }

    return false;
}

// void Map::draw_self()
// {
//     if (current_room)
//         current_room->draw();
// }

void Map::update_self(unsigned long elapsed)
{
    if(m_boss->created())
    {
        if(last_summon == -1)
            last_summon = elapsed;

        if((elapsed - last_summon > 1000) && m_boss->summoned() == false )
        {
            add_child(m_boss);
            m_boss->set_summoned(true);
        }
    }

}
