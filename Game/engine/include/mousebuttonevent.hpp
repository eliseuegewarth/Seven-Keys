/*
 * Classe que representa um evento de botão do mouse.
 *
 * Autor: Edson Alves
 * Data: 22/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MOUSE_BUTTON_EVENT_H
#define MOUSE_BUTTON_EVENT_H

#include <SDL2/SDL.h>

class MouseButtonEvent
{
public:
    typedef enum {PRESSED, RELEASED} State;
    typedef enum { LEFT, RIGHT, MIDDLE } Button;

    MouseButtonEvent(State state, Button button, double horizontal_position, double vertical_position);

    State state() const;
    Button button() const;
    double horizontal_position() const;
    double vertical_position() const;

    static MouseButtonEvent from_SDL(const SDL_Event& event);

private:
    State m_state;
    Button m_button;
    double m_horizontal_position, m_vertical_position;
};

#endif
