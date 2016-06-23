/*
 * Implementação da classe que representa um texto.
 *
 * Autor: Edson Alves
 * Data: 14/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/text.hpp"

#include "core/font.hpp"
#include "core/texture.hpp"
#include "core/environment.hpp"

#include <SDL2/SDL.h>

#include <cassert>

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param parent [description]
 * @param text [description]
 * @param color [description]
 * @return [description]
 */
class Text::Impl
{
    public:
        Impl(Text *parent, const string& text, const Color& color)
    
        {
            m_parent = parent;

            /* It is an object of the class environment. 
            Is a pointer to the current instance of the game environment.*/
            Environment *env = Environment::get_instance();
            assert((env != NULL) && "Failed to pick up the instance of environment");

            m_texture = env->canvas->render_text(text, color);

            if (m_texture)
            {
                parent->set_dimensions(m_texture->width(), m_texture->height());
            }
        }

        ~Impl()
        {
            delete m_texture;
        }

        void draw_self()
        {
            if (not m_texture)
            {
                return;
            }

            Environment *env = Environment::get_instance();
            env->canvas->draw(m_texture, m_parent->horizontal_position(), m_parent->vertical_position());
        }

    private:
        Text *m_parent;
        Texture *m_texture;
};

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param parent [description]
 * @param texture [description]
 * @param color [description]
 * @param e [description]
 * @param l [description]
 * @param e [description]
 * @param r [description]
 */
Text::Text(Object *parent, const string& texture, const Color& color)
    : Object(parent, texture), m_impl(new Impl(this, texture, color))
{
    //nothing to do.
}

Text::~Text()
{
}

void Text::draw_self()
{
    m_impl->draw_self();
}
