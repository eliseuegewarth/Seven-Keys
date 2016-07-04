#include "core/mousemotionevent.hpp"

/**
 * [MouseMotionEvent::MouseMotionEvent description]
 * @method MouseMotionEvent::MouseMotionEvent
 * @param  horizontal_position                    [Mouse position in axis x(horizontal)]
 * @param  vertical_position                    [Mouse position in axis y(vertical)]
 * @param  relative_horizontal_position                [Mouse position in axis x(horizontal)]
 * @param  relative_vertical_position                [Mouse position in axis y(vertical)]
 * @param  left                 [Position where the mouse is moving (left)]
 * @param  right                [Position where the mouse is moving (right)]
 * @param  middle               [Position where the mouse is moving (middle)]
 */
MouseMotionEvent::MouseMotionEvent(int horizontal_position, int vertical_position, int relative_horizontal_position, int relative_vertical_position,
    MotionState left, MotionState right, MotionState middle)
{
    this->m_horizontal_position = horizontal_position;
    this->m_vertical_position = vertical_position;
    this->m_relative_horizontal_position = relative_horizontal_position;
    this->m_relative_vertical_position = relative_vertical_position;
    this->m_buttons[0] = left;
    this->m_buttons[1] = right;
    this->m_buttons[2] = middle;
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
    return this->m_buttons[button];
}

/**
 * [MouseMotionEvent::horizontal_position Mouse position in axis x(horizontal)]
 * @method MouseMotionEvent::horizontal_position
 * @return [Returns the mouse position in axis x(horizontal)]
 */
int MouseMotionEvent::horizontal_position() const
{
    return this->m_horizontal_position;
}

/**
 * [MouseMotionEvent::vertical_position Mouse position in axis y(vertical)]
 * @method MouseMotionEvent::vertical_position
 * @return [Returns the mouse position in axis y(vertical)]
 */
int MouseMotionEvent::vertical_position() const
{
    return this->m_vertical_position;
}

int MouseMotionEvent::relative_horizontal_position() const
{
    return this->m_relative_horizontal_position;
}

int
MouseMotionEvent::relative_vertical_position() const
{
    return this->m_relative_vertical_position;
}

/**
 * [MouseMotionEvent::from_SDL      Reads the movements from the SDL library
 *                                     and returns the states for class]
 * @method MouseMotionEvent::from_SDL
 * @param  event                      [mouse event detected by the SDL library]
 * @return                            [mouse movement]
 */
MouseMotionEvent MouseMotionEvent::from_SDL(const SDL_Event& event)
{
    int horizontal_position = event.motion.x;
    int vertical_position = event.motion.y;
    int relative_horizontal_position = event.motion.xrel;
    int relative_vertical_position = event.motion.yrel;

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

    return MouseMotionEvent(horizontal_position, vertical_position, relative_horizontal_position, relative_vertical_position, left, right, middle);
}
