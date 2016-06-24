/**
 * 7keys.hpp
 * Class that represents the entire game and manages the main screens.
 */

#ifndef TEST_H
#define TEST_H

#include "core/game.hpp"
#include "player.hpp"


class SevenKeys : public Game
{
public:
    SevenKeys();

private:
    // Is the initial value of sanity (HP) of the player.
    #define INITIAL_SANITY_OF_THE_PLAYER 100

    // Is the initial value of the player's lives.
    #define INITIAL_NUMBER_OF_LIVES_OF_THE_PLAYER 5

    //
    #define NEW_STRING_MAX_SIZE 256

    #define MUSIC_PATH_STRING_MAX_SIZE 256

    #define PATH_STRING_MAX_SIZE 256

    #define STAGE_NUMBER_ARRAY_SIZE 10


    Level * load_level(const string& id);

    // Is the number of the player's lives.
    unsigned int number_of_players_lives;
    // Is the player's sanity points.
    double player_sanity;
};

#endif
