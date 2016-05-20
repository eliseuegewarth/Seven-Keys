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

    if(m_num_id == 1)
    {
        Environment *env = Environment::get_instance();
        env->sfx->play("res/sounds/Alarme1.wav",1);
    }

    add_child(m_player);
    add_observer(m_player);
    add_observer(m_map);
}

void
Stage::update_self(unsigned long)
{

    const list<Object*> map_filhos = m_map->children();
    for( auto filho : map_filhos)
    {
        Rect a = m_player->bounding_box();
        Rect b = filho->bounding_box();
        Rect c = a.intersection(b);

        if(filho->id() == "boss")
        {
            Boss *boss = (Boss*) filho;
            boss->get_playerx(m_player->x());
            boss->get_playery(m_player->y());

            //retirar vida do player
            if (c.w() != 0 and c.h() != 0)
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


    const list<Object *> items = m_map->items();
    for (auto item : items)
    {
        Rect a = m_player->bounding_box();
        Rect b = item->bounding_box();
        Rect c = a.intersection(b);

        //tratando colisoes diretas
        if(item->walkable() == false)
        {
            if(item->id() == "paredet")
            {
                if (c.w() != 0 and c.h() > 50)
                {
                    char message[512];
                    sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(), item->id().c_str(), c.x(),
                        c.y(), c.w(), c.h());
                    notify(Stage::colisionID, message);

                    if(a.y() > b.y())
                    {
                        m_player->set_y(b.y() + b.h() - 50);
                    }
                }
            }
            else if (c.w() != 0 and c.h() != 0)
            {
                char message[512];
                sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(), item->id().c_str(), c.x(),
                    c.y(), c.w(), c.h());
                notify(Stage::colisionID, message);

                //eixo x
                if(abs(a.x() - b.x()) > abs(a.y() - b.y()))
                {
                    if(a.x() < b.x())
                    {
                        m_player->set_x(b.x() - a.w() + 1);
                    }
                    else if(a.x() > b.x())
                    {
                        m_player->set_x(b.x() + b.w() - 1);
                    }
                }
                else
                {
                    if(a.y() < b.y())
                    {
                        m_player->set_y(b.y() - a.h() + 1);
                    }
                    else if(a.y() > b.y())
                    {
                        m_player->set_y(b.y() + b.h() - 1);
                    }
                }
            }
        }
        else
        {

            if (c.w() != 0 and c.h() != 0)
            {
                char message[512];
                sprintf(message, "%s,%s,%.2f,%.2f,%.2f,%.2f", m_player->id().c_str(), item->id().c_str(), c.x(),
                    c.y(), c.w(), c.h());

                notify(Stage::colisionID, message);

            }
            if(c.w() > 50 and c.h() > 50)
            {
                if(item->id() == "door")
                {
                    if(item->x() == 0 && item->y() == 320)//m_map->current_room->r_left
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

        //Tratando visoes dos guardas
        if(item->id() == "guard")
        {
            Guard *guarda = (Guard*) item;
            const list<Object *> filhos = item->children();
            Environment *env = Environment::get_instance();
            for (auto filho : filhos)
            {
                Rect a2 = m_player->bounding_box();
                Rect b2 = filho->bounding_box();
                Rect c2 = a2.intersection(b2);

                if (c2.w() != 0 and c2.h() != 0)
                {
                    if(filho->id() == "visao")
                    {
                        if(guarda->type() != "follow")
                        {
                            env->sfx->play("res/sounds/alemaogritando.wav",1);
                            guarda->m_old_type = guarda->type();
                            guarda->set_type("follow");
                        }
                        if ((c2.w() != 0 and c2.h() != 0) && (c.w() != 0 and c.h() != 0))
                            {
                                if(m_player->health() > 0)
                                {
                                    m_player->set_health(m_player->health() - guarda->damage());
                                    if(m_player->health() < 0)
                                        m_player->set_health(0);
                                }
                            }
                    }
                }

            }

            if(guarda->type() == "follow")
            {
                guarda->get_playerx(m_player->x());
                guarda->get_playery(m_player->y());
            }
        }
        else if(item->id() == "ghost")
        {
            Ghost *ghost = (Ghost*) item;
            ghost->get_playerx(m_player->x());
            ghost->get_playery(m_player->y());
            const list<Object *> filhos = item->children();

            //retirar vida do player
            if (c.w() != 0 and c.h() != 0)
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

void
Stage::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::BLUE);
}

bool
Stage::on_message(Object *, MessageID id, Parameters p)
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
            m_map->set_current(m_map->current_room->r_left);
        else if(p == "top")
            m_map->set_current(m_map->current_room->r_top);
        else if(p == "right")
            m_map->set_current(m_map->current_room->r_right);
        else if(p == "bottom")
            m_map->set_current(m_map->current_room->r_bottom);

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
            Rect a = m_player->bounding_box();
            Rect b = item->bounding_box();
            Rect c = a.intersection(b);

            //tratando colisoes diretas
            if(item->walkable() == true)
            {
                if (c.w() != 0 and c.h() != 0)
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
            Rect a = m_player->bounding_box();
            Rect b = item->bounding_box();
            Rect c = a.intersection(b);

            if(item->walkable() == true)
            {
                if(item->id() == "finalDoor")
                {
                    if (c.w() > 0 and c.h() > 0)
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
            Rect a = m_player->bounding_box();
            Rect b = item->bounding_box();
            Rect c = a.intersection(b);

            if(item->walkable() == false)
            {
                if (c.w() != 0 and c.h() != 0)
                {
                    if(item->mass() <= m_player->strength())
                    {
                        if(abs(a.x() - b.x()) > abs(a.y() - b.y()))
                        {
                            if(a.x() < b.x())
                            {
                                item->set_x(b.x() + 1);
                                //m_player->set_x(b.x() - a.w());
                            }
                            else if(a.x() > b.x())
                            {
                                item->set_x(b.x() - 1);
                                //m_player->set_x(b.x() + b.w());
                            }
                        }
                        else
                        {
                            if(a.y() < b.y())
                            {
                                item->set_y(b.y() + 1);
                                //m_player->set_y(b.y() - a.h());
                            }
                            else if(a.y() > b.y())
                            {
                                item->set_y(b.y() - 1);
                                //m_player->set_y(b.y() + b.h());
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
        const list<Object *> filhos = m_player->children();
        for (auto npc : npcs)
        {
            for (auto filho : filhos)
            {
                Rect a = filho->bounding_box();
                Rect b = npc->bounding_box();
                Rect c = a.intersection(b);

                if(npc->id() == "guard")
                {
                    if (c.w() != 0 and c.h() != 0)
                    {
                        if(filho->id() == "visao")
                        {
                            double dmg = atof(p.c_str());
                            Guard * guarda = (Guard*) npc;
                            guarda->receive_dmg(dmg);
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
