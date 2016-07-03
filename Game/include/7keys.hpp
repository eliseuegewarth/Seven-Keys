/**
 * 7keys.hpp
 * Class that represents the entire game and manages the main screens.
 * Licença: LGPL. Sem copyright.
 */

#ifndef SEVENKEYS_HPP
#define SEVENKEYS_HPP

#include "core/game.hpp"
#include "player.hpp"
#include "internacionalization.hpp"

class SevenKeys : public Game
{
public:
    SevenKeys();

    // Class that represents the screen types of game.
    class ScreenType
    {
    public:
        static const string& LANGUAGUE;
		static const string& LANGUAGUE_OPTIONS;
        static const string& HEADPHONE;
        static const string& COMPANY_LOGO;
        static const string& USED_TECHNOLOGIES;
        static const string& AGE_RATING;
        static const string& MAIN_SCREEN;
        static const string& OPTIONS;
        static const string& STAGE;
        static const string& TRANSITION;
        static const string& DEATH;
        static const string& GAME_OVER;
        static const string& CREDITS;
        static const string& EXTRAS;
        static const string& PAUSE;
        static const string& EXIT;
    };
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
