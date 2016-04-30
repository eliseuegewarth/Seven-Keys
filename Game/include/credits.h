#ifndef CREDITS_H
#define CREDITS_H

#include <core/level.h>

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
