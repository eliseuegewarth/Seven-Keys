#ifndef PAUSE_H
#define PAUSE_H

#include "core/level.hpp"

class Image;

// Class that represents the pause option of the main menu of the game.
class Pause : public Level
{
public:
    Pause();
    virtual ~Pause();

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif
