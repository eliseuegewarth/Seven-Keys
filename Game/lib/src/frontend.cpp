/*
 * Implementação da class FrontEnd.
 *
 * Autor: Edson Alves
 * Data: 20/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "util/frontend.hpp"

#include "core/rect.hpp"
#include "core/texture.hpp"
#include "core/environment.hpp"

#include "core/joystickevent.hpp"
#include "core/keyboardevent.hpp"
#include "core/mousebuttonevent.hpp"

class FrontEnd::Impl
{
public:
    Impl(Level *parent, const string& texture, unsigned long duration,
        const Color& background)
        : m_parent(parent), m_texture(nullptr), m_background(background),
        m_fad(), m_start(0), m_duration(duration)
    {
        Environment *env = Environment::get_instance();
        m_texture = env->resources_manager->get_texture(texture);

        m_in = m_duration / 3;
        m_out = m_duration - m_in;
    }

    ~Impl() {}

    bool on_event(const MouseButtonEvent& event)
    {
        if (event.state() == MouseButtonEvent::PRESSED)
        {
            m_parent->finish();
            return true;
        }

        return false;
    }

    bool on_event(const KeyboardEvent& event)
    {
        if (event.state() == KeyboardEvent::PRESSED)
        {
            m_parent->finish();
            return true;
        }

        return false;
    }

    bool on_event(const JoyStickEvent& event)
    {
        if (event.state() == JoyStickEvent::PRESSED)
        {
            m_parent->finish();
            return true;
        }

        return false;
    }

    void update_self(unsigned long elapsed)
    {
        if (not m_start)
        {
            m_start = elapsed;
        }

        unsigned long now = elapsed - m_start;

        if (now <= m_in)
        {
            unsigned char a = (255 * (100 - (100*now)/m_in))/100;
            m_fad.set_a(a);
        } else if (now >= m_out)
        {
            unsigned char a = (255 * (100*(now - m_out))/m_in)/100;
            m_fad.set_a(a);
        } else
        {
            m_fad.set_a(0);
        }

        if (now > m_duration)
        {
            m_parent->finish();
        }

        Environment *env = Environment::get_instance();

        m_horizontal_position = (env->camera->width() - m_texture->width())/2 + env->camera->horizontal_position();
        m_vertical_position = (env->camera->height() - m_texture->height())/2 + env->camera->vertical_position();
    }

    void draw_self()
    {
        Environment *env = Environment::get_instance();

        env->canvas->clear(m_background);
        env->canvas->draw(m_texture.get(), m_horizontal_position, m_vertical_position);

        env->canvas->set_blend_mode(Canvas::BLEND);
        Rect r { 0, 0, (double) env->canvas->width(), (double) env->canvas->height() };
        env->canvas->fill(r, m_fad);
        env->canvas->set_blend_mode(Canvas::NONE);
    }

private:
    Level *m_parent;
    shared_ptr<Texture> m_texture;
    Color m_background, m_fad;
    unsigned long m_start, m_duration;
    unsigned long m_in, m_out;
    int m_horizontal_position, m_vertical_position;
};

FrontEnd::FrontEnd(const string& id, const string& next, const string& texture,
    unsigned long duration, const Color& bg)
        : Level(id, next), m_impl(new Impl(this, texture, duration, bg))
{
    Environment *env = Environment::get_instance();
    env->events_manager->register_listener(this);
}

FrontEnd::~FrontEnd()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);
}

void
FrontEnd::draw_self()
{
    m_impl->draw_self();
}

void
FrontEnd::update_self(unsigned long elapsed)
{
    m_impl->update_self(elapsed);
}

bool
FrontEnd::on_event(const MouseButtonEvent& event)
{
    return m_impl->on_event(event);
}

bool
FrontEnd::on_event(const JoyStickEvent& event)
{
    return m_impl->on_event(event);
}

bool
FrontEnd::on_event(const KeyboardEvent& event)
{
    return m_impl->on_event(event);
}
