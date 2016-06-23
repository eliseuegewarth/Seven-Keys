#include <core/rect.hpp>
#include <core/keyboardevent.hpp>
#include <core/environment.hpp>

#include "square.hpp"

#include <cassert>

#define SPEED 150.5

/**
 * [Square::Square description]
 * @param parent [The parent is the map object that
 *                              will contains the ghost guard.]
 * @param id [identifier of object]
 * @param size [Square size that will be created, height and width]
 */
Square::Square(Object *parent, ObjectID id, double size)
{
    assert((parent != NULL) && "Parent can't be NULL");
    assert((not id.empty()) && "ID can't be empty");
    assert((size >= 0) && "Size can't be negative");
    Object(parent, id, 0, 0, size, size);
    m_speed= 0;
    m_last=0;
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");
    env->events_manager->register_listener(this);

    double vertical_position = env->canvas->height()*0.6 - size;
    set_vertical_position(vertical_position);
}
Square::~Square()
{
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");
    env->events_manager->unregister_listener(this);
}
/**
 * [Square::size returns one of the sides of the square, width or height]
 * @method Square::size
 * @return [square width]
 */
double Square::size()
{
    return width();
}
/**
 * [Square::on_event            return if the square is on an event]
 * @method Square::on_event
 * @param  event                [keyboard action]
 * @return      [true when the keyboard is in any event or false if it is not]
 */
bool Square::on_event(const KeyboardEvent& event)
{
    switch (event.state())
    {
    case KeyboardEvent::PRESSED:
        switch (event.key())
        {
        case KeyboardEvent::LEFT:
            m_speed = -SPEED;
            return true;

        case KeyboardEvent::RIGHT:
            m_speed = SPEED;
            return true;
        default:
            return false;
        }
        break;

    case KeyboardEvent::RELEASED:
        switch (event.key())
        {
        case KeyboardEvent::LEFT:
        case KeyboardEvent::RIGHT:
            m_speed = 0;
            return true;
        default:
            return false;
        }
    }

    return false;
}
/**
 * [Square::draw_self Draws the animation of the environment on screen.]
 * @method Square::draw_self
 */
void Square::draw_self()
{
    const Color color { 80, 180, 205 };

    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");
    env->canvas->fill(bounding_box(), color);
}

/**
 * [Square::update_self Updates the environment on the screen.]
 * @method Square::update_self
 * @param  elapsed             [Elapsed time since the game start.]
 */
void Square::update_self(unsigned long elapsed)
{
    if (m_speed == 0)
    {
        m_last = 0;
        return;
    }else{
        //do nothing
    }

    if (not m_last)
    {
        m_last = elapsed;
    }else{
        //do nothing
    }

    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");

    double horizontal_position = this->horizontal_position() + m_speed*((elapsed - m_last)/(double)1000);
    m_last = elapsed;

    if (horizontal_position < 0)
    {
        horizontal_position = 0;
    }else{
        //do nothing
    }

    if (horizontal_position + width() > env->canvas->width())
    {
        horizontal_position = env->canvas->width() - width();
    }else{
        //do nothing
    }

    set_horizontal_position(horizontal_position);
}
