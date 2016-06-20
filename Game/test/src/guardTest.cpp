#include "guard.hpp"

#include <cassert>

using namespace std;
//using namespace Guard;
/*
class GuardTest : public Guard {
public:
    GuardTest(){

    }
    void get_playerx_test()
    {
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        int player_horizontal_position = 0;
        Guard::get_playerx(player_horizontal_position);
        assert(this->player_horizontal_position == player_horizontal_position);
    }
    void get_playery_test()
    {
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        int player_vertical_position = 0;
        Guard::get_playery(player_vertical_position);
        assert(this->player_vertical_position == player_vertical_position);
    }
    void set_direction_test(Direction direction_of_movement)
    {
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        Direction direction_of_movement = Guard::RIGHT;
        Guard::set_direction(direction_of_movement);
        assert(this->direction_of_movement == direction_of_movement);
    }
    void walk_test()
    {
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        int player_horizontal_position = 0;
        int player_vertical_position = 0;
        Guard::get_playerx(player_horizontal_position);
        Guard::get_playery(player_vertical_position);
        Guard::walk();
    }
    void update_direction_test()
    {
        unsigned long elapsed = 5001; //condition that is accepted by the 'if' of the method
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        Direction direction_of_movement_before_update = this->direction_of_movement;
        Guard::update_direction(elapsed);
        assert(this->direction_of_movement != direction_of_movement_before_update);
    }
    void damage_test()
    {
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        double Guard_damage;
        Guard_damage = Guard::damage();
        assert(Guard_damage == this->GUARD_DAMAGE);
    }
    void health()
    {
        Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));
        double guard_health_to_test;
        guard_health_to_test = Guard::health();
        assert(guard_health_to_test == this->guard_health);
    }
}
*/
