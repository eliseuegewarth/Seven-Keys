/**
 * guard.hpp file.
 */
#ifndef GUARD_H
#define GUARD_H

#include "core/sprite.hpp"
#include "room.hpp"
#include "sight.hpp"

using namespace std;

/**
 * @brief [brief description]
 * @details [long description]
 *
 */
class Guard : public Object
{
public:

    typedef enum { NONE, IDLE, RUNNING } State;
    typedef enum { MOVED, STOPPED } Event;
    typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;

    #define GUARD_SPEED_IN_MILISECONDS 120

    Guard(Object *parent, ObjectID id, const double horizontal_position, const double vertical_position,
          const unsigned int mass_of_guard, const bool walkable, string type, const unsigned int initial_movement_direction);
    ~Guard();

    static ActionID removeGuardID;
    static ActionID walkID;


    Direction direction();
    void get_player_horizontal_position(const unsigned int horizontal_position);
    void get_player_vertical_position(const unsigned int vertical_position);
    void set_direction(Direction direction_of_movement);
    void update_vision();
    void walk(unsigned long elapsed);
    void update_direction(unsigned long elapsed);
    void change_animation(string path);

    string type();
    string old_type();
    void set_type(string t);
    void set_old_type(string t);

    double health();
    double damage();
    void receive_dmg(double dmg);
    string m_old_type;

private:
    string guard_type;

    int player_horizontal_position;
    int player_vertical_position;
    const double GUARD_DAMAGE = 0.7;
    double guard_health;
    const double GUARD_SPEED = 1;


    void draw_self();
    void update_self(unsigned long elapsed);
    unique_ptr<Animation> guard_animation;
    Direction direction_of_movement;
    unsigned long last_game_time_saved;
};


#endif
