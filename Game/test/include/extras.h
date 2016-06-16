#ifndef EXTRAS_H
#define EXTRAS_H

#include <core/level.h>

class Image;

class Extras : public Level //Class that represents the extra option of the main menu of the game.
{
public:
    Extras();
    virtual ~Extras();

    bool on_message(Object *sender, MessageID id, Parameters parameters); 

private:
    void draw_self();
};

#endif