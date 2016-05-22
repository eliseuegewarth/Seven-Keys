/*
 * Implementação da classe Animation.
 *
 * Autor: Edson Alves
 * Data: 05/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/animation.h"

#include "core/rect.h"
#include "core/texture.h"
#include "core/environment.h"

#include <cassert>

class Animation::Impl
{
public:
    Impl(const string& id, double x_, double y_, double width_, double height_, int f,
        unsigned long s, bool l_)
    {
        this->x = (x_);
        this->y = (y_);
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

    double x, y, width, height;
    int frames;
    unsigned long speed;
    bool loop, done;
    unsigned long last;
    int frame;
    shared_ptr<Texture> texture;
};

Animation::Animation(const string& texture, double x, double y, double width,
    double height, int frames, unsigned long speed_in_ms, bool loop)
    : m_impl(new Animation::Impl(texture, x, y, width, height, frames, speed_in_ms, loop))
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
            m_impl->done = true;
        }
    }
}

void
Animation::draw(double x, double y)
{
    if (m_impl->done)
    {
        return;
    }

    Rect clip { m_impl->x + m_impl->frame * m_impl->width, m_impl->y, m_impl->width,
        m_impl->height
              };

    Environment *env = Environment::get_instance();
    env->canvas->draw(m_impl->texture.get(), clip, x, y, clip.width(), clip.height());
}

double
Animation::width() const
{
    return m_impl->width;
}

double
Animation::height() const
{
    return m_impl->height;
}

void
Animation::set_row(int row)
{
    int y = row*m_impl->height;

    if (m_impl->y != y)
    {
        m_impl->frame = 0;
    }

    m_impl->y = y;
}

void
Animation::reset()
{
    m_impl->reset();
}
