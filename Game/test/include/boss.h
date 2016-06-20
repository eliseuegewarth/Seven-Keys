#ifndef BOSS_H
#define BOSS_H

#include "room.hpp"

using namespace std;

/**
 * @brief [This class describes the attributes and behaviors of the enemy boss.]
 */
class Boss : public Object
{
public:
    
    //Defines the direction in which the boss can move around.
    typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;
    
    Boss(Object *parent, const ObjectID id, const double boss_horizontal_position, 
            const double boss_vertical_position, const int mass_of_boss, 
            const bool walkable, const int dir);
    ~Boss();

    Direction direction();
    void get_playerx(const unsigned int pos_x);
    void get_playery(const unsigned int pos_y);
    void set_direction(const Direction direction);
    void update_vision();
    void walk();
    void update_direction();

    void set_position(const double horizontal_position, const double vertical_position);

    bool summoned() {return this->summoned_state;}
    bool created() {return this->created_state;}

    void set_summoned(const bool is_summoned);
    void set_created(const bool is_created);

    double damage();

private:
    
    const double BOSS_MOVEMENT_SPEED = 1.3; // Define the boss walking speed.

    const double BOSS_DAMAGE = 0.9; // The boss attack damage value.
    
    int player_horizontal_position; // The player's horizontal position.

    int player_vertical_position;// The player's vertical position.


    bool summoned_state; // Indicates the summon state of the boss.

    bool created_state; // Indicates the creation state of the boss.

    void draw_self();

    void update_self(const unsigned long elapsed);

    // It is the animation of the boss that will be loaded on the screen.
    unique_ptr<Animation> boss_animation;

    Direction direction_of_movement;// The Boss movement direction.

    // Last game time saved since the start of the game. It's like an old Elapsed time. Is Not used.
    long last_game_time_saved = 0;
};


#endif