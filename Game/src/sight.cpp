#include <cassert>
#include <iostream>
#include <core/animation.h>
#include <core/environment.h>

#include "sight.h"

Sight::Sight(Object *parent, ObjectID id, double x, double y, double w, double h)
{
    assert((parent != NULL) && "Parent can't be NULL");
    assert((not id.empty()) && "Id can't be empty");
    Object(parent, id, x, y, w, h);
}

Sight::~Sight()
{
}

//Alterar
void
Sight::draw_self()
{

}

void
Sight::update_self()
{
    set_x(this->x());
    set_y(this->y());
}
