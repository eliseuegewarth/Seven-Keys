/**
 * 7keys.hpp
 * Class that represents the entire game and manages the main screens.
 */

#ifndef TEST_H
#define TEST_H

#include <core/game.h>
#include "player.h"


class SevenKeys : public Game
{
public:
    
    /*static namespace screen_type
    {
      const string& FONE = "fone";
      const string& LOGO = "logo";
      const string& TECNOLOGIAS = "tecnologias";
      const string& CLASSIFICACAO = "classificacao";
      const string& TITLE = "title";
      const string& OPTIONS = "options";
      const string& TRANSITION = "trans";
      const string& DEATH = "death";
      const string& GAMEOVER = "gameover";
      const string& STAGE = "stage";
      const string& CREDITOS = "creditos";
      const string& EXTRAS = "extras";
    }Screen_type;*/
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
