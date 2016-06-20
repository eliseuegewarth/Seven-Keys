/*
 * Implementation of the Sprite class.
 * Licença: LGPL. Sem copyright.
 */
#include "core/rect.hpp"
#include "core/sprite.hpp"
#include "core/keyboardevent.hpp"
#include "core/environment.hpp"

using std::make_pair;

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param sprite [description]
 * @param d [description]
 * @param e [description]
 * @return [description]
 */
class Sprite::Impl
{
public:
    Impl(Sprite *sprite)
        : m_sprite(sprite), m_state_id(0), m_state(nullptr)
    {
    }

    ~Impl()
    {
    }

    void report_event(int event)
    {
        auto it = m_fsm.find(make_pair(m_state_id, event));

        if (it == m_fsm.end())
        {
            return;
        }

        int next = it->second;

        change_state(next, m_state_id);
    }

    void change_state(int to, int from)
    {
        auto it = m_states.find(to);

        if (it == m_states.end())
        {
            return;
        }

        if (m_state)
        {
            m_state->leave(to);
        }

        m_state_id = to;
        m_state = it->second;

        if (m_state)
        {
            m_state->enter(from);
        }
    }

    void add_state(int id, SpriteState *state)
    {
        m_states[id] = state;
    }

    void add_transition(int event, int from, int to)
    {
        m_fsm[make_pair(from, event)] = to;
    }

    void update_self(unsigned long elapsed)
    {
        if (m_state)
        {
            m_state->update(elapsed);
        }
    }

    void draw_self()
    {
        if (m_state)
        {
            m_state->draw();
        }
    }

    SpriteState * state() const
    {
        return m_state;
    }

    bool on_event(const KeyboardEvent& event)
    {
        if (m_state)
        {
            return m_state->on_event(event);
        }

        return false;
    }

    bool on_event(const MouseButtonEvent& event)
    {
        if (m_state)
        {
            return m_state->on_event(event);
        }

        return false;
    }

    bool on_event(const MouseMotionEvent& event)
    {
        if (m_state)
        {
            return m_state->on_event(event);
        }

        return false;
    }

    bool on_event(const JoyStickEvent& event)
    {
        if (m_state)
        {
            return m_state->on_event(event);
        }

        return false;
    }

private:
    Sprite *m_sprite;
    int m_state_id;
    SpriteState *m_state;
    map< pair<int, int>, int > m_fsm;
    map<int, SpriteState *> m_states;
};

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param parent [description]
 * @param id [description]
 * @param d [description]
 * @param l [description]
 */
Sprite::Sprite(Object *parent, ObjectID id)
    : Object(parent, id), m_impl(new Impl(this))
{
}

Sprite::~Sprite()
{
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param event [description]
 */
void Sprite::report_event(int event)
{
    m_impl->report_event(event);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param to [description]
 * @param from [description]
 */
void Sprite::change_state(int to, int from)
{
    m_impl->change_state(to, from);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param id [description]
 * @param state [description]
 */
void Sprite::add_state(int id, SpriteState *state)
{
    m_impl->add_state(id, state);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param event [description]
 * @param from [description]
 * @param to [description]
 */
void Sprite::add_transition(int event, int from, int to)
{
    m_impl->add_transition(event, from, to);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param long [description]
 */
void Sprite::update_self(unsigned long elapsed)
{
    m_impl->update_self(elapsed);
}

/**
 * @brief [brief description]
 * @details [long description]
 */
void Sprite::draw_self()
{
    m_impl->draw_self();
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
SpriteState * Sprite::state() const
{
    return m_impl->state();
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param event [description]
 * @return [description]
 */
bool Sprite::on_event(const KeyboardEvent& event)
{
    return m_impl->on_event(event);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param event [description]
 * @return [description]
 */
bool Sprite::on_event(const MouseButtonEvent& event)
{
    return m_impl->on_event(event);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param event [description]
 * @return [description]
 */
bool Sprite::on_event(const MouseMotionEvent& event)
{
    return m_impl->on_event(event);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param event [description]
 * @return [description]
 */
bool Sprite::on_event(const JoyStickEvent& event)
{
    return m_impl->on_event(event);
}
