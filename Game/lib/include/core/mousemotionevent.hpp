/*
 * Classe que representa um evento de movimentação do mouse.
 *
 * Autor: Edson Alves
 * Data: 25/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MOUSE_MOTION_EVENT_H
#define MOUSE_MOTION_EVENT_H

#include <SDL2/SDL.h>

class MouseMotionEvent
{
public:
    typedef enum { DOWN, UP } MotionState; //Define the Motion states of mouse moviment
    typedef enum { LEFT, RIGHT, MIDDLE } Button; //Define the states of mouse button

    MouseMotionEvent(int horizontal_position, int vertical_position, int relative_horizontal_position, int relative_vertical_position, MotionState left,
        MotionState right, MotionState middle);

    MotionState state(Button button) const;
    int horizontal_position() const;
    int vertical_position() const;
    int relative_horizontal_position() const;
    int relative_vertical_position() const;

    static MouseMotionEvent from_SDL(const SDL_Event& event);

private:
    int m_horizontal_position; //Mouse position in axis x(horizontal)
    int m_vertical_position; //Mouse position in axis y(vertical)
    int m_relative_horizontal_position, m_relative_vertical_position;
    MotionState m_buttons[3];
};

#endif
