/*
 * 7keys.cpp
 * Implementação da classe SevenKeys.
 * Class that represents the entire game and manages the main screens.
 */
#include <ijengine/core/environment.hpp>
#include <ijengine/core/level.hpp>

#include "7keys.hpp"
#include <ijengine/util/frontend.hpp>
#include "titlescreen.hpp"
#include "stage.hpp"
#include "options.hpp"
#include "credits.hpp"
#include "extras.hpp"

#include <cassert>
#include <cstring>
/**
 * @brief [This is the class constructor method. He starts the game in "headset" and plays a song.]
 */
SevenKeys::SevenKeys()
    : Game("fone")
{
    // Instance of the audio manager that is responsible for playing the game music.
    AudioManagerMusic * music2 = new AudioManagerMusic();
    assert(music2 != NULL && "Could not create instance of AudioManager Music");
    music2 -> play("res/sounds/musicaMenu.wav", -1);
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

    if (screen_type == "fone")
    {
        level_to_be_loaded = (Level*) new FrontEnd("logo", "logo", "res/EN-US/images/fone.png");
    }
    else if (screen_type == "logo")
    {
        level_to_be_loaded = (Level*) new FrontEnd("logo", "tecnologias", "res/EN-US/images/manateam.png");
    }
    else if (screen_type == "tecnologias")
    {
        level_to_be_loaded = (Level*) new FrontEnd("tecnologias", "classificacao", "res/EN-US/images/tecnologias.png");
    }
    else if (screen_type == "classificacao")
    {
        level_to_be_loaded = (Level*) new FrontEnd("classificacao", "title", "res/EN-US/images/classificacao_indicativa.png");
    }
    else if (screen_type == "title")
    {
        this->number_of_players_lives = INITIAL_NUMBER_OF_LIVES_OF_THE_PLAYER;
        this->player_sanity = INITIAL_SANITY_OF_THE_PLAYER;
        level_to_be_loaded = (Level*) new TitleScreen();
    }
    else if (screen_type == "options")
    {
        level_to_be_loaded = (Level*) new Options();
    }
    else if (strstr(screen_type.c_str(), "trans"))
    {

        /* It is an object of the class environment.
        Is a pointer to the current instance of the game environment.*/
        Environment *env = Environment::get_instance();

        assert(env != NULL && "failed to pick up the instance of Environment");

        // Comment This
        shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
        env->canvas->set_font(font);

        // Width of screen in pixels.
        double width = env->canvas->width();
        // Height of screen in pixels.
        double height = env->canvas->height();

        // String that contains the old type of screen.
        string ant = screen_type;

        // The screen to be loaded.
        Level *lvl = new Level(screen_type, screen_type);
        assert(lvl != NULL && "failed to create a Level instance");
        lvl->set_dimensions(width, height);

        char stage_screen_type[NEW_STRING_MAX_SIZE];
        snprintf(stage_screen_type, NEW_STRING_MAX_SIZE, "%s", screen_type.c_str());

        stage_screen_type[0] = 's';
        stage_screen_type[1] = 't';
        stage_screen_type[2] = 'a';
        stage_screen_type[3] = 'g';
        stage_screen_type[4] = 'e';


        string string_of_stage_number = screen_type.substr(5,5);
        char stage_number_array_of_characters[ STAGE_NUMBER_ARRAY_SIZE] = "";
        sprintf(stage_number_array_of_characters, "%s", string_of_stage_number.c_str());
        int new_stage_number = atoi(stage_number_array_of_characters);
        char path[PATH_STRING_MAX_SIZE] = "";
        if(new_stage_number < 6)
        {
            sprintf(path, "res/EN-US/interface/transicao/Fase%d.png", new_stage_number);
        }
        else
        {
            sprintf(path, "res/EN-US/interface/transicao/Bonus.png");
        }

        char music_path[MUSIC_PATH_STRING_MAX_SIZE];
        if(new_stage_number < 5)
        {
            sprintf(music_path, "res/sounds/Fase%d.wav", new_stage_number);
        }
        else
        {
            sprintf(music_path, "res/sounds/Fase5.wav");
        }
        env->music->play(music_path, -1);

        env->canvas->draw(screen_type, width/2, height/2 ,Color::RED);

        cout << stage_screen_type << endl;

        level_to_be_loaded = (Level*) new FrontEnd(screen_type, stage_screen_type, path);
    }

    else if(strstr(screen_type.c_str(), "death"))
    {
        Environment *env = Environment::get_instance();
        assert(env != NULL && "failed to pick up the instance of Environment");
        env->sfx->play("res/sounds/pregameover.wav",1);
        shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
        env->canvas->set_font(font);

        // Width of screen in pixels.
        double width = env->canvas->width();
        // Height of screen in pixels.
        double height = env->canvas->height();

        // String that contains the old type of screen.
        string ant = screen_type;

        // The screen to be loaded.
        Level *lvl = new Level(screen_type, screen_type);
        assert(lvl != NULL && "failed to create a Level instance");
        lvl->set_dimensions(width, height);

        char stage_screen_type[NEW_STRING_MAX_SIZE];
        sprintf(stage_screen_type, "%s",screen_type.c_str());
        stage_screen_type[0] = 's';
        stage_screen_type[1] = 't';
        stage_screen_type[2] = 'a';
        stage_screen_type[3] = 'g';
        stage_screen_type[4] = 'e';

        this->number_of_players_lives--;

        level_to_be_loaded = (Level*) new FrontEnd(screen_type, stage_screen_type, "res/EN-US/images/transition.png");
    }
    else if(screen_type == "gameover")
    {
        Environment *env = Environment::get_instance();
        assert(env != NULL && "failed to pick up the instance of Environment");
        env->sfx->play("res/sounds/gameOver.wav",1);

        // Width of screen in pixels.
        double width = env->canvas->width();
        // Height of screen in pixels.
        double height = env->canvas->height();

        // The screen to be loaded.
        Level *lvl = new Level(screen_type, screen_type);
        assert(lvl != NULL && "failed to create a Level instance");
        lvl->set_dimensions(width, height);
        level_to_be_loaded = (Level*) new FrontEnd(screen_type, "title", "res/EN-US/interface/transicao/gameOver.png");
    }
    else if (strstr(screen_type.c_str(), "stage"))
    {
        level_to_be_loaded = (Level*) new Stage(screen_type, this->number_of_players_lives, &(this->player_sanity));
    }
    else if (screen_type == "creditos")
    {
        level_to_be_loaded = (Level*) new Credits();
    }
    else if (screen_type == "extras")
    {
        level_to_be_loaded = (Level*) new Extras();
    }
    else{
        // Do nothing
    }
    assert(level_to_be_loaded != nullptr && "Could not load a screen.");

    return level_to_be_loaded;
}
