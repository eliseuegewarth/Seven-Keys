#include <cassert>
#include <iostream>
#include <core/animation.h>
#include <core/environment.h>

#include "sight.hpp"
/**
 * [Sight::Sigth description]
 * @param *parent [The parent is the map Object that will contains the boss.]
 * @param id [Identifier of Object]
 * @param x [Position on the map in the axis x(horizontal)]
 * @param y [Position on the map in the axis y(vertical)]
 * @param w [Width of the screen]
 * @param h [Height of the screen]
 * @method Sight::Sight
 */
Sight::Sight(Object *parent, ObjectID id, double x, double y, double w, double h)
{
    assert((parent != NULL) && "Parent can't be NULL");
    assert((not id.empty()) && "Id can't be empty");
    Object(parent, id, x, y, w, h);
}

Sight::~Sight()
{
}

void Sight::draw_self()
{

}

void Sight::update_self()
{
    set_x(this->x());
    set_y(this->y());
}
