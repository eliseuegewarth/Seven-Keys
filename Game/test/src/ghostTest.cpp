#include "../include/ghost.hpp"

#include <cassert>

using namespace std;
//using namespace Ghost;

/*class GhostTest : public Ghost {
public:
    GhostTest(){

    }
    void get_playerx_test()
    {
        Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));
        int player_horizontal_position = 0;
        Ghost::get_playerx(player_horizontal_position);
        assert(this->player_horizontal_position == player_horizontal_position);
    }
    void get_playery_test()
    {
        Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));
        int player_vertical_position = 0;
        Ghost::get_playery(player_vertical_position);
        assert(this->player_vertical_position == player_vertical_position);
    }
    void set_direction_test(Direction direction_of_movement)
    {
        Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));
        Direction direction_of_movement = Ghost::RIGHT;
        Ghost::set_direction(direction_of_movement);
        assert(this->direction_of_movement == direction_of_movement);
    }
    void walk_test()
    {
        Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));
        int player_horizontal_position = 0;
        int player_vertical_position = 0;
        Ghost::get_playerx(player_horizontal_position);
        Ghost::get_playery(player_vertical_position);
        Ghost::walk();
    }
    void update_direction_test()
    {
        unsigned long elapsed = 5001; //condition that is accepted by the 'if' of the method
        Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));
        Direction direction_of_movement_before_update = this->direction_of_movement;
        Ghost::update_direction(elapsed);
        assert(this->direction_of_movement != direction_of_movement_before_update);
    }
    void damage_test()
    {
        Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));
        double ghost_damage;
        ghost_dagame = Ghost::damage();
        assert(ghost_dagame == this->GHOST_GUARD_DAMAGE);
    }
}
*/
