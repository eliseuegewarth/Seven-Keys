#include <core/environment.h>
#include <core/music.h>
#include <core/soundeffect.h>
#include <core/audiomanager.h>
#include <core/audiomanagerwrapper.h>

#include <cmath>

#include "guard.h"
#include "stage.h"
#include "item.h"
#include "map.h"
#include "player.h"

/**
 * stage.cpp
 * @brief [Class that implements the stages of the game.]
 * Licença: LGPL. Sem copyright.
 */

ActionID Stage::colisionID = "colisionID()";
ActionID Stage::summonBossID = "summonBossID()";

Stage::Stage(ObjectID id, int lives, double * sanity)
    : Level(id)
{
    // Temporary saves the number of the current stage
    char stage_number[10];

    // Temporary saves the id of the stage
    char stage_id[10];
    sprintf(stage_id, "%s", id.c_str());

    // Getting the Id of the stage by it's name
    for(int i = 0; stage_id[i] != '\0'; i++)
    {
        stage_number[i] = stage_id[i+5];
    }

    m_sanity = sanity;

    m_num_id = atoi(stage_number);

    // Calculate the total rooms of the current stage {Min: 3 / Max: - }
    int total_rooms = (3 + m_num_id + (m_num_id - 1) * 2) *(1 + (1 - *m_sanity/100)*0.55);

    cout << "Starting stage "<< m_num_id << ", " << total_rooms << " rooms created." << endl;

    // Instancing the current map
    m_map = new Map(total_rooms,m_num_id);
    add_child(m_map);
    m_map->add_observer(this);

    // Player's health {Min: 0.0 / Max: 100.0}
    double health = 100.0;

    // Instancing the player
    m_player = new Player(this, "player");
    m_player->set_strength(100.0);
    m_player->set_health(health);
    m_player->set_life(lives);
    m_player->set_sanity(*sanity);

    m_player->add_observer(this);
    m_player->set_key(false);
    m_player->set_position(600, 320);

    // The first stage has a special sound that has to be played
    if(m_num_id == 1)
    {
        Environment *env = Environment::get_instance();
        env->sfx->play("res/sounds/Alarme1.wav",1);
    }

    add_child(m_player);
    add_observer(m_player);
    add_observer(m_map);
}

void Stage::threat_colision_boss(list<Object*> map_objects)
{
    for( auto object : map_objects)
    {
        // Bounding box of player
        Rect bounding_box_player = m_player->bounding_box();

        // Bounding box of one of room's object
        Rect bounding_box_object = object->bounding_box();

        /* Intersection of the bounding boxes of player and room's
           object*/
        Rect intersection = bounding_box_player.intersection(bounding_box_object);

        if(object->id() == "boss")
        {
            Boss *boss = (Boss*) object;
            boss->get_playerx(m_player->x());
            boss->get_playery(m_player->y());

            // Withdraw player's life
            if (intersection.width() != 0 and intersection.height() != 0)
            {
                if(m_player->health() > 0)
                {
                    m_player->set_health(m_player->health() - boss->damage());
                    if(m_player->health() < 0)
                        m_player->set_health(0);
                }
            }
        }
    }
}

void Stage::update_self(unsigned long)
{

    // Receive the list of the objects of the current room
    const list<Object*> map_objects = m_map->children();

    threat_colision_boss(map_objects);

    // List of all items of the map
    const list<Object *> items = m_map->items();

    for (auto item : items)
    {
        Rect bounding_box_player = m_player->bounding_box();
        Rect bounding_box_item = item->bounding_box();
        Rect intersection = bounding_box_player.intersection(bounding_box_item);

        // Threating direct colisions
        if(item->walkable() == false)
        {
            if(item->id() == "paredet")
            {
                if (intersection.width() != 0 and intersection.height() > 50)
                {
                    char message[512];
                    sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(), item->id().c_str(), intersection.x(),
                        intersection.y(), intersection.width(), intersection.height());
                    notify(Stage::colisionID, message);

                    if(bounding_box_player.y() > bounding_box_item.y())
                    {
                        m_player->set_y(bounding_box_item.y() + bounding_box_item.height() - 50);
                    }
                }
            }
            else if (intersection.width() != 0 and intersection.height() != 0)
            {
                char message[512];
                sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(), item->id().c_str(), intersection.x(),
                    intersection.y(), intersection.width(), intersection.height());
                notify(Stage::colisionID, message);

                //eixo x
                if(abs(bounding_box_player.x() - bounding_box_item.x()) > abs(bounding_box_player.y() - bounding_box_item.y()))
                {
                    if(bounding_box_player.x() < bounding_box_item.x())
                    {
                        m_player->set_x(bounding_box_item.x() - bounding_box_player.width() + 1);
                    }
                    else if(bounding_box_player.x() > bounding_box_item.x())
                    {
                        m_player->set_x(bounding_box_item.x() + bounding_box_item.width() - 1);
                    }
                }
                else
                {
                    if(bounding_box_player.y() < bounding_box_item.y())
                    {
                        m_player->set_y(bounding_box_item.y() - bounding_box_player.height() + 1);
                    }
                    else if(bounding_box_player.y() > bounding_box_item.y())
                    {
                        m_player->set_y(bounding_box_item.y() + bounding_box_item.height() - 1);
                    }
                }
            }
        }
        else
        {
            if (intersection.width() != 0 and intersection.height() != 0)
            {
                char message[512];
                sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(), item->id().c_str(), intersection.x(),
                    intersection.y(), intersection.width(), intersection.height());

                notify(Stage::colisionID, message);

            }
            if(intersection.width() > 50 and intersection.height() > 50)
            {
                if(item->id() == "door")
                {
                    if(item->x() == 0 && item->y() == 320)
                    {
                        m_player->set_current("left", 1120, m_player->y());
                        m_map->m_boss->set_position(1120, m_player->y());
                    }
                    else if(item->x() == 1200 && item->y() == 320)
                    {
                        m_player->set_current("right", 80, m_player->y());
                        m_map->m_boss->set_position(80, m_player->y());
                    }
                    else if(item->x() == 600 && item->y() == 0)
                    {
                        m_player->set_current("top", m_player->x(), 560);
                        m_map->m_boss->set_position(m_player->x(), 560);
                    }
                    else if(item->x() == 600 && item->y() == 640)
                    {
                        m_player->set_current("bottom", m_player->x(), 80);
                        m_map->m_boss->set_position(m_player->x(), 80);
                    }
                }

            }
        }

        //Threating guard's vision
        if(item->id() == "guard")
        {
            // Instance of guard
            Guard *guard = (Guard*) item;
            const list<Object *> objects = item->children();
            Environment *env = Environment::get_instance();
            for (auto object : objects)
            {
                // Bounding box of the player
                Rect bounding_box_player2 = m_player->bounding_box();

                //Bounding box of one of the room's guards
                Rect bounding_box_guard = object->bounding_box();

                Rect intersection2 = bounding_box_player2.intersection(bounding_box_guard);

                if (intersection2.width() != 0 and intersection2.height() != 0)
                {
                    if(object->id() == "visao")
                    {
                        if(guard->type() != "follow")
                        {
                            env->sfx->play("res/sounds/alemaogritando.wav",1);
                            guard->m_old_type = guard->type();
                            guard->set_type("follow");
                        }
                        if ((intersection2.width() != 0 and intersection2.height() != 0) && (intersection.width() != 0 and intersection.height() != 0))
                            {
                                if(m_player->health() > 0)
                                {
                                    m_player->set_health(m_player->health() - guard->damage());
                                    if(m_player->health() < 0)
                                        m_player->set_health(0);
                                }
                            }
                    }
                }

            }

            if(guard->type() == "follow")
            {
                guard->get_playerx(m_player->x());
                guard->get_playery(m_player->y());
            }
        }
        else if(item->id() == "ghost")
        {
            Ghost *ghost = (Ghost*) item;
            ghost->get_playerx(m_player->x());
            ghost->get_playery(m_player->y());
            const list<Object *> objects = item->children();

            //retirar vida do player
            if (intersection.width() != 0 and intersection.height() != 0)
            {
                if(m_player->health() > 0)
                {
                    m_player->set_health(m_player->health() - ghost->damage());
                    if(m_player->health() < 0)
                        m_player->set_health(0);

                    m_player->set_sanity(m_player->sanity() - ghost->damage()/2);
                }
            }
        }
    }
}

void Stage::draw_self()
{
    // Instance the environment for a new stage
    Environment *env = Environment::get_instance();

    // Setting the screen background color of the game
    env->canvas->clear(Color::BLUE);
}

bool Stage::on_message(Object *, MessageID id, Parameters p)
{
    if (id == Player::hitExitDoorID)
    {
        *m_sanity = m_player->sanity();
        set_next(p);
        finish();
        return true;
    }
    if (id == Player::changeRoomID)
    {
        if(p == "left")
            m_map->set_current(m_map->current_room->room_in_left);
        else if(p == "top")
            m_map->set_current(m_map->current_room->room_in_top);
        else if(p == "right")
            m_map->set_current(m_map->current_room->room_in_right);
        else if(p == "bottom")
            m_map->set_current(m_map->current_room->room_in_bottom);

        return true;
    }
    else if(id == Player::jumpNextLevelID)
    {
        m_player->set_key(false);
        char new_stage[256];
        sprintf(new_stage, "trans%d", m_num_id+1);
        m_player->notify(Player::hitExitDoorID, new_stage);
        return true;
    }
    else if(id == Player::repeatLevelID)
    {
        m_player->set_key(false);
        char new_stage[256];
        cout << "Voce morreu, parca. Re";
        m_player->die();
        if(m_player->life() > 0)
        {
            sprintf(new_stage, "death%d", m_num_id);
            m_player->set_sanity(m_player->sanity()-20);
            *m_sanity = m_player->sanity();
        }
        else
            sprintf(new_stage, "gameover");
        m_player->notify(Player::hitExitDoorID, new_stage);
        return true;
    }
    else if(id == Player::takeItemID)
    {
        const list<Object *> items = m_map->items();
        for (auto item : items)
        {
            Rect bounding_box_player = m_player->bounding_box();
            Rect bounding_box_item = item->bounding_box();
            Rect intersection = bounding_box_player.intersection(bounding_box_item);

            // Threating direct colisions with items
            if(item->walkable() == true)
            {
                if (intersection.width() != 0 and intersection.height() != 0)
                {
                    if(strstr(item->id().c_str(), "key"))
                    {
                        cout << "Pegou a chave!" << endl;
                        m_map->remove_item(item);
                        m_player->get_key();

                        if(m_num_id >= 5)
                        {
                            m_map->m_boss->set_position(m_player->x(), m_player->y());
                            notify(Stage::summonBossID, "stage7");
                        }

                        return true;
                    }

                    if(strstr(item->id().c_str(), "Pill"))
                    {
                        m_player->get_pill(item->id());
                        m_map->remove_item(item);
                    }

                    if(item->id() == "Garrafa" || item->id() == "Faca" || item->id() == "Cacetete")
                    {
                        m_player->get_weapon(item->id());
                        m_map->remove_item(item);
                    }
                }
            }
        }
    }
    else if(id == Player::openDoorID)
    {
        const list<Object *> items = m_map->items();
        for (auto item : items)
        {
            Rect bounding_box_player = m_player->bounding_box();
            Rect bounding_box_item = item->bounding_box();
            Rect intersection = bounding_box_player.intersection(bounding_box_item);

            if(item->walkable() == true)
            {
                if(item->id() == "finalDoor")
                {
                    if (intersection.width() > 0 and intersection.height() > 0)
                    {
                        if(m_player->has_key() == true)
                        {
                            m_player->set_key(false);
                            finish();
                            char new_stage[256];
                            sprintf(new_stage, "trans%d", m_num_id+1);
                            m_player->notify(Player::hitExitDoorID, new_stage);
                            return true;
                        }
                    }
                }
            }
        }
    }
    else if(id == Player::pushItemID)
    {
        const list<Object *> items = m_map->items();
        for (auto item : items)
        {
            Rect bounding_box_player = m_player->bounding_box();
            Rect bounding_box_item = item->bounding_box();
            Rect intersection = bounding_box_player.intersection(bounding_box_item);

            if(item->walkable() == false)
            {
                if (intersection.width() != 0 and intersection.height() != 0)
                {
                    if(item->mass() <= m_player->strength())
                    {
                        if(abs(bounding_box_player.x() - bounding_box_item.x()) > abs(bounding_box_player.y() - bounding_box_item.y()))
                        {
                            if(bounding_box_player.x() < bounding_box_item.x())
                            {
                                item->set_x(bounding_box_item.x() + 1);
                            }
                            else if(bounding_box_player.x() > bounding_box_item.x())
                            {
                                item->set_x(bounding_box_item.x() - 1);
                            }
                        }
                        else
                        {
                            if(bounding_box_player.y() < bounding_box_item.y())
                            {
                                item->set_y(bounding_box_item.y() + 1);
                            }
                            else if(bounding_box_player.y() > bounding_box_item.y())
                            {
                                item->set_y(bounding_box_item.y() - 1);
                            }
                        }
                        return true;
                    }
                }
            }
        }
    }
    else if(id == Player::getHitID)
    {
        const list<Object *> npcs = m_map->current_room->children();
        const list<Object *> objects = m_player->children();
        for (auto npc : npcs)
        {
            for (auto object : objects)
            {
                Rect bounding_box_object = object->bounding_box();
                Rect bounding_box_npc = npc->bounding_box();
                Rect intersection = bounding_box_object.intersection(bounding_box_npc);

                if(npc->id() == "guard")
                {
                    if (intersection.width() != 0 and intersection.height() != 0)
                    {
                        if(object->id() == "visao")
                        {
                            double dmg = atof(p.c_str());
                            Guard * guard = (Guard*) npc;
                            guard->receive_dmg(dmg);
                            return true;
                        }

                    }
                }
            }
        }
    }
    else if(id == Room::guardDeathID)
    {
        cout << "entrou" << endl;
        m_player->set_sanity(m_player->sanity() - 30);
    }
    return false;
}
