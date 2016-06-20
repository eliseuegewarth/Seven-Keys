/*
 * Implementation of a class that represents a texture.
 * Licença: LGPL. Sem copyright.
 */
#include "core/texture.hpp"
#include "core/exception.hpp"
#include "core/environment.hpp"
#include "core/settings.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cassert>

using std::make_pair;

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param data [description]
 * @param width [description]
 * @param height [description]
 * @param t [description]
 * @return [description]
 */
class Texture::Impl
{
public:
    Impl(void *data, int width, int height)
        : m_width(width), m_height(height)
    {
        m_texture = static_cast<SDL_Texture *>(data);

        Environment *env = Environment::get_instance();
        shared_ptr<Settings> settings = env->resources_manager->
        get_settings(env->m_settings_path);

        double k = settings->read<double>("Game", "scale", 1);

        scale(k);
    }

    ~Impl()
    {
        if (m_texture)
        {
            SDL_DestroyTexture(m_texture);
        }
    }

    int width() const
    {
        return m_width;
    }
    int height() const
    {
        return m_height;
    }
    void * data() const
    {
        return m_texture;
    }

    void scale(double k)
    {
        m_width = size().first * k;
        m_height = size().second * k;
    }

    pair<int, int> size() const
    {
        int width, height;
        int rc = SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);

        if (rc)
        {
            throw Exception(SDL_GetError());
        }

        return make_pair(width, height);
    }

private:
    int m_width, m_height;
    SDL_Texture *m_texture;
};

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param data [description]
 * @param width [description]
 * @param height [description]
 * @param h [description]
 * @param t [description]
 */
Texture::Texture(void *data, int width, int height)
    : m_impl(new Impl(data, width, height))
{
}

Texture::~Texture()
{
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
void * Texture::data() const
{
    return m_impl->data();
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int Texture::width() const
{
    return m_impl->width();
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int Texture::height() const
{
    return m_impl->height();
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param path [description]
 * @return [description]
 */
Texture * Texture::from_file(const string& path) throw (Exception)
{
    /* It is an object of the class environment. 
    Is a pointer to the current instance of the game environment.*/
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");

    SDL_Renderer *renderer = env->canvas->renderer();
    SDL_Texture *texture = IMG_LoadTexture(renderer, path.c_str());

    if (texture == nullptr)
    {
        throw Exception(SDL_GetError());
    }
    else
    {
        //nothing to do.
    }

    int width, height;

    int rc = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    if (rc)
    {
        throw Exception(SDL_GetError());
    }
    else
    {
        //nothing to do.
    }

    Texture *t = new Texture(texture, width, height);


    if (not t)
    {
        throw Exception("Out of memory for a new Texture");
    }
    else
    {
        //nothing to do.
    }

    return t;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param k [description]
 */
void Texture::scale(double k)
{
    m_impl->scale(k);
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
pair<int, int> Texture::size() const
{
    return m_impl->size();
}
