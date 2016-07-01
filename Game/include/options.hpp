/**
 * options.hpp
 * Class that implements the options game menu.
 * Licença: LGPL. Sem copyright.
 */

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "core/level.hpp"

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
