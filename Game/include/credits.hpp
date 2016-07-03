/**
 * credits.hpp
 * Class that implements the credits of the game.
 * Licença: LGPL. Sem copyright.
 */

#ifndef CREDITS_HPP
#define CREDITS_HPP

#include "core/level.hpp"


class Image;

class Credits : public Level
{
public:
    Credits();
    virtual ~Credits();

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif
