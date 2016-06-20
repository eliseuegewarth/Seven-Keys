/*
 * Classe que representa um ouvinte de eventos de controle.
 *
 * Autor: Simiao Carvalho
 * Data: 26/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef JOYSTICK_EVENT_LISTENER_H
#define JOYSTICK_EVENT_LISTENER_H

class JoyStickEvent;
/*
Detects if any event is occurring in the
joystick buttons [UP, DOWN, LEFT, RIGHT or any other button]
*/
class JoyStickEventListener
{
public:
    virtual bool onJoyStickEvent(const JoyStickEvent& event) = 0;
};

#endif
