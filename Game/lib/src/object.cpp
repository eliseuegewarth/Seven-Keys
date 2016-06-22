/*
 * Implementação da classe que representa um objeto do mundo do jogo.
 *
 * Autor: Edson Alves
 * Data: 20/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/object.hpp"
#include "core/rect.hpp"

#include <list>

using std::list;

class Object::Impl
{
public:
    Impl(Object *base, Object *parent, ObjectID id, double horizontal_position, double vertical_position,
        double width, double height)
        : m_base(base), m_parent(parent), m_id(id), m_box(horizontal_position, vertical_position, width, height),
        m_visible(true), m_walkable(true), m_mass(0.0)
    {
    }

    ~Impl()
    {
        if (m_parent)
        {
            m_parent->remove_child(m_parent);
        }

        while (not m_children.empty())
        {
            Object *child = m_children.back();
            m_children.pop_back();
            delete child;
        }
    }

    Object * parent() const
    {
        return m_parent;
    }

    const list<Object *>& children() const
    {
        return m_children;
    }

    ObjectID id() const
    {
        return m_id;
    }

    void align_to(const Object* object, Alignment horizontal_axis, Alignment vertical_axis)
    {
        if (not object)
        {
            return;
        }

        double horizontal_position = m_box.horizontal_position();

        switch (horizontal_axis)
        {
        case LEFT:
            horizontal_position = object->horizontal_position();
            break;

        case CENTER:
            horizontal_position = (object->width() - m_box.width())/2 + object->horizontal_position();
            break;

        case RIGHT:
            horizontal_position = object->width() - m_box.width() + object->horizontal_position();
            break;

        default:
            break;
        }

        double vertical_position = m_box.vertical_position();

        switch (vertical_axis)
        {
        case TOP:
            vertical_position = object->vertical_position();
            break;

        case MIDDLE:
            vertical_position = (object->height() - m_box.height())/2 + object->vertical_position();
            break;

        case BOTTOM:
            vertical_position = object->height() - m_box.height() + object->vertical_position();
            break;

        default:
            break;
        }

        m_box.set_position(horizontal_position, vertical_position);
        m_base->set_position(horizontal_position, vertical_position);
    }

    void add_child(Object *child)
    {
        if (child)
        {
            m_children.push_back(child);
            child->set_parent(m_parent);
        }
    }

    void remove_child(Object *child)
    {
        m_children.remove(child);
    }

    bool send_message(Object *receiver, MessageID id, Parameters parameters)
    {
        if (receiver)
        {
            return receiver->on_message(m_base, id, parameters);
        }

        return false;
    }

    void add_observer(Object *observer)
    {
        if (observer)
        {
            m_observers.push_back(observer);
        }
    }

    void remove_observer(Object *observer)
    {
        m_observers.remove(observer);
    }

    void notify(ActionID action, Parameters parameters)
    {
        for (auto observer : m_observers)
        {
            if (send_message(observer, action, parameters))
            {
                break;
            }
        }
    }

    void update(unsigned long elapsed)
    {
        for (auto child : m_children)
        {
            child->update(elapsed);
        }

        m_base->update_self(elapsed);
    }

    void draw()
    {
        if (not visible())
        {
            return;
        }

        m_base->draw_self();

        for (auto child : m_children)
        {
            child->draw();
        }
    }

    const Rect& bounding_box() const
    {
        return m_box;
    }

    double horizontal_position() const
    {
        return m_box.horizontal_position();
    }

    double vertical_position() const
    {
        return m_box.vertical_position();
    }

    double width() const
    {
        return m_box.width();
    }

    double height() const
    {
        return m_box.height();
    }

    void set_horizontal_position(double horizontal_position)
    {
        m_box.set_horizontal_position(horizontal_position);
    }

    void set_vertical_position(double vertical_position)
    {
        m_box.set_vertical_position(vertical_position);
    }

    void set_width(double width)
    {
        m_box.set_width(width);
    }

    void set_height(double height)
    {
        m_box.set_height(height);
    }


    void set_position(double horizontal_position, double vertical_position)
    {
        m_box.set_position(horizontal_position, vertical_position);
    }

    void set_dimensions(double width, double height)
    {
        m_box.set_dimensions(width, height);
    }

    void set_parent(Object *parent)
    {
        m_parent = parent;
    }

    bool visible() const
    {
        return m_visible;
    }

    void set_visible(bool visible)
    {
        m_visible = visible;
    }

    void set_walkable(bool walkable)
    {
        m_walkable = walkable;
    }

    bool walkable() const
    {
        return m_walkable;
    }

    void set_mass(double mass)
    {
        m_mass = mass;
    }

    double mass() const
    {
        return m_mass;
    }

private:
    Object *m_base;
    Object *m_parent;
    ObjectID m_id;
    Rect m_box;
    bool m_visible;
    bool m_walkable;
    double m_mass;

    list<Object *> m_children;
    list<Object *> m_observers;
};

Object::Object(Object *parent, ObjectID id, double horizontal_position, double vertical_position, double width,
    double height) : m_impl(new Object::Impl(this, parent, id, horizontal_position, vertical_position, width, height))
{
}

Object::~Object()
{
}

Object *
Object::parent() const
{
    return m_impl->parent();
}

ObjectID
Object::id() const
{
    return m_impl->id();
}

double
Object::horizontal_position() const
{
    return m_impl->horizontal_position();
}

double
Object::vertical_position() const
{
    return m_impl->vertical_position();
}

double
Object::width() const
{
    return m_impl->width();
}

double
Object::height() const
{
    return m_impl->height();
}

const Rect&
Object::bounding_box() const
{
    return m_impl->bounding_box();
}

void
Object::set_horizontal_position(double horizontal_position)
{
    m_impl->set_horizontal_position(horizontal_position);
}

void
Object::set_vertical_position(double vertical_position)
{
    m_impl->set_vertical_position(vertical_position);
}

void
Object::set_width(double width)
{
    m_impl->set_width(width);
}

void
Object::set_height(double height)
{
    m_impl->set_height(height);
}

void
Object::set_position(double horizontal_position, double vertical_position)
{
    m_impl->set_position(horizontal_position, vertical_position);
}

void
Object::set_dimensions(double width, double height)
{
    m_impl->set_dimensions(width, height);
}

void
Object::set_parent(Object *parent)
{
    m_impl->set_parent(parent);
}

void
Object::add_child(Object *child)
{
    m_impl->add_child(child);
}

void
Object::remove_child(Object *child)
{
    m_impl->remove_child(child);
}

bool
Object::send_message(Object *receiver, MessageID id, Parameters parameters)
{
    return m_impl->send_message(receiver, id, parameters);
}

bool
Object::on_message(Object *, MessageID, Parameters)
{
    return false;
}

void
Object::add_observer(Object *observer)
{
    m_impl->add_observer(observer);
}

void
Object::remove_observer(Object *observer)
{
    m_impl->remove_observer(observer);
}

void
Object::notify(ActionID action, Parameters parameters)
{
    m_impl->notify(action, parameters);
}

void
Object::update(unsigned long elapsed)
{
    m_impl->update(elapsed);
}

void
Object::draw()
{
    m_impl->draw();
}

void
Object::update_self(unsigned long)
{
}

void
Object::draw_self()
{
}

void
Object::align_to(const Object* object, Alignment horizontal_axis, Alignment vertical_axis)
{
    m_impl->align_to(object, horizontal_axis, vertical_axis);
}

bool
Object::visible() const
{
    return m_impl->visible();
}

void
Object::set_visible(bool visible)
{
    m_impl->set_visible(visible);
}

void
Object::set_walkable(bool walkable)
{
    m_impl->set_walkable(walkable);
}

void
Object::set_mass(double mass)
{
    m_impl->set_mass(mass);
}

bool
Object::walkable()
{
    return m_impl->walkable();
}

double
Object::mass()
{
    return m_impl->mass();
}

const list<Object *>&
Object::children() const
{
    return m_impl->children();
}
