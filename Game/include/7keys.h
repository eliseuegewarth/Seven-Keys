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
    // Is the initial value of sanity (HP) of the player.
    #define INITIAL_SANITY_OF_THE_PLAYER 100;
    // Is the initial value of the player's lives.
    #define INITIAL_NUMBER_OF_LIVES_OF_THE_PLAYER 5;

    Level * load_level(const string& id);

    /*namespace Screen_type
    {
      const string& FONE = "fone";
    };*/

    // Is the number of the player's lives.
    unsigned int number_of_players_lives;
    // Is the player's sanity points.
    double player_sanity;
};

#endif
