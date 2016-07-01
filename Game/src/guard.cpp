/**
 * guard.cpp
 * This class describes the attributes and behaviors of the guard enemie.
 * Licença: LGPL. Sem copyright.
 */

#include "guard.hpp"

#include "core/level.hpp"
#include "core/environment.hpp"
#include "core/keyboardevent.hpp"

#include <cassert>
#include <iostream>

ActionID Guard::removeGuardID { "removeGuardID()" };
ActionID Guard::walkID { "walkID()" };

using namespace std;

const string& GUARD_RUNNING_PATH = "res/sprites/guard1_running.png";
const string& GUARD_3_RUNNING_PATH = "res/sprites/guard3_running.png";

 /**
  * [Guard::Guard Loads the guard information in the game]
  * @param  parent                           [The parent is the map object that
  *                                          will contains the guard.]
  * @param  id                               [identifier of object]
  * @param  guard_horizontal_position        [Guard position on the map in the axis x]
  * @param  guard_vertical_position          [Guard position on the map in the axis y]
  * @param  mass_of_guard                    [Contains mass information of the guard object]
  * @param  walkable                         [Defines if the ghost guard is an object able to walk]
  * @param  t                                [description]
  * @param  initial_movement_direction       [Defines the initial direction of moviment]
  */
Guard::Guard(Object *parent, ObjectID id, const double guard_horizontal_position,
            const double guard_vertical_position,
            const unsigned int mass_of_guard,
            const bool walkable, string t,
            const unsigned int initial_movement_direction)
            : Object (parent, id, guard_horizontal_position,
                    guard_vertical_position)
{
    //preconditions for execution of method.
    assert((parent != NULL) && "Parent needs to be different from NULL");
    assert((not id.empty()) && "id needs to be different drom the empty");
    assert((mass_of_guard > 0) && "mass of guard needs to greater than zero");

    guard_type = t;
    guard_health = 100;
    guard_animation  = (unique_ptr<Animation>)new Animation
    (GUARD_RUNNING_PATH, 0, 0, 70, 70, 8, GUARD_SPEED_IN_MILISECONDS, true);
    direction_of_movement = (Direction) initial_movement_direction;
    last_game_time_saved = 0;

    this->set_mass(mass_of_guard);
    set_width(70);
    set_height(70);
    this->set_walkable(walkable);
    this->set_old_type(t);
    update_vision();

    if(guard_type == "hard")
    {
        change_animation(GUARD_3_RUNNING_PATH);
    }else
    {
        //do nothing
    }
}

Guard::~Guard()
{
}

/**
 * [Guard::direction Just returns informations of m_direction.]
 * @method Guard::direction
 * @return [returns the direction of guard movement]
 */
Guard::Direction Guard::direction()
{
    return direction_of_movement;
}

/**
 * [Guard::update_vision updated sprite guard depending on your direction]
 * @method Guard::update_vision
 */
void Guard::update_vision()
{
    const list<Object *> filhos = this->children();

    for (auto filho : filhos)
    {
        if(filho->id() == "visao")
        {
            remove_child(filho);
        }else
        {
            //do nothing
        }
    }

    if(direction() == Guard::RIGHT)
    {
        Sight *visao = new Sight(this, "visao", this->horizontal_position()+40, this->vertical_position(), 200, 80);
        add_child(visao);
    }
    else if(direction() == Guard::LEFT)
    {
        Sight *visao = new Sight(this, "visao", this->horizontal_position() - 200, this->vertical_position(), 240, 80);
        add_child(visao);
    }
    else if(direction() == Guard::UP)
    {
        Sight *visao = new Sight(this, "visao", this->horizontal_position(), this->vertical_position() - 200, 80, 240);
        add_child(visao);
    }
    else if(direction() == Guard::DOWN)
    {
        Sight *visao = new Sight(this, "visao", this->horizontal_position(), this->vertical_position() + 40, 80, 200);
        add_child(visao);
    }else{
        //do nothing
    }

}

/**
 * [Guard::set_direction Modifies the movement direction]
 * @method Guard::set_direction
 * @param  direction_of_movement [The value of the direction that will be setted.]
 */
void Guard::set_direction(Direction direction_of_moviment)
{
    direction_of_movement = direction_of_moviment;
}

/**
 * [Ghost::draw_self Draws the animation of guard on screen.]
 * @method Guard::draw_self
 */
void Guard::draw_self()
{
    guard_animation->draw(horizontal_position(), vertical_position());
}

/**
 * [Guard::walk Walk to the player's position at a constant speed.]
 * @method Guard::walk
 */
void Guard::walk(unsigned long elapsed)
{
    if(guard_type == "easy")
    {
        return;
    }
    else if(guard_type == "normal" || guard_type == "hard")
    {
       const Environment *env = Environment::get_instance();


        if(elapsed - last_game_time_saved > 3000)
        {
            if(direction() == Guard::RIGHT || direction() == Guard::LEFT)
            {
                set_horizontal_position(horizontal_position() - GUARD_SPEED + (GUARD_SPEED * direction()));
                if(horizontal_position() < 0 + 80)
                {
                    set_horizontal_position(80);
                }
                else if(horizontal_position() > env->canvas->width() - this->width() - 80)
                {
                    set_horizontal_position(env->canvas->width() - this->width() - 80);
                }else{
                    //do nothing
                }
            }
            if(direction() == Guard::UP || direction() == Guard::DOWN)
            {
                set_vertical_position(vertical_position() - 2 * GUARD_SPEED + (GUARD_SPEED * direction()));
                if(vertical_position() < 0 + 80)
                {
                    set_vertical_position(80);
                }
                else if(vertical_position() > env->canvas->height() - this->height() - 80)
                {
                    set_vertical_position(env->canvas->height() - this->height() - 80);
                }else{
                    //do nothing
                }
            }else{
                //do nothing
            }
        }else{
            //do nothing
        }
    }
    else if(guard_type == "follow")
    {
        const bool player_is_to_the_right = (player_horizontal_position
                                            > this->horizontal_position() + 70);
        const bool player_is_to_the_left = (player_horizontal_position
                                            < this->horizontal_position() - 70);
        if(player_is_to_the_left)
        {
            set_horizontal_position(horizontal_position() - GUARD_SPEED);
        }
        else if(player_is_to_the_right)
        {
            set_horizontal_position(horizontal_position() + GUARD_SPEED);
        }else{
            //do nothing
        }

        const bool player_is_to_the_buttom = (player_vertical_position
                                             < this->vertical_position() - 70);
        const bool player_is_to_the_top = (player_vertical_position
                                          > this->vertical_position() + 70);
        if(player_is_to_the_buttom)
        {
            set_vertical_position(vertical_position() - GUARD_SPEED);
        }
        else if(player_is_to_the_top)
        {
            set_vertical_position(vertical_position() + GUARD_SPEED);
        }else{
            //do nothing
        }

        /*

         */
        const bool player_is_to_the_right_to_walk = (player_horizontal_position
                                                    > this->horizontal_position() - 100);
        const bool player_is_to_the_left_to_walk = (player_horizontal_position
                                                    < this->horizontal_position() + 100);
        const bool player_is_aligned_vertically = (player_is_to_the_right_to_walk
                                                  and player_is_to_the_left_to_walk);
        const bool player_is_to_the_left_to_set_direction = (player_horizontal_position
         < this->horizontal_position());
        const bool player_is_to_the_right_to_set_direction = (player_horizontal_position
         > this->horizontal_position());
        const bool player_is_to_the_buttom_to_walk = (player_vertical_position
         > this->vertical_position());
        const bool player_is_to_the_top_to_walk = (player_vertical_position
                                                  < this->vertical_position());

        if (player_is_aligned_vertically and player_is_to_the_top_to_walk)
        {
            set_direction(Guard::UP);
        }

        else if (player_is_aligned_vertically and player_is_to_the_buttom_to_walk)
        {
            set_direction(Guard::DOWN);
        }

        else if(player_is_to_the_left_to_set_direction)
        {
            set_direction(Guard::LEFT);
        }

        else if(player_is_to_the_right_to_set_direction)
        {
            set_direction(Guard::RIGHT);
        }else{
            //do nothing
        }
    }else{
        //do nothing
    }
}

/**
 * [Guard::update_direction Updates the sprite of object (guard) based on the guard movement direction.]
 * @method Guard::update_direction
 * @param  elapsed                 [Elapsed time since the game start. This parameter is not used here.]
 */
void Guard::update_direction(unsigned long elapsed)
{

    if(guard_type == "easy")
    {
        if(elapsed - last_game_time_saved > 1000)
        {
            int random = rand()%100;

            if(random < 25)
                set_direction(Guard::LEFT);
            else if(random < 50)
                set_direction(Guard::UP);
            else if(random < 75)
                set_direction(Guard::RIGHT);
            else
                set_direction(Guard::DOWN);

            last_game_time_saved = elapsed;
        }else{
            //do nothing
        }
    }
    else if (guard_type == "normal")
    {
        if(elapsed - last_game_time_saved > 5000)
        {
            int test = ((int)direction() + 2) % 4;
            Direction new_direction = (Direction)test;
            set_direction(new_direction);

            last_game_time_saved = elapsed;
        }else{
            //do nothing
        }
    }
    else if(guard_type == "hard" || guard_type == "follow")
    {
        if(elapsed - last_game_time_saved > 5000)
        {
            int random = rand()%100;

            if(random < 25)
            {
                set_direction(Guard::LEFT);
            }
            else if(random < 50)
            {
                set_direction(Guard::UP);
            }
            else if(random < 75)
            {
                set_direction(Guard::RIGHT);
            }
            else
            {
                set_direction(Guard::DOWN);
            }

            last_game_time_saved = elapsed;
        }else{
            //do nothing
        }
    }else{
        //do nothing
    }
    guard_animation->set_row(this->direction());
}

/**
 * [Ghost::get_player_horizontal_position Receive the player's horizontal position.
 * This information is used at Guard artificial intelligence.]
 * @method Guard::get_playe_horizontal_position
 * @param  player_horizontal_position [That's the player's horizontal position.]
 */
void Guard::get_player_horizontal_position(const unsigned int player_horizontal_position)
{
    this->player_horizontal_position  = player_horizontal_position;
}

/**
 * [Ghost::get_player_vertical_position Receive the player's vertical position.
 * This information is used at Guard artificial intelligence.]
 * @method Guard::get_player_vertical_position
 * @param  player_vertical_position [That's the player's vertical position.]
 */
void Guard::get_player_vertical_position(const unsigned int player_vertical_position)
{
    this->player_vertical_position = player_vertical_position;
}

/**
 * [Guard::damage Returns the guard attack damage value.]
 * @method Guard::damage
 * @return [Returns the guard attack damage value]
 */
double Guard::damage()
{
    return GUARD_DAMAGE;
}

/**
 * [Guard::update_self Updates the guard position on the map and walk.]
 * @method Guard::update_self
 * @param  elapsed            [Elapsed time since the game start.]
 */
void Guard::update_self(unsigned long elapsed)
{
    set_horizontal_position(this->horizontal_position());
    set_vertical_position(this->vertical_position());

    update_direction(elapsed);
    guard_animation->update(elapsed);
    walk(elapsed);
    update_vision();
}

/**
 * [Guard::change_animation It is the animation of the guard
 * that will be loaded on the screen.]
 * @method Guard::change_animation
 */
void Guard::change_animation(string path)
{
    guard_animation.reset(new Animation(path, 0, 0, 70, 70, 8, 120, true));
}

/**
 * [Guard::health Returns the guard health value.]
 * @method Guard::health
 * @return [Returns the guard health value]
 */
double Guard::health()
{
    return guard_health;
}

/**
 * [Guard::type return the guard type]
 * @method Guard::type
 * @return [return the guard type]
 */
string Guard::type()
{
    return guard_type;
}

string Guard::old_type()
{
    return m_old_type;
}

/**
 * [Guard::set_type set the guard type as t]
 * @method Guard::set_type
 * @param  t               [string that defines the type of guard]
 */
void Guard::set_type(string t)
{
    guard_type = t;
}

/**
 * [Guard::set_old_type set the guard old type as t]
 * @method Guard::set_type
 * @param  t               [string that defines the old type of guard]
 */void Guard::set_old_type(string t)
{
    m_old_type = t;
}

/**
 * [Guard::receive_dmg receives the player damage]
 * @method Guard::receive_dmg
 * @param  dmg                [player damage]
 */
void Guard::receive_dmg(double dmg)
{
    guard_health = guard_health - dmg;
    if(guard_health < 0)
    {
        guard_health = 0;
    }else{
        //do nothing
    }
}
