#ifndef OPTIONS_H
#define OPTIONS_H

#include <core/level.h>

class Image;

class Options : public Level
{
public:
    Options();
    virtual ~Options();

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif
