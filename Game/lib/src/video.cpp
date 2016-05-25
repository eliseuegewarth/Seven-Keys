/*
 * Implementation of the Video class.
 *
 * Licença: LGPL. Sem copyright.
 */
 
#include "core/video.h"
#include "core/camera.h"
#include "core/canvas.h"
#include "core/environment.h"

#include <SDL2/SDL_ttf.h>
#include <cassert>


using std::make_pair;

/**
 * @brief [brief description]
 * @details [long description]
 */
Video::Video()
{
    m_window = nullptr;
    m_renderer = nullptr;
    m_canvas = nullptr;
    m_camera = nullptr;
    m_w = 800;
    m_h = 600;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @return [description]
 */
Video::~Video()
{
    if (m_camera)
    {
        delete m_camera;
        delete m_canvas;
    }
    else
    {
        //nothing to do.
    }


    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
    }
    else
    {
        //nothing to do.
    }

    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }
    else
    {
        //nothing to do.
    }

    if (TTF_WasInit())
    {
        TTF_Quit();
    }
    else
    {
        //nothing to do.
    }

    if (SDL_WasInit(SDL_INIT_EVERYTHING))
    {
        SDL_Quit();
    }
    else
    {
        //nothing to do.
    }
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 */
void Video::init() throw (Exception)
{
    int rc = SDL_Init(SDL_INIT_VIDEO);

    if (rc)
    {
        throw Exception(SDL_GetError());
        throw Exception(TTF_GetError());
    }
    else
    {
        //nothing to do.
    }

    rc = TTF_Init();
    rc = SDL_CreateWindowAndRenderer(m_w, m_h, 0, &m_window, &m_renderer);

    if (rc or not m_window or not m_renderer)
    {
        throw Exception(SDL_GetError());
    }
    else
    {
        //nothing to do.
    }

    m_canvas = new Canvas(m_renderer, m_w, m_h);

    if (not m_canvas)
    {
        throw Exception("Out of memory for a new Canvas");
    }
    else
    {
        //nothing to do.
    }

    m_camera = new Camera(0, 0, m_w, m_h);

    if (not m_camera)
    {
        throw Exception("Out of memory for a new Camera");
    }
    else
    {
        //nothing to do.
    }
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param w [description]
 * @param h [description]
 * @param scale [description]
 */
void Video::set_resolution(int w, int h, double scale) throw (Exception)
{
    if (m_window and w > 0 and h > 0)
    {
        m_w = w;
        m_h = h;
        SDL_SetWindowSize(m_window, w, h);

        int rc = SDL_RenderSetLogicalSize(m_renderer, m_w, m_h);

        if (rc != 0)
        {
            throw Exception(SDL_GetError());
        }

        m_canvas->set_resolution(w, h);
        m_camera->set_dimensions(w, h);

         /* It is an object of the class environment. 
        Is a pointer to the current instance of the game environment.*/
        Environment *env = Environment::get_instance();
        assert((env != NULL) && "Failed to pick up the instance of environment");
        
        env->resources_manager->scale(scale);
    }
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param fullscreen [description]
 */
void Video::set_fullscreen(bool fullscreen) throw (Exception)
{
    if (not m_window)
    {
        return;
    }

    int flag = fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;

    int rc = SDL_SetWindowFullscreen(m_window, flag);

    if (rc != 0)
    {
        throw Exception(SDL_GetError());
    }

}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param flag [description]
 * @return [description]
 */
bool Video::fullscreen() const
{
    int flag = SDL_GetWindowFlags(m_window);

    if (flag & SDL_WINDOW_FULLSCREEN)
    {
        return true;
    }

    return false;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param name [description]
 */
void Video::set_window_name(const string& name)
{
    if (m_window)
    {
        SDL_SetWindowTitle(m_window, name.c_str());
    }
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param make_pair [description]
 * @param h [description]
 * 
 * @return [description]
 */
pair<int, int> Video::resolution() const
{
    return make_pair(m_w, m_h);
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
Canvas * Video::canvas() const
{
    return m_canvas;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
Camera * Video::camera() const
{
    return m_camera;
}
