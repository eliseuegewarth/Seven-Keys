/**
 * square.hpp
 * Class that implements the square object of the game.
 * Licença: LGPL. Sem copyright.
 */

#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "core/object.hpp"
#include "core/keyboardevent.hpp"
#include "core/listener.hpp"

class Square : public Object, Listener
{
public:
    Square(Object *parent, ObjectID id, double size);
    ~Square();

    double size();
    bool on_event(const KeyboardEvent& event);

private:
    double m_speed;
    unsigned long m_last;

    void draw_self();
    void update_self(unsigned long elapsed);
};

#endif
