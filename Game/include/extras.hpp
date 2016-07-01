/**
 * extras.hpp
 * Class that represents the extra option of the main menu of the game.
 * Licença: LGPL. Sem copyright.
 */

#ifndef EXTRAS_HPP
#define EXTRAS_HPP

#include "core/level.hpp"

class Image;

//Class that represents the extra option of the main menu of the game.
class Extras : public Level
{
public:
    Extras();
    virtual ~Extras();

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif
