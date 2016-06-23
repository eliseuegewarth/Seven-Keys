#ifndef CREDITS_H
#define CREDITS_H

#include "core/level.hpp"

/**
 * credits.h
 * @brief [Class that implements the credits of the game.]
 * Licença: LGPL. Sem copyright.
 */

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
