/**
 * Boss.cpp file
 * Class that implements the boss enemie.
 */


#include "boss.hpp"

#include "core/level.hpp"
#include "core/environment.hpp"
#include "core/keyboardevent.hpp"

#include <core/animation.hpp>

#include <cassert>
#include <iostream>

using namespace std;

/**
 * @brief [Loads the information about the boss on the map.]
 *
 * @param parent [The parent is the map Object that will contains the boss.]
 * @param id [Identifier of object type. in case of this class, aways have to be "boss".]
 * @param boss_horizontal_position [The position in horizontal(horizontal_position) axis where boss will be placed. ]
 * @param boss_vertical_position [The position in vertival(vertical_position) axis where boss will be placed. ]
 * @param mass_of_boss [Contains Object Boss mass information.]
 * @param walkable [Defines whether the boss is an object able to walk.]
 * @param initial_movement_direction [Sets the initial movement direction.]
 */
Boss::Boss(Object *parent, const ObjectID id, const double boss_horizontal_position,
                const double boss_vertical_position, const int mass_of_boss, const bool walkable,
                const int initial_movement_direction)
{
    // Preconditions for execution of method.
    assert((parent != NULL) && "parent needs to be different from NULL");
    assert(not id.empty() && "id needs to be different empty string");
    assert((mass_of_boss > 0) && "mass_of_boss needs to be greater than zero");

    Object(parent, id, boss_horizontal_position, boss_vertical_position);

    this->boss_animation = (unique_ptr<Animation>) (new Animation(
                                    BOSS_RUNNING_SPRITE_PATH, 0, 0, 90, 90,
                                        6, 120, true));

    this->direction_of_movement = (Direction) initial_movement_direction;
    this->last_game_time_saved = INITIAL_TIME_ELAPSED_VALUE;
    this->set_mass(mass_of_boss);
    this->set_width(70);
    this->set_height(70);
    this->set_walkable(walkable);
    this->set_summoned(false);
    this->set_created(false);
    update_vision();
}

/**
 * @brief [Destructor of Boss class.]
 */
Boss::~Boss()
{
}

/**
 * @brief [Just returns informations of direction_of_movement.]
 * @return direction_of_movement [The Boss movement direction.]
 */
Boss::Direction
Boss::direction()
{
    return direction_of_movement;
}

/**
 * @brief [Does not implement any behavior.]
 */
void
Boss::update_vision()
{
}

/**
 * @brief [Modifies the movement direction.]
 *
 * @param direction_of_movement [The value of the direction that will be setted.]
 */
void
Boss::set_direction(const Direction direction_of_movement)
{
    this->direction_of_movement = direction_of_movement;
}

/**
 * @brief [Draws the animation of boss on screen.]
 */
void
Boss::draw_self()
{
    boss_animation->draw(horizontal_position(), vertical_position());
}

/**
 * @brief [Walk to the player's position at a constant speed.]
 */
void
Boss::walk()
{
    //Moves the boss on the horizontal axis towards the player.
    const bool player_is_to_the_right = (player_horizontal_position > this->horizontal_position());
    const bool player_is_to_the_left = (player_horizontal_position < this->horizontal_position());
    if(player_is_to_the_left){
        set_horizontal_position(horizontal_position() - BOSS_MOVEMENT_SPEED);
    }else if(player_is_to_the_right){
        set_horizontal_position(horizontal_position() + BOSS_MOVEMENT_SPEED);
    }else{
        set_horizontal_position(horizontal_position());
    }

    //Moves the boss on the vertical axis towards the player.
    const bool player_is_to_the_bottom = (player_vertical_position < this->vertical_position());
    const bool player_is_to_the_top = (player_vertical_position > this->vertical_position());
    if(player_is_to_the_bottom){
        set_vertical_position(vertical_position() - BOSS_MOVEMENT_SPEED);
    }else if(player_is_to_the_top){
        set_vertical_position(vertical_position() + BOSS_MOVEMENT_SPEED);
    }else{
        set_vertical_position(vertical_position());
    }

    //
    const bool player_is_aligned_vertically = (not player_is_to_the_right and
                                                                    not player_is_to_the_left);
    if(player_is_aligned_vertically and player_is_to_the_top){
        set_direction(Boss::UP);
    }else if(player_is_aligned_vertically and player_is_to_the_bottom){
        set_direction(Boss::DOWN);
    }else if(player_is_to_the_left){
        set_direction(Boss::LEFT);
    }else{
        set_direction(Boss::RIGHT);
    }
}

/**
 * @brief [Updates the sprite of object (boss) based on the boss movement direction.]
 *
 * @param elapsed [Elapsed time since the game start. This parameter is not used here.]
 */
void
Boss::update_direction()
{
    boss_animation->set_row(this->direction());
}

/**
 * @brief [Receive the player's horizontal position. This information is used at Boss's artificial intelligence.
 *
 * @param player_horizontal_position [That's the player's horizontal position.]
 */
void
Boss::get_player_horizontal_position(const unsigned int player_horizontal_position)
{
    this->player_horizontal_position = player_horizontal_position;
}

/**
 * @brief [Receive the player's vertical position. This information is used at Boss's artificial intelligence.
 *
 * @param player_vertical_position [That's the player's vertical position.]
 */
void
Boss::get_player_vertical_position(const unsigned int player_vertical_position)
{
    this->player_vertical_position = player_vertical_position;
}

/**
 * @brief [Returns the boss attack damage value.]
 * @return BOSS_DAMAGE [The boss attack damage value.]
 */
double
Boss::damage()
{
    return BOSS_DAMAGE;
}

//
/**
 * @brief [Updates the boss's position on the map and walk.]
 *
 * @param elapsed [Elapsed time since the game start.]
 */
void
Boss::update_self(const unsigned long elapsed)
{

    set_horizontal_position(this->horizontal_position());
    set_vertical_position(this->vertical_position());

    update_direction();
    boss_animation->update(elapsed);
    walk();
}

/**
 * @brief [This method defines the boss's position in the room.]\
 *
 * @param boss_horizontal_position [The boss horizontal position.]
 * @param boss_vertical_position [The boss vertical position.]
 */
void
Boss::set_position(const double boss_horizontal_position, const double boss_vertical_position)
{
    set_horizontal_position(boss_horizontal_position);
    set_vertical_position(boss_vertical_position);
}

/**
 * @brief [Set the summoned_state status with the 'is_summoned' boolean value.]
 *
 * @param is_summoned [Contain the summoned state boolean value.]
 */
void
Boss::set_summoned(const bool is_summoned)
{
    this->summoned_state = is_summoned;
}

/**
 * @brief [Set the created_state status with the 'is_created' boolean value]
 *
 * @param is_created [Contain the created state boolean value.]
 */
void
Boss::set_created(const bool is_created)
{
    this->created_state = is_created;
}
