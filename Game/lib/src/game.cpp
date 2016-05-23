/*
 * Implementation of the class that represents a game using SDL.
 * Licença: LGPL. Sem copyright.
 */
#include "core/game.h"
#include "core/video.h"
#include "core/environment.h"
#include "core/systemevent.h"
#include "core/keyboardevent.h"
#include "core/settings.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Game::Game(const string& id)
    : m_id(id), m_level(nullptr), m_done(false)
{
    env = Environment::get_instance();

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
 * @brief [brief description]
 * @details [long description]
 * 
 * @param title [description]
 * @param int [description]
 * @param int [description]
 * @param scale [description]
 * @param fullscreen [description]
 * @param int [description]
 */
void Game::init(const string& title, unsigned const int width, unsigned const int height,
                const double scale, bool fullscreen, unsigned int volume) throw (Exception)
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
 * @brief [brief description]
 * @details [long description]
 * 
 * @param path [description]
 */
void Game::init(const string& path) throw (Exception)
{
    env->m_settings_path = path;

    shared_ptr<Settings> settings = env->resources_manager->get_settings(path);

    string title = settings->read<string>("Game", "title", "Test Game");
    int width = settings->read<int>("Game", "w", 800);
    int height = settings->read<int>("Game", "h", 600);
    double scale = settings->read<double>("Game", "scale", 1);
    bool fullscreen = settings->read<bool>("Game", "fullscreen", false);
    int volume = settings->read<int>("Game", "volume", 50);

    init(title, width, height, scale, fullscreen, volume);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param e [description]
 */
void Game::run()
{
    while (m_level and not m_done)
    {
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
    // It is an object of the class environment. Is a pointer to the current instance of the game environment.
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
