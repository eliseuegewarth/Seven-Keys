/*
 * 7keys.cpp
 * Implementação da classe SevenKeys.
 * Class that represents the entire game and manages the main screens.
 */
#include <ijengine/core/environment.h>
#include <ijengine/core/level.h>

#include "7keys.h"
#include <ijengine/util/frontend.h>
#include "titlescreen.h"
#include "stage.h"
#include "options.h"
#include "credits.h"
#include "extras.h"

#include <cassert>
#include <cstring>

SevenKeys::SevenKeys()
    : Game("fone")
{
    AudioManagerMusic * music2 = new AudioManagerMusic();
    assert(music2 != NULL && "Could not create instance of AudioManager Music");
    music2 -> play("res/sounds/musicaMenu.wav", -1);
}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param screen_type [description]
 * @return level_to_be_loaded [Returns the screen that will be loaded.]
 */
Level *
SevenKeys::load_level(const string& screen_type)
{
    assert(not screen_type.empty() && "screen_type needs to be different empty string");

    // Represents the screen that will be loaded.
    Level * level_to_be_loaded = nullptr;
    if (screen_type == "fone")
    {
        level_to_be_loaded = (Level*) new FrontEnd("logo", "logo", "res/images/fone.png");
    }
    if (screen_type == "logo")
    {
        level_to_be_loaded = (Level*) new FrontEnd("logo", "tecnologias", "res/images/manateam.png");
    }
    else if (screen_type == "tecnologias")
    {
        level_to_be_loaded = (Level*) new FrontEnd("tecnologias", "classificacao", "res/images/tecnologias.png");
    }
    else if (screen_type == "classificacao")
    {
        level_to_be_loaded = (Level*) new FrontEnd("classificacao", "title", "res/images/classificacao_indicativa.png");
    }
    else if (screen_type == "title")
    {
        this->lives = INITIAL_NUMBER_OF_LIVES_OF_THE_CHARACTER;
        sanity = INITIAL_SANITY_OF_THE_CHARACTER;
        level_to_be_loaded = (Level*) new TitleScreen();
    }
    else if (screen_type == "options")
    {
        level_to_be_loaded = (Level*) new Options();
    }
    else if (strstr(screen_type.c_str(), "trans"))
    {
        Environment *env = Environment::get_instance();
        assert(env != NULL && "failed to pick up the instance of Environment");
        shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
        env->canvas->set_font(font);

        double w = env->canvas->width();
        double h = env->canvas->height();

        string ant = screen_type;

        Level *lvl = new Level(screen_type, screen_type);
        assert(lvl != NULL && "failed to create a Level instance");
        lvl->set_dimensions(w, h);

        char novo[256];
        sprintf(novo, "%s", screen_type.c_str());
        novo[0] = 's';
        novo[1] = 't';
        novo[2] = 'a';
        novo[3] = 'g';
        novo[4] = 'e';


        string num_id = screen_type.substr(5,5);
        char num_id2[10];
        sprintf(num_id2, "%s", num_id.c_str());
        int novo_id = atoi(num_id2);
        char path[256];
        if(novo_id < 6)
            sprintf(path, "res/interface/transicao/Fase%d.png", novo_id);
        else
            sprintf(path, "res/interface/transicao/Bonus.png");

        char music_path[256];
        if(novo_id < 5)
            sprintf(music_path, "res/sounds/Fase%d.wav", novo_id);
        else
            sprintf(music_path, "res/sounds/Fase5.wav");
        env->music->play(music_path, -1);

        env->canvas->draw(screen_type, w/2, h/2 ,Color::RED);

        cout << novo << endl;

        level_to_be_loaded = (Level*) new FrontEnd(screen_type, novo, path);
    }

    else if(strstr(screen_type.c_str(), "death"))
    {
        Environment *env = Environment::get_instance();
        assert(env != NULL && "failed to pick up the instance of Environment");
        env->sfx->play("res/sounds/pregameover.wav",1);
        shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
        env->canvas->set_font(font);

        double w = env->canvas->width();
        double h = env->canvas->height();

        string ant = screen_type;

        Level *lvl = new Level(screen_type, screen_type);
        assert(lvl != NULL && "failed to create a Level instance");
        lvl->set_dimensions(w, h);

        char novo[256];
        sprintf(novo, "%s",screen_type.c_str());
        novo[0] = 's';
        novo[1] = 't';
        novo[2] = 'a';
        novo[3] = 'g';
        novo[4] = 'e';

        this->lives -= 1;

        level_to_be_loaded = (Level*) new FrontEnd(screen_type, novo, "res/images/transition.png");
    }
    else if(screen_type == "gameover")
    {
        Environment *env = Environment::get_instance();
        assert(env != NULL && "failed to pick up the instance of Environment");
        env->sfx->play("res/sounds/gameOver.wav",1);
        double w = env->canvas->width();
        double h = env->canvas->height();

        Level *lvl = new Level(screen_type, screen_type);
        assert(lvl != NULL && "failed to create a Level instance");
        lvl->set_dimensions(w, h);
        level_to_be_loaded = (Level*) new FrontEnd(screen_type, "title", "res/interface/transicao/gameOver.png");
    }
    else if (strstr(screen_type.c_str(), "stage"))
    {
        level_to_be_loaded = (Level*) new Stage(screen_type, lives, &sanity);
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
