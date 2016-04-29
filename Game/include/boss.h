#ifndef BOSS_H
#define BOSS_H

#include "room.h"

using namespace std;

/**
 * @brief [This class describes the attributes and behaviors of the enemy boss.]
 */
class Boss : public Object
{
public:
    
    //Defines the direction in which the boss can move around.
    typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;
    
    Boss(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, int dir);
    ~Boss();

    Direction direction();
    void get_playerx(int pos_x);
    void get_playery(int pos_y);
    void set_direction(Direction direction);
    void update_vision();
    void walk();
    void update_direction(unsigned long elapsed);

    void set_position(double x, double y);

    bool summoned() {return m_summoned;}
    bool created() {return m_created;}

    void set_summoned(bool t);
    void set_created(bool t);

    double damage();

private:

    // The player's horizontal position.
    int player_posx;

    // The player's vertical position.
    int player_posy;

    // The boss attack damage value.
    double m_damage;

    // Indicates the summon state of the boss.
    bool m_summoned;

    // Indicates the creation state of the boss.
    bool m_created;

    void draw_self();

    void update_self(unsigned long elapsed);

    // It is the animation of the boss that will be loaded on the screen.
    unique_ptr<Animation> m_animation;

    // The Boss movement direction.
    Direction m_direction;

    // Last game time saved since the start of the game. It's like an old Elapsed time. Is Not used.
    unsigned long m_last = 0;
};


#endif