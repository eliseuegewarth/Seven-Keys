/*
 * Classe que representa um objeto do mundo do jogo.
 *
 * Autor: Edson Alves
 * Data: 20/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef OBJECT_H
#define OBJECT_H

#include <list>
#include <string>
#include <memory>

using std::list;
using std::string;
using std::unique_ptr;

class Rect;

typedef string ObjectID;
typedef string ActionID;
typedef string MessageID;
typedef string Parameters;

class Object
{
public:
    Object(Object *parent = nullptr, ObjectID id = "", double horizontal_position = 0,
        double vertical_position = 0, double width = 1, double height = 1);
    virtual ~Object();

    Object * parent() const;
    const list<Object *>& children() const;
    ObjectID id() const;

    double horizontal_position() const;
    double vertical_position() const;
    double width() const;
    double height() const;

    const Rect& bounding_box() const;

    bool visible() const;

    void set_horizontal_position(double horizontal_position);
    void set_vertical_position(double vertical_position);
    void set_width(double width);
    void set_height(double height);

    void set_visible(bool visible = true);

    bool walkable();
    double mass();

    void set_walkable(bool walkable = true);
    void set_mass(double mass);

    void set_position(double horizontal_position, double vertical_position);
    void set_dimensions(double width, double height);
    void set_parent(Object *parent);

    typedef enum { NONE, LEFT, CENTER, RIGHT, TOP, MIDDLE, BOTTOM }
        Alignment;

    void align_to(const Object* object, Alignment horizontal_axis, Alignment vertical_axis);

    void add_child(Object *child);
    void remove_child(Object *child);

    bool send_message(Object *receiver, MessageID id, Parameters parameters);
    virtual bool on_message(Object *sender, MessageID id, Parameters p);

    void add_observer(Object *observer);
    void remove_observer(Object *observer);

    void notify(ActionID action, Parameters parameters);

    void update(unsigned long elapsed);
    void draw();

private:
    class Impl;
    unique_ptr<Impl> m_impl;

    virtual void update_self(unsigned long elapsed);
    virtual void draw_self();
};

#endif
