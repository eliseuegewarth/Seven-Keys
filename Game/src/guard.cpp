#include "guard.h"

#include "core/level.h"
#include "core/environment.h"
#include "core/keyboardevent.h"

#include <cassert>
#include <iostream>

ActionID Guard::removeGuardID { "removeGuardID()" };
ActionID Guard::walkID { "walkID()" };

using namespace std;

const string& GUARD_RUNNING_PATH = "res/sprites/guarda1_running.png";
const string& GUARD_3_RUNNING_PATH = "res/sprites/guarda3_running.png";


/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param parent [description]
 * @param id [description]
 * @param guard_horizontal_position [description]
 * @param guard_vertical_position [description]
 * @param mass_of_guard [description]
 * @param walkable [description]
 * @param t [description]
 * @param initial_movement_direction [description]
 */
Guard::Guard(Object *parent, ObjectID id, const double guard_horizontal_position, 
            const double guard_vertical_position, const unsigned int mass_of_guard,
            const bool walkable, string t, const unsigned int initial_movement_direction)


{
    assert((parent != NULL) && "Parent needs to be different from NULL");
    Object(parent, id, guard_horizontal_position, guard_vertical_position);
    guard_type = t;
    guard_health = 100; 
    guard_animation  = (unique_ptr<Animation>)new Animation
    (GUARD_RUNNING_PATH, 0, 0, 70, 70, 8, GUARD_SPEED_IN_MILISECONDS, true);
    direction_of_movement = (Direction) initial_movement_direction;
    last_game_time_saved = 0;

    this->set_mass(mass_of_guard);
    this->set_w(70);
    this->set_h(70);
    this->set_walkable(walkable);
    this->set_old_type(t);
    update_vision();

    if(guard_type == "hard")
    {
        change_animation(GUARD_3_RUNNING_PATH);
    }
}

Guard::~Guard()
{
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return direction_of_movement[description]
 */
Guard::Direction Guard::direction()
{
    return direction_of_movement;
}

/**
 * @brief [brief description]
 * @details [long description]
 */
void Guard::update_vision()
{
    const list<Object *> filhos = this->children();

    for (auto filho : filhos)
    {
        if(filho->id() == "visao")
        {
            remove_child(filho);
        }
    }

    if(direction() == Guard::RIGHT)
    {
        Sight *visao = new Sight(this, "visao", this->x()+40, this->y(), 200, 80);
        add_child(visao);
    }
    else if(direction() == Guard::LEFT)
    {
        Sight *visao = new Sight(this, "visao", this->x() - 200, this->y(), 240, 80);
        add_child(visao);
    }
    else if(direction() == Guard::UP)
    {
        Sight *visao = new Sight(this, "visao", this->x(), this->y() - 200, 80, 240);
        add_child(visao);
    }
    else if(direction() == Guard::DOWN)
    {
        Sight *visao = new Sight(this, "visao", this->x(), this->y() + 40, 80, 200);
        add_child(visao);
    }

}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param direction_of_moviment [description]
 */
void Guard::set_direction(Direction direction_of_moviment)
{
    direction_of_movement = direction_of_moviment;
}

/**
 * @brief [brief description]
 * @details [long description]
 */
void Guard::draw_self()
{
    guard_animation->draw(x(), y());
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param elapsed [description]
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
                set_x(x() - GUARD_SPEED + (GUARD_SPEED * direction()));
                if(x() < 0 + 80)
                {
                    set_x(80);
                }
                else if(x() > env->canvas->w() - this->w() - 80)
                {
                    set_x(env->canvas->w() - this->w() - 80);
                }
            }
            if(direction() == Guard::UP || direction() == Guard::DOWN)
            {
                set_y(y() - 2 * GUARD_SPEED + (GUARD_SPEED * direction()));
                if(y() < 0 + 80)
                {
                    set_y(80);
                }
                else if(y() > env->canvas->h() - this->h() - 80)
                {
                    set_y(env->canvas->h() - this->h() - 80);
                }
            }
        }
    }
    else if(guard_type == "follow")
    {

        if(player_horizontal_position + 70 < this->x())
        {
            set_x(x() - GUARD_SPEED);
        }
        else if(player_horizontal_position > this->x() + 70)
        {
            set_x(x() + GUARD_SPEED);
        }

        if(player_vertical_position + 70 < this->y())
        {
            set_y(y() - GUARD_SPEED);
        }
        else if(player_vertical_position > this->y() + 70)
        {
            set_y(y() + GUARD_SPEED);
        }

        const bool player_is_to_the_right = (player_horizontal_position > this->x());
        const bool player_is_to_the_left = (player_horizontal_position < this->x());
        const bool player_is_to_the_top = (player_vertical_position < this->y());
        const bool player_is_to_the_buttom = (player_vertical_position > this->y());
        const bool player_is_aligned_vertically = (not player_is_to_the_right and not player_is_to_the_left);
        if(player_is_aligned_vertically and player_is_to_the_top)
        {
            set_direction(Guard::UP);
        }
        else if(player_is_aligned_vertically and player_is_to_the_buttom)
        {
            set_direction(Guard::DOWN);
        }
        else if(player_is_to_the_left)
        {
            set_direction(Guard::LEFT);
        }
        else if(player_is_to_the_right)
        {
            set_direction(Guard::RIGHT);
        }

    }
        return;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param long [description]
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
        }
    }
    guard_animation->set_row(this->direction());
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param player_horizontal_position [description]
 */
void Guard::get_playerx(const unsigned int player_horizontal_position)
{
    this->player_horizontal_position  = player_horizontal_position;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param player_vertical_position [description]
 */
void Guard::get_playery(const unsigned int player_vertical_position)
{
    this->player_vertical_position = player_vertical_position;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
double Guard::damage()
{
    return GUARD_DAMAGE;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param elapsed [description]
 */
void Guard::update_self(unsigned long elapsed)
{
    set_x(this->x());
    set_y(this->y());
   
    update_direction(elapsed);
    guard_animation->update(elapsed);
    walk(elapsed);
    update_vision();
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param path [description]
 */
void Guard::change_animation(string path)
{
    guard_animation.reset(new Animation(path, 0, 0, 70, 70, 8, 120, true));
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
double Guard::health()
{
    return guard_health;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
string Guard::type()
{
    return guard_type;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
string Guard::old_type()
{
    return m_old_type;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param t [description]
 */
void Guard::set_type(string t)
{
    guard_type = t;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param t [description]
 */
void Guard::set_old_type(string t)
{
    m_old_type = t;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param dmg [description]
 */
void Guard::receive_dmg(double dmg)
{
    guard_health = guard_health - dmg;
    if(guard_health < 0)
    {
        guard_health = 0;
    }
}