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
    typedef enum { DOWN, UP } State;
    typedef enum { LEFT, RIGHT, MIDDLE } Button;

    MouseMotionEvent(int horizontal_position, int vertical_position, int relative_horizontal_position, int relative_vertical_position, State left,
        State right, State middle);

    State state(Button button) const;
    int horizontal_position() const;
    int vertical_position() const;
    int relative_horizontal_position() const;
    int relative_vertical_position() const;

    static MouseMotionEvent from_SDL(const SDL_Event& event);

private:
    int m_vertical_position;
    int m_vertical_position;
    int m_relative_horizontal_position;
    int m_relative_vertical_position;
    State m_buttons[3];
};

#endif
