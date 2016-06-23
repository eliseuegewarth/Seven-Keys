#include <cassert>
#include <iostream>
#include <core/animation.hpp>
#include <core/environment.hpp>

#include "sight.hpp"
/**
 * [Sight::Sigth description]
 * @param *parent [The parent is the map Object that will contains the boss.]
 * @param id [Identifier of Object]
 * @param horizontal_position [Position on the map in the axis x(horizontal)]
 * @param vertical_position [Position on the map in the axis y(vertical)]
 * @param w [Width of the screen]
 * @param h [Height of the screen]
 * @method Sight::Sight
 */
Sight::Sight(Object *parent, ObjectID id, double horizontal_position, double vertical_position, double width, double height)
{
    assert((parent != NULL) && "Parent can't be NULL");
    assert((not id.empty()) && "Id can't be empty");
    Object(parent, id, horizontal_position,vertical_position, width, height);
}

Sight::~Sight()
{
}

void Sight::draw_self()
{

}

void Sight::update_self()
{
    set_horizontal_position(this->horizontal_position());
    set_vertical_position(this->vertical_position());
}
