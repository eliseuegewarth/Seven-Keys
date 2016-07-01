/*
 * titlescreen.hpp
 * This class implements the start menu screen.
 * Licença: LGPL. Sem copyright.
 */

#ifndef TITLE_SCREEN_HPP
#define TITLE_SCREEN_HPP

#include "core/level.hpp"

class Image;

class TitleScreen : public Level
{
public:
    TitleScreen();
    virtual ~TitleScreen();

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif
