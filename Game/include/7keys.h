/**
 * 7keys.h
 * Class that represents the entire game and manages the main screens.
 */

#ifndef TEST_H
#define TEST_H

#include <core/game.h>
#include "player.h"

class SevenKeys : public Game
{
public:
    
    SevenKeys();

private:
    #define INITIAL_SANITY_OF_THE_CHARACTER 100;
    #define INITIAL_NUMBER_OF_LIVES_OF_THE_CHARACTER 5;
    Level * load_level(const string& id);
    unsigned int lives;
    double sanity;
};

#endif
