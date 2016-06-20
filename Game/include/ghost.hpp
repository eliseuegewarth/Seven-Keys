/**
 * ghost.hpp file
 */
#ifndef GHOST_H
#define GHOST_H

#include "core/sprite.hpp"
#include "room.hpp"

using namespace std;

class Ghost : public Object
{
public:

	typedef enum { NONE, IDLE, RUNNING } State;
    typedef enum { MOVED, STOPPED } Event;
    typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;

	#define GHOST_GUARD_SPEED_IN_MILISECONDS 60
	#define GHOST_GUARD_SPEED_IN_MILISECONDS_HARD 120

    Ghost(Object *parent, ObjectID id, const double x, const double y,
		 const unsigned int mass_of_ghost_guard,
		 const bool walkable, string type,
		 const unsigned int initial_movement_direction);
    ~Ghost();

    Direction direction();
    void get_playerx(const unsigned int player_horizontal_position);
    void get_playery(const unsigned int player_vertical_position);
    void set_direction(Direction direction_of_movement);
    void update_vision();
    void walk();
    void update_direction(unsigned long elapsed);
    void change_animation();

    double damage();

private:
    string type;
    int player_horizontal_position;
    int player_vertical_position;
    const double GHOST_GUARD_DAMAGE = 0.05;
	const double GHOST_GUARD_SPEED = 0.6;

    void draw_self();
    void update_self(unsigned long elapsed);
    unique_ptr<Animation> ghost_guard_animation;
    Direction direction_of_movement;
    unsigned long last_game_time_saved = 0;
};


#endif
