/*
 * 7keys.cpp
 * Class that represents the entire game and manages the main screens.
 * Licença: LGPL. Sem copyright.
 */

#include "core/environment.hpp"
#include "core/level.hpp"

#include "7keys.hpp"
#include "util/frontend.hpp"
#include "titlescreen.hpp"
#include "stage.hpp"
#include "options.hpp"
#include "credits.hpp"
#include "extras.hpp"
#include "internacionalization.hpp"

#include <cassert>
#include <cstring>

// String paths definition of resources
// Path of music of menu
#define PATH_OF_MUSIC_OF_MENU "res/sounds/musicaMenu.wav"
// Path of Headphone image
#define HEADPHONE_IMAGE_PATH "images/fone.png"
// Path of  Development team logo image
#define MANA_TEAM_IMAGE_PATH "images/manateam.png"
// Path of used technologies image
#define USED_TECNOLOGIES_IMAGE_PATH "images/tecnologias.png"
// Path of game age rating image
#define AGE_RATING_IMAGE_PATH "images/classificacao_indicativa.png"
// Path of game font used in game
#define PATH_OF_GAME_FONT "res/fonts/TakaoExGothic.ttf"
// Formatted string of path of stage screen image file
#define STAGE_TRANSITION_IMAGE_PATH "interface/transition/stage%d.png"
// Path of bonus stage screen image
#define BONUS_STAGE_TRANSITION_IMAGE_PATH "interface/transition/Bonus.png"
// Formatted string of path of stage music file
#define PATH_OF_MUSIC_OF_STAGE "res/sounds/Fase%d.wav"
// Path of Bonus stage music file
#define PATH_OF_MUSIC_OF_BONUS_STAGE "res/sounds/Fase5.wav"
// Path of death music file
#define PATH_OF_DEATH_MUSIC "res/sounds/pregameover.wav"
// Path of Empty black transition image used when player die.
#define EMPTY_BLACK_TRANSITION_PATH "images/transition.png"
//
#define PATH_OF_GAME_OVER_MUSIC "res/sounds/gameOver.wav"

// Path of Game Over transition image.
#define GAME_OVER_IMAGE_PATH "interface/transition/gameOver.png"

#define EMPTY_STRING ""
#define NUMBER_OF_STAGES 5

/**
 * @brief [ScreenType class definition. All string literals of screen types are definied here.]
 */
const string& SevenKeys::ScreenType::LANGUAGUE = "language";
const string& SevenKeys::ScreenType::LANGUAGUE_OPTIONS = "language_options";
const string& SevenKeys::ScreenType::HEADPHONE = "headphone";
const string& SevenKeys::ScreenType::COMPANY_LOGO = "Company_Logo";
const string& SevenKeys::ScreenType::USED_TECHNOLOGIES = "Technologies";
const string& SevenKeys::ScreenType::AGE_RATING = "Age Rating";
const string& SevenKeys::ScreenType::MAIN_SCREEN = "Main Screen";
const string& SevenKeys::ScreenType::OPTIONS = "Options";
const string& SevenKeys::ScreenType::STAGE = "stage";
const string& SevenKeys::ScreenType::TRANSITION = "trans";
const string& SevenKeys::ScreenType::DEATH = "death";
const string& SevenKeys::ScreenType::GAME_OVER = "gameover";
const string& SevenKeys::ScreenType::CREDITS = "credits";
const string& SevenKeys::ScreenType::EXTRAS = "extras";
const string& SevenKeys::ScreenType::PAUSE = "pause";
const string& SevenKeys::ScreenType::EXIT = "exit";

/**
 * @brief [This is the class constructor method. He starts the game and plays a song.]
 */
SevenKeys::SevenKeys()
    : Game(SevenKeys::ScreenType::LANGUAGUE)
{
    // Instance of the audio manager that is responsible for playing the game music.
    AudioManagerMusic * music_of_menu = new AudioManagerMusic();
    assert(music_of_menu != NULL && "Could not create instance of AudioManager Music");
    music_of_menu -> play(PATH_OF_MUSIC_OF_MENU, -1);
}

/**
 * @brief [Returns the pointer to a screen that will be loaded.]
 *
 * @param screen_type [String that contains the type of screen that will be loaded.]
 * @return level_to_be_loaded [Returns the screen that will be loaded.]
 */
Level *
SevenKeys::load_level(const string& screen_type) {
    assert(((not (screen_type.empty())) && "screen_type needs to be different empty string"));

    // Represents the screen that will be loaded.
    Level * level_to_be_loaded = nullptr;

    if (screen_type == SevenKeys::ScreenType::LANGUAGUE)
    {
        if(not Internacionalization::LanguageType::is_language()){
            /*LOG.info("Showing Language menu screen.")*/
            cout << "Showing Language menu screen." <<endl;
            level_to_be_loaded = (Level*) new Internacionalization(false);
        }else{
            cout << "Showing Headphone hint screen." <<endl;
            string path_fone = Internacionalization::load_string(HEADPHONE_IMAGE_PATH);

            level_to_be_loaded = (Level*) new FrontEnd( SevenKeys::ScreenType::COMPANY_LOGO, 
                                                                                SevenKeys::ScreenType::COMPANY_LOGO, 
                                                                                path_fone);
        }
    }
    else if (screen_type == SevenKeys::ScreenType::LANGUAGUE_OPTIONS)
    {
        /*LOG.info("Showing Language menu screen.")*/
        cout << "Showing Language menu screen." <<endl;
        level_to_be_loaded = (Level*) new Internacionalization(true);
    }
    else if (screen_type == SevenKeys::ScreenType::HEADPHONE)
    {
        /*LOG.info("Showing Headphone hint screen.")*/
        cout << "Showing Headphone hint screen." <<endl;
        string path_fone = Internacionalization::load_string(HEADPHONE_IMAGE_PATH);
        level_to_be_loaded = (Level*) new FrontEnd(SevenKeys::ScreenType::COMPANY_LOGO, 
                                                                            SevenKeys::ScreenType::COMPANY_LOGO, 
                                                                            path_fone);
    }
    else if (screen_type == SevenKeys::ScreenType::COMPANY_LOGO)
    {
        /*LOG.info("Showing company logo.")*/
        cout << "Showing company logo." << endl;
        string path_mana_team = Internacionalization::load_string(MANA_TEAM_IMAGE_PATH);
        level_to_be_loaded = (Level*) new FrontEnd(SevenKeys::ScreenType::COMPANY_LOGO, 
                                                                            SevenKeys::ScreenType::USED_TECHNOLOGIES, 
                                                                            path_mana_team);
    }
    else if (screen_type == SevenKeys::ScreenType::USED_TECHNOLOGIES)
    {
        /*LOG.info("Showing used Technologies.")*/
        cout << "Showing used Technologies." << endl;
        string path_technologies = Internacionalization::load_string(USED_TECNOLOGIES_IMAGE_PATH);
        level_to_be_loaded = (Level*) new FrontEnd(SevenKeys::ScreenType::USED_TECHNOLOGIES, 
                                                                            SevenKeys::ScreenType::AGE_RATING, 
                                                                            path_technologies);
    }
    else if (screen_type == SevenKeys::ScreenType::AGE_RATING)
    {
        /*LOG.info("Showing used Technologies.")*/
        cout << "Showing the game age rating." << endl;
        string path_classificacao = Internacionalization::load_string(AGE_RATING_IMAGE_PATH);
        cout << path_classificacao <<endl;
        level_to_be_loaded = (Level*) new FrontEnd(SevenKeys::ScreenType::AGE_RATING, 
                                                                            SevenKeys::ScreenType::MAIN_SCREEN, 
                                                                            path_classificacao);
    }
    else if (screen_type == SevenKeys::ScreenType::MAIN_SCREEN)
    {
        /*LOG.info("Showing Start Menu Screen.")*/
        cout << "Showing Start Menu Screen." << endl;
        this->number_of_players_lives = INITIAL_NUMBER_OF_LIVES_OF_THE_PLAYER;
        this->player_sanity = INITIAL_SANITY_OF_THE_PLAYER;
        level_to_be_loaded = (Level*) new TitleScreen();
    }
    else if (screen_type == SevenKeys::ScreenType::OPTIONS)
    {
        /*LOG.info("Showing Options Menu.")*/
        cout << "Showing Options Menu." << endl;
        level_to_be_loaded = (Level*) new Options();
    }
    else if (strstr(screen_type.c_str(), SevenKeys::ScreenType::TRANSITION.c_str()))
    {

        /*LOG.info("Showing transition screen.")*/
        cout << "Showing " <<  screen_type << "Screen" << endl;
        /* It is an object of the class environment.
        Is a pointer to the current instance of the game environment.*/
        Environment *env = Environment::get_instance();

        assert(env != NULL && "failed to pick up the instance of Environment");

        // Comment This
        shared_ptr <Font> font = env->resources_manager->get_font(PATH_OF_GAME_FONT);
        assert(font != nullptr);
        env->canvas->set_font(font);

        // String that contains the old type of screen.
        string ant = screen_type;

        char stage_screen_type[NEW_STRING_MAX_SIZE] = EMPTY_STRING;
        cout << "Creating " <<  stage_screen_type << " stage Screen" << endl;
        snprintf(stage_screen_type, NEW_STRING_MAX_SIZE, "stage%c", screen_type.c_str()[5]);

        cout << "Created " <<  stage_screen_type << " stage Screen" << endl;
        cout << "Created " <<  screen_type.substr(5,5) << " stage number string" << endl; 
        char stage_number_array_of_characters[ STAGE_NUMBER_ARRAY_SIZE] = EMPTY_STRING;
        sprintf(stage_number_array_of_characters, "%s", screen_type.substr(5,5).c_str());
        const int new_stage_number = atoi(stage_number_array_of_characters);
        assert(new_stage_number >= 0 && "Stage number must be greater than zero");
        char path[PATH_STRING_MAX_SIZE] = EMPTY_STRING;
        string path_transition_fase;
        if(new_stage_number <= NUMBER_OF_STAGES)
        {
            sprintf(path, STAGE_TRANSITION_IMAGE_PATH, new_stage_number);
            path_transition_fase = Internacionalization::load_string(path);
        }
        else
        {
            path_transition_fase = Internacionalization::load_string(BONUS_STAGE_TRANSITION_IMAGE_PATH);
        }

        char music_path[MUSIC_PATH_STRING_MAX_SIZE] = EMPTY_STRING;
        if(new_stage_number <= NUMBER_OF_STAGES)
        {
            sprintf(music_path, PATH_OF_MUSIC_OF_STAGE, new_stage_number);
        }
        else
        {
            sprintf(music_path, PATH_OF_MUSIC_OF_BONUS_STAGE);
        }
        env->music->play(music_path, -1);

        cout << stage_screen_type << endl;

        level_to_be_loaded = (Level*) new FrontEnd(screen_type, stage_screen_type,
                                                   path_transition_fase);
    }

    else if(strstr(screen_type.c_str(), SevenKeys::ScreenType::DEATH.c_str()))
    {
        /*LOG.info("Showing Death screen.")*/
        cout << "Showing Death screen." <<endl;
        Environment *env = Environment::get_instance();
        assert(env != NULL && "failed to pick up the instance of Environment");
        env->sfx->play(PATH_OF_DEATH_MUSIC,1);
        shared_ptr <Font> font = env->resources_manager->get_font(PATH_OF_GAME_FONT);
        env->canvas->set_font(font);

        char stage_screen_type[NEW_STRING_MAX_SIZE] = EMPTY_STRING;
        sprintf(stage_screen_type, "stage%c",screen_type.c_str()[5]);

        this->number_of_players_lives--;
        string path_transition = Internacionalization::load_string(EMPTY_BLACK_TRANSITION_PATH);
        level_to_be_loaded = (Level*) new FrontEnd(screen_type, stage_screen_type, path_transition);
    }
    else if(screen_type == SevenKeys::ScreenType::GAME_OVER)
    {
        /*LOG.info("Showing Game Over screen.")*/
        cout << "Showing Game Over screen." <<endl;
        Environment *env = Environment::get_instance();
        assert(env != NULL && "failed to pick up the instance of Environment");
        env->sfx->play(PATH_OF_GAME_OVER_MUSIC,1);

        string path_transition_game_over = Internacionalization::load_string(GAME_OVER_IMAGE_PATH);
        level_to_be_loaded = (Level*) new FrontEnd(screen_type, 
                                                                            SevenKeys::ScreenType::MAIN_SCREEN, 
                                                                            path_transition_game_over);
    }
    else if (strstr(screen_type.c_str(), SevenKeys::ScreenType::STAGE.c_str()))
    {
        /*LOG.info("Showing new stage screen.")*/
        cout << "Showing new stage screen." <<endl;
        level_to_be_loaded = (Level*) new Stage(screen_type, 
                                                                    this->number_of_players_lives, 
                                                                    &(this->player_sanity));
    }
    else if (screen_type == SevenKeys::ScreenType::CREDITS)
    {
        /*LOG.info("Showing Credits menu screen.")*/
        cout << "Showing Credits menu screen." <<endl;
        level_to_be_loaded = (Level*) new Credits();
    }
    else if (screen_type == SevenKeys::ScreenType::EXTRAS)
    {
        /*LOG.info("Showing Extras menu screen.")*/
        cout << "Showing Extras menu screen." <<endl;
        level_to_be_loaded = (Level*) new Extras();
    }
    else if (screen_type == SevenKeys::ScreenType::EXIT)
    {
        /*LOG.info("Exiting game.")*/
        cout << "Exiting game." <<endl;
        exit(0);
    }
    else{
        /*LOG.info("Failed to load " + screen_type + " screen type!")*/
        cout << "Failed to load " << screen_type << " screen type!" << endl;
    }
    assert(level_to_be_loaded != nullptr && "Could not load a screen.");

    return level_to_be_loaded;
}
