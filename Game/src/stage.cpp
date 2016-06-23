#include "core/environment.hpp"
#include "core/music.hpp"
#include "core/soundeffect.hpp"
#include "core/audiomanager.hpp"
#include "core/audiomanagerwrapper.hpp"

#include <cmath>

#include "guard.hpp"
#include "stage.hpp"
#include "item.hpp"
#include "map.hpp"
#include "player.hpp"

/**
 * stage.cpp
 * @brief [Class that implements the stages of the game.]
 * Licença: LGPL. Sem copyright.
 */

using namespace std;

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
    printf("m_num_id=%d\n", m_num_id);
    // Calculate the total rooms of the current stage {Min: 3 / Max: - }
    int total_rooms = (3 + m_num_id + (m_num_id - 1) * 2) *(1 + (1 - *m_sanity/100)*0.55);
    printf("total_rooms=%d", total_rooms);
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
            boss->get_player_horizontal_position(m_player->horizontal_position());
            boss->get_player_vertical_position(m_player->vertical_position());

            // Withdraw player's life
            if (intersection.width() != 0 and intersection.height() != 0)
            {
                if(m_player->health() > 0)
                {
                    m_player->set_health(m_player->health() - boss->damage());
                    if(m_player->health() < 0)
                        m_player->set_health(0);
                }
                else
                {
                  // Do nothing
                }
            }
            else
            {
              // Do nothing
            }
        }
        else
        {
          // Do nothing
        }
    }
}

void Stage::threat_colision_not_walkable_objects(Object * item,
    Rect bounding_box_player, Rect bounding_box_item, Rect intersection)
{
    if(item->id() == "paredet")
    {
        if (intersection.width() != 0 and intersection.height() > 50)
        {
            char message[512];
            sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f",
                m_player->id().c_str(), item->id().c_str(), intersection.horizontal_position(),
                intersection.vertical_position(), intersection.width(), intersection.height());

            notify(Stage::colisionID, message);

            if(bounding_box_player.vertical_position() > bounding_box_item.vertical_position())
            {
                m_player->set_vertical_position(bounding_box_item.vertical_position() +
                bounding_box_item.height() - 50);
            }
            else
            {
              // Do nothing
            }
        }
        else
        {
          // Do nothing
        }
    }
    else if (intersection.width() != 0 and intersection.height() != 0)
    {
        char message[512];
        sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(),
            item->id().c_str(), intersection.horizontal_position(), intersection.vertical_position(),
            intersection.width(), intersection.height());

        notify(Stage::colisionID, message);

        //horizontal axis
        if(abs(bounding_box_player.horizontal_position() - bounding_box_item.horizontal_position()) >
            abs(bounding_box_player.vertical_position() - bounding_box_item.vertical_position()))
        {
            if(bounding_box_player.horizontal_position() < bounding_box_item.horizontal_position())
            {
                m_player->set_horizontal_position(bounding_box_item.horizontal_position() - bounding_box_player.width() + 1);
            }
            else if(bounding_box_player.horizontal_position() > bounding_box_item.horizontal_position())
            {
                m_player->set_horizontal_position(bounding_box_item.horizontal_position() + bounding_box_item.width() - 1);
            }
            else
            {
              // Do nothing
            }
        }
        else
        {
            if(bounding_box_player.vertical_position() < bounding_box_item.vertical_position())
            {
                m_player->set_vertical_position(bounding_box_item.vertical_position() - bounding_box_player.height() + 1);
            }
            else if(bounding_box_player.vertical_position() > bounding_box_item.vertical_position())
            {
                m_player->set_vertical_position(bounding_box_item.vertical_position() + bounding_box_item.height() - 1);
            }
            else
            {
              // Do nothing
            }
        }
    }
    else
    {
      // Do nothing
    }
}

void Stage::threat_colision_walkable_objects(Object * item, Rect intersection)
{
    if (intersection.width() != 0 and intersection.height() != 0)
    {
        char message[512];
        sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(), item->id().c_str(), intersection.horizontal_position(),
            intersection.vertical_position(), intersection.width(), intersection.height());

        notify(Stage::colisionID, message);

    }
    if(intersection.width() > 50 and intersection.height() > 50)
    {
        if(item->id() == "door")
        {
            if(item->horizontal_position() == 0 && item->vertical_position() == 320)
            {
                m_player->set_current("left", 1120, m_player->vertical_position());
                m_map->m_boss->set_position(1120, m_player->vertical_position());
            }
            else if(item->horizontal_position() == 1200 && item->vertical_position() == 320)
            {
                m_player->set_current("right", 80, m_player->vertical_position());
                m_map->m_boss->set_position(80, m_player->vertical_position());
            }
            else if(item->horizontal_position() == 600 && item->vertical_position() == 0)
            {
                m_player->set_current("top", m_player->horizontal_position(), 560);
                m_map->m_boss->set_position(m_player->horizontal_position(), 560);
            }
            else if(item->horizontal_position() == 600 && item->vertical_position() == 640)
            {
                m_player->set_current("bottom", m_player->horizontal_position(), 80);
                m_map->m_boss->set_position(m_player->horizontal_position(), 80);
            }
            else
            {
              // Do nothing
            }
        }
        else
        {
          // Do nothing
        }

    }
    else
    {
      // Do nothing
    }
}

void Stage::threat_colision_guard(Object *item, Rect intersection)
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
                        {
                            m_player->set_health(0);
                        }
                        else
                        {
                          // Do nothing
                        }

                    }
                    else
                    {
                      // Do nothing
                    }
                }
                else
                {
                  // Do nothing
                }
            }
            else
            {
              // Do nothing
            }
        }
        else
        {
          // Do nothing
        }

    }

    if(guard->type() == "follow")
    {
        guard->get_player_horizontal_position(m_player->horizontal_position());
        guard->get_player_vertical_position(m_player->vertical_position());
    }
    else
    {
      // Do nothing
    }
}

void Stage::threat_colision_ghost(Object *item, Rect intersection)
{
    Ghost *ghost = (Ghost*) item;
    ghost->get_player_horizontal_position(m_player->horizontal_position());
    ghost->get_player_vertical_position(m_player->vertical_position());
    const list<Object *> objects = item->children();

    //Withdraw player's life
    if (intersection.width() != 0 and intersection.height() != 0)
    {
        if(m_player->health() > 0)
        {
            m_player->set_health(m_player->health() - ghost->damage());
            if(m_player->health() < 0)
                m_player->set_health(0);
            else
              // Do nothing

            m_player->set_sanity(m_player->sanity() - ghost->damage()/2);
        }
        else
        {
          // Do nothing
        }
    }
    else
    {
      // Do nothing
    }
}

void Stage::threat_colision()
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

          if(item->walkable() == false)
          {
              threat_colision_not_walkable_objects(item, bounding_box_player,
                bounding_box_item, intersection);
          }
          else
          {
              threat_colision_walkable_objects(item, intersection);
          }

          if(item->id() == "guard")
          {
              threat_colision_guard(item, intersection);
          }
          else if(item->id() == "ghost")
          {
              threat_colision_ghost(item, intersection);
          }
          else
          {
              // Do nothing
          }
      }
}

void Stage::update_self(unsigned long)
{
    threat_colision();
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
        else
            // Do nothing

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
                            m_map->m_boss->set_position(m_player->horizontal_position(), m_player->vertical_position());
                            notify(Stage::summonBossID, "stage7");
                        }
                        else
                        {
                          // Do nothing
                        }

                        return true;
                    }
                    else
                    {
                      // Do nothing
                    }

                    if(strstr(item->id().c_str(), "Pill"))
                    {
                        m_player->get_pill(item->id());
                        m_map->remove_item(item);
                    }
                    else
                    {
                      // Do nothing
                    }

                    if(item->id() == "Garrafa" || item->id() == "Faca" || item->id() == "Cacetete")
                    {
                        m_player->get_weapon(item->id());
                        m_map->remove_item(item);
                    }
                    else
                    {
                      // Do nothing
                    }
                }
                else
                {
                  // Do nothing
                }
            }
            else
            {
              // Do nothing
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
                        else
                        {
                          // Do nothing
                        }
                    }
                    else
                    {
                      // Do nothing
                    }
                }
                else
                {
                  // Do nothing
                }
            }
            else
            {
              // Do nothing
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
                        if(abs(bounding_box_player.horizontal_position() - bounding_box_item.horizontal_position()) > abs(bounding_box_player.vertical_position() - bounding_box_item.vertical_position()))
                        {
                            if(bounding_box_player.horizontal_position() < bounding_box_item.horizontal_position())
                            {
                                item->set_horizontal_position(bounding_box_item.horizontal_position() + 1);
                            }
                            else if(bounding_box_player.horizontal_position() > bounding_box_item.horizontal_position())
                            {
                                item->set_horizontal_position(bounding_box_item.horizontal_position() - 1);
                            }
                            else
                            {
                              // Do nothing
                            }
                        }
                        else
                        {
                            if(bounding_box_player.vertical_position() < bounding_box_item.vertical_position())
                            {
                                item->set_vertical_position(bounding_box_item.vertical_position() + 1);
                            }
                            else if(bounding_box_player.vertical_position() > bounding_box_item.vertical_position())
                            {
                                item->set_vertical_position(bounding_box_item.vertical_position() - 1);
                            }
                            else
                            {
                              // Do nothing
                            }
                        }
                        return true;
                    }
                    else
                    {
                      // Do nothing
                    }
                }
                else
                {
                  // Do nothing
                }
            }
            else
            {
              // Do nothing
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
                        else
                        {
                          // Do nothing
                        }
                    }
                    else
                    {
                      // Do nothing
                    }
                }
                else
                {
                  // Do nothing
                }
            }
        }
    }
    else if(id == Room::guardDeathID)
    {
        cout << "entrou" << endl;
        m_player->set_sanity(m_player->sanity() - 30);
    }
    else
    {
      // Do nothing
    }
    return false;
}
