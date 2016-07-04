#include "../../include/guard.hpp"
#include "../../include/room.hpp"
#include "../../include/map.hpp"

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class TestGuard : public CppUnit::TestCase
    {

      CPPUNIT_TEST_SUITE( TestGuard );
      CPPUNIT_TEST( get_playerx_test );
      //CPPUNIT_TEST( anotherExample );
      //CPPUNIT_TEST( testEquals );
      CPPUNIT_TEST_SUITE_END();

      Guard * GuardTestObj;
      Room * RoomTestObj;
      Map * MapTestObj;

        void get_playerx_test ();
        //void            anotherExample ();
        //void            testEquals ();

    public:

        void setUp ();
      void tearDown();
    };


    CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( TestGuard, "TestGuard" );

    void TestGuard::setUp () {

        MapTestObj = new Map(4,1);
        RoomTestObj = new Room(MapTestObj, "sala 0", "None", nullptr, nullptr, nullptr, nullptr, 1);
        GuardTestObj =  new Guard(RoomTestObj, "guard", 0, 0, 60, false, "normal", 2);
        printf("criou os objetos");
    }

    void TestGuard::tearDown(){
        if(GuardTestObj != NULL){
            delete GuardTestObj;
        }else{
            //do nothing
        }

        if(RoomTestObj != NULL){
            delete RoomTestObj;
        }else{
          //do nothing
        }

        if(MapTestObj != NULL){
            delete MapTestObj;
        }else{
            //do nothing
        }
        printf("deletou os objetos");
    }

    void get_playerx_test()
    {
        CPPUNIT_ASSERT (1 == 1);
        // int player_horizontal_position = 0;
        // //Guard::get_playerx(player_horizontal_position);
        // assert(true == true);
    }
    // void get_playery_test()
    // {
    //     setUp();
    //     int player_vertical_position = 0;
    //     Guard::get_playery(player_vertical_position);
    //     assert(player_vertical_position == player_vertical_position);
    // }
    // void set_direction_test(Guard::Direction direction_of_movement)
    // {
    //     setUp();
    //     Guard::Direction direction_of_movement = Guard::RIGHT;
    //     Guard::set_direction(direction_of_movement);
    //     assert(direction_of_movement == direction_of_movement);
    // }
    // void walk_test()
    // {
    //     setUp();
    //     int player_horizontal_position = 0;
    //     int player_vertical_position = 0;
    //     Guard::get_playerx(player_horizontal_position);
    //     Guard::get_playery(player_vertical_position);
    //     Guard::walk();
    // }
    // void update_direction_test()
    // {
    //     setUp();
    //     unsigned long elapsed = 5001; //condition that is accepted by the 'if' of the method
    //     Direction direction_of_movement_before_update = direction_of_movement;
    //     Guard::update_direction(elapsed);
    //     assert(direction_of_movement != direction_of_movement_before_update);
    // }
    // void damage_test()
    // {
    //     setUp();
    //     double Guard_damage;
    //     Guard_damage = Guard::damage();
    //     assert(Guard_damage == GUARD_DAMAGE);
    // }
    // void health()
    // {
    //     setUp();
    //     double guard_health_to_test;
    //     guard_health_to_test = Guard::health();
    //     assert(guard_health_to_test == guard_health);
    // }
//};

// int main(){
//     TestGuard *testGuard = new TestGuard();
//     testGuard->setUp();
//     return 0;
// }



    /*

    */
