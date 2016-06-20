#include "core/mousemotionevent.hpp"

/**
 * [MouseMotionEvent::MouseMotionEvent description]
 * @method MouseMotionEvent::MouseMotionEvent
 * @param  x                    [Mouse position in axis x(horizontal)]
 * @param  y                    [Mouse position in axis y(vertical)]
 * @param  x_rel                [Mouse position in axis x(horizontal)]
 * @param  y_rel                [Mouse position in axis y(vertical)]
 * @param  left                 [Position where the mouse is moving (left)]
 * @param  right                [Position where the mouse is moving (right)]
 * @param  middle               [Position where the mouse is moving (middle)]
 */
MouseMotionEvent::MouseMotionEvent(int x, int y, int x_rel, int y_rel,
    MotionState left, MotionState right, MotionState middle)
{
    m_x = x;
    m_y = y;
    m_x_rel = x_rel;
    m_y_rel = y_rel;
    m_buttons[0] = left;
    m_buttons[1] = right;
    m_buttons[2] = middle;
}

/**
 * [MouseMotionEvent::state State of the buttons, if it is pressed or not]
 * @method MouseMotionEvent::state
 * @param  button                  [Button that is pressed]
 * @return                         [Return the button that is pressed]
 */
MouseMotionEvent::MotionState
MouseMotionEvent::state(MouseMotionEvent::Button button) const
{
    return m_buttons[button];
}

/**
 * [MouseMotionEvent::x Mouse position in axis x(horizontal)]
 * @method MouseMotionEvent::x
 * @return [Returns the mouse position in axis x(horizontal)]
 */
int MouseMotionEvent::x() const
{
    return m_x;
}

/**
 * [MouseMotionEvent::y Mouse position in axis y(vertical)]
 * @method MouseMotionEvent::y
 * @return [Returns the mouse position in axis y(vertical)]
 */
int MouseMotionEvent::y() const
{
    return m_y;
}

int MouseMotionEvent::x_rel() const
{
    return m_x_rel;
}

int
MouseMotionEvent::y_rel() const
{
    return m_y_rel;
}

/**
 * [MouseMotionEvent::from_SDL      Reads the movements from the SDL library
 * 									and returns the states for class]
 * @method MouseMotionEvent::from_SDL
 * @param  event                      [mouse event detected by the SDL library]
 * @return                            [mouse movement]
 */
MouseMotionEvent MouseMotionEvent::from_SDL(const SDL_Event& event)
{
    int x = event.motion.x;
    int y = event.motion.y;
    int xrel = event.motion.xrel;
    int yrel = event.motion.yrel;

    Uint8 state = event.motion.state;
    MotionState left = UP, right = UP, middle = UP;

    if (state & SDL_BUTTON(1))
    {
        left = DOWN;
    }else{
        //do nothing
    }

    if (state & SDL_BUTTON(2))
    {
        middle = DOWN;
    }else{
        //do nothing
    }

    if (state & SDL_BUTTON(3))
    {
        right = DOWN;
    }else{
        //do nothing
    }

    return MouseMotionEvent(x, y, xrel, yrel, left, right, middle);
}
