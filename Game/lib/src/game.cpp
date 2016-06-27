/*
 * Implementation of the class that represents a game using SDL.
 * Licença: LGPL. Sem copyright.
 */
#include "core/game.hpp"
#include "core/video.hpp"
#include "core/environment.hpp"
#include "core/systemevent.hpp"
#include "core/keyboardevent.hpp"
#include "core/settings.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <cassert>

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param id Map identifier file.
 */
Game::Game(const string& id)
{
    m_id = id; //Map identifier file.
    m_level = nullptr; //Stores the game levels.
    m_done = false; //Stores if it was create or not the level.

    /*It is an object of the class environment. 
    Is a pointer to the current instance of the game environment.*/
    env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");

}

Game::~Game()
{
    if (m_level)
    {
        delete m_level;
    }

    env->events_manager->unregister_listener(this);
    Environment::release_instance();
}

/**
 * @brief initializes the game with all the preconditions
 * 
 * @param whdth variable that stores the width of the resolution.
 * @param height variable that stores the screen resolution height.
 * @param scale variable that stores the display scale.
 * @param fullscreen boolean variable that stores the state of the screen.
 * @param volume Variable that stores the game audio volume.
 */
void Game::init(const string& title, unsigned const int width, 
                unsigned const int height,const double scale,
                bool fullscreen, unsigned int volume) throw (Exception)
{
    env->video->set_resolution(width, height, scale);
    env->video->set_window_name(title);
    env->video->set_fullscreen(fullscreen);
    env->music->set_volume(volume);
    env->sfx->set_volume(volume);

    SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);

    if (SDL_NumJoysticks() > 0)
    {
        SDL_GameControllerOpen(0);
    }

    env->events_manager->register_listener(this);

    m_level = load_level(m_id);
}

/**
 * @brief Method to init the game.
 * 
 * @param path [description]
 */
void Game::init(const string& path) throw (Exception)
{
    env->m_settings_path = path;

    shared_ptr<Settings> settings = env->resources_manager->get_settings(path);

    string title = settings->read<string>("Game", SevenKeys::ScreenType::MAIN_SCREEN, "Test Game");

    //variable that stores the width of the resolution.
    int width = settings->read<int>("Game", "w", 800); 

    //variable that stores the screen resolution height.
    int height = settings->read<int>("Game", "h", 600); 

    //variable that stores the display scale.
    double scale = settings->read<double>("Game", "scale", 1); 

    //boolean variable that stores the state of the screen.
    bool fullscreen = settings->read<bool>("Game", "fullscreen", false); 

    //Variable that stores the game audio volume.
    int volume = settings->read<int>("Game", "volume", 50); 

    init(title, width, height, scale, fullscreen, volume);
}

/**
 * @brief Method to start the game.
 * 
 */
void Game::run()
{
    while (m_level and not m_done)
    {
        //Number of milliseconds since the SDL library initialized. 
        unsigned long now = update_timestep(); 
        env->events_manager->dispatch_pending_events();

        m_level->update(now);
        env->camera->update(now);

        m_level->draw();
        update_screen();
        delay(1);

        if (m_level->finished())
        {
            string next = m_level->next();
            delete m_level;
            m_level = load_level(next);
        }
    }
}

unsigned long Game::update_timestep() const
{
    return SDL_GetTicks();
}

bool Game::on_event(const SystemEvent& event)
{
    if (event.type() == SystemEvent::QUIT)
    {
        m_done = true;
        return true;
    }

    return false;
}

bool Game::on_event(const KeyboardEvent& event)
{
    if (event.state() == KeyboardEvent::PRESSED
        and event.key() == KeyboardEvent::ESCAPE)
    {
        m_done = true;
        return true;
    }

    return false;
}

void Game::update_screen()
{
    /* It is an object of the class environment. 
    Is a pointer to the current instance of the game environment.*/
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");

    env->canvas->update();
}

void Game::delay(unsigned long ms)
{
    SDL_Delay(ms);
}

Level * Game::load_level(const string&)
{
    return nullptr;
}
