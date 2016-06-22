/*
 * Implementação da classe Animation.
 *
 * Autor: Edson Alves
 * Data: 05/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/animation.hpp"

#include "core/rect.hpp"
#include "core/texture.hpp"
#include "core/environment.hpp"

#include <cassert>

class Animation::Impl
{
public:
    Impl(const string& id, double horizontal_position_, double vertical_position_, double width_, double height_, int f,
        unsigned long s, bool l_)
    {
        this->horizontal_position = (horizontal_position_);
        this->vertical_position = (vertical_position_);
        this->width = (width_);
        this->height = (height_);
        this->frames = (f);
        this->speed = (s);
        this->loop = (l_);
        this->done = (false);
        this->last = (0);
        this->frame = (0);
        Environment *env = Environment::get_instance();
        this->texture = env->resources_manager->get_texture(id);
    }

    void reset()
    {
        last = frame = 0;
    }

    double horizontal_position;
    double vertical_position;
    double width;
    double height;
    int frames;
    unsigned long speed;
    bool loop;
    bool done;
    unsigned long last;
    int frame;
    shared_ptr<Texture> texture;
};

Animation::Animation(const string& texture, double horizontal_animation_positon, double vertical_animation_position, double width,
    double height, int frames, unsigned long speed_in_ms, bool loop)
    : m_impl(new Animation::Impl(texture, horizontal_animation_positon, vertical_animation_position, width, height, frames, speed_in_ms, loop))
{
}

Animation::~Animation()
{
}

bool
Animation::is_done() const
{
    return m_impl->done;
}

void
Animation::update(unsigned long elapsed)
{
    if (not m_impl->last)
    {
        m_impl->last = elapsed;
    }

    if (elapsed - m_impl->last > m_impl->speed)
    {
        ++m_impl->frame;
        m_impl->last += m_impl->speed;

        if (m_impl->loop)
        {
            m_impl->frame %= m_impl->frames;
        } else if (m_impl->frame == m_impl->frames)
        {
            --m_impl->frame;
            this->m_impl->done = true;
        }
    }
}

void
Animation::draw(double horizontal_position, double vertical_position)
{
    if (this->m_impl->done)
    {
        return;
    }

    Rect clip { this->m_impl->horizontal_position + this->m_impl->frame * 
                     this->m_impl->width, this->m_impl->vertical_position,
                     this->m_impl->width, this->m_impl->height
              };

    Environment *env = Environment::get_instance();
    env->canvas->draw(this->m_impl->texture.get(), clip, horizontal_position, vertical_position, clip.width(), clip.height());
}

double
Animation::width() const
{
    return this->m_impl->width;
}

double
Animation::height() const
{
    return m_impl->height;
}

void
Animation::set_row(int row)
{
    int vertical_position = row*m_impl->height;

    if (m_impl->vertical_position != vertical_position)
    {
        m_impl->frame = 0;
    }

    m_impl->vertical_position = vertical_position;
}

void
Animation::reset()
{
    m_impl->reset();
}
