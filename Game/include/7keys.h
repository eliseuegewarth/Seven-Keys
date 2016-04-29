#ifndef TEST_H
#define TEST_H

#include <core/game.h>
#include "player.h"

/**
 * 7keys.h
 * @brief [Class that represents the entire game and manages the main screens.]
 * Licença: LGPL. Sem copyright.
 */

class SevenKeys : public Game
{
public:
    SevenKeys();

private:
    Level * load_level(const string& id);
    unsigned int lives;
    double sanity;
};

#endif
