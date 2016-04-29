#include "boss.h"

#include "core/level.h"
#include "core/environment.h"
#include "core/keyboardevent.h"

#include <core/animation.h>

#include <iostream>

using namespace std;

/**
 * @brief [Loads the information about the boss on the map.]
 * 
 * @param parent [The parent is the map Object that will contains the boss.]
 * @param id [Identifier of object type. in case of this class, aways have to be "boss".]
 * @param x [The position in horizontal(x) axis where boss will be placed. ]
 * @param y [The position in vertival(y) axis where boss will be placed. ]
 * @param mass [Contains Object Boss mass information.]
 * @param walkable [Defines whether the boss is an object able to walk.]
 * @param dir [Sets the initial movement direction.]
 */
Boss::Boss(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, int dir)
    : Object(parent, id, x, y), m_damage(0.9), m_animation (new Animation("res/sprites/boss_running.png",
    	0, 0, 90, 90, 6, 120, true)), m_direction((Direction) dir), m_last(0)
{
    this->set_mass(mass);
    this->set_w(70);
    this->set_h(70);
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
 * @brief [Just returns informations of m_direction.]
 * @return m_direction [The Boss movement direction.]
 */
Boss::Direction
Boss::direction()
{
    return m_direction;
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
 * @param direction [The value of the direction that will be setted.]
 */
void
Boss::set_direction(Direction direction)
{
    m_direction = direction;
}

/**
 * @brief [Draws the animation of boss on screen.]
 */
void
Boss::draw_self()
{
    m_animation->draw(x(), y());
}

/**
 * @brief [Walk to the player's position at a constant speed.]
 */
void
Boss::walk()
{
    // Define the boss walking speed.
    double speed = 1.3;
    if(player_posx < this->x())
        set_x(x() - speed);
    else
        set_x(x() + speed);

    if(player_posy < this->y())
        set_y(y() - speed);
    else
        set_y(y() + speed);

    if(player_posx > this->x() - 100 && player_posx < this->x() + 100 && player_posy < this->y())
        set_direction(Boss::UP);
    else if(player_posx > this->x() - 100 && player_posx < this->x() + 100 && player_posy > this->y())
        set_direction(Boss::DOWN);
    else if(player_posx < this->x())
        set_direction(Boss::LEFT);
    else
        set_direction(Boss::RIGHT);
}

/**
 * @brief [Updates the sprite of object (boss) based on the boss movement direction.]
 * 
 * @param elapsed [Elapsed time since the game start. This parameter is not used here.]
 */
void
Boss::update_direction(unsigned long elapsed)
{
    m_animation->set_row(this->direction());
}

/**
 * @brief [Receive the player's horizontal position. This information is used at Boss's artificial intelligence.
 * 
 * @param pos_x [That's the player's horizontal position.]
 */
void
Boss::get_playerx(int pos_x)
{
    player_posx = pos_x;
}

/**
 * @brief [Receive the player's vertical position. This information is used at Boss's artificial intelligence.
 * 
 * @param pos_y [That's the player's vertical position.]
 */
void
Boss::get_playery(int pos_y)
{
    player_posy = pos_y;
}

/**
 * @brief [Returns the boss attack damage value.]
 * @return m_damege [The boss attack damage value.]
 */
double
Boss::damage()
{
    return m_damage;
}

//
/**
 * @brief [Updates the boss's position on the map and walk.]
 * 
 * @param elapsed [Elapsed time since the game start.]
 */
void
Boss::update_self(unsigned long elapsed)
{

    set_x(this->x());
    set_y(this->y());
   
    update_direction(elapsed);
    m_animation->update(elapsed);
    walk();
}

/**
 * @brief [This method defines the boss's position in the room.]\
 * 
 * @param x [The boss horizontal position.]
 * @param y [The boss vertical position.]
 */
void
Boss::set_position(double x, double y)
{
    set_x(x);
    set_y(y);
}

/**
 * @brief [Set the m_summoned status with the 't' value.]
 * 
 * @param t [Contain the summoned state value.]
 */
void
Boss::set_summoned(bool t)
{
    m_summoned = t;
}

/**
 * @brief [Set the m_created status with the 't' value]
 * 
 * @param t [Contain the created state value.]
 */
void
Boss::set_created(bool t)
{
    m_created = t;
}