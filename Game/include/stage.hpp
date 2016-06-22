/**
 * stage.h
 * @brief [Class that implements the stages of the game.]
 * Licença: LGPL. Sem copyright.
 */

#ifndef STAGE_H
#define STAGE_H

#include <core/level.hpp>
#include <core/rect.hpp>

#include "map.hpp"
#include "room.hpp"

class Player;
class Map;

class Stage : public Level
{
public:
    Stage(ObjectID id, int lives, double * sanity);

    static ActionID colisionID;
    static ActionID summonBossID;

private:
    Player *m_player;
    Map *m_map;
    int m_num_id;
    void draw_self();
    void update_self(unsigned long);
    void threat_colision();
    void threat_colision_boss(list<Object*> map_objects);
    void threat_colision_not_walkable_objects(Object *item,
        Rect bounding_box_player, Rect bounding_box_item, Rect intersection);
    void threat_colision_walkable_objects(Object * item, Rect intersection);
    void threat_colision_guard(Object *item, Rect intersection);
    void threat_colision_ghost(Object *item, Rect intersection);
    double *m_sanity;

    bool on_message(Object *object, MessageID id, Parameters p);
};

#endif
