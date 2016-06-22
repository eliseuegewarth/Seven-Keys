#include <iostream>
#include <core/image.hpp>
#include <core/keyboardevent.hpp>
#include <core/environment.hpp>
#include <cassert>

#include "item.hpp"

/**
 * item.cpp
 * @brief [Class that implements item objects from the game]
 * Licença: LGPL. Sem copyright.
 */

Item::Item(Object *parent, ObjectID id, const string& path, double horizontal_position,
 double vertical_position, double mass, bool walkable)
    : Image(parent, id, path)
{
    assert(parent != NULL && "Failed to pick up the instance of Object");

    set_position(horizontal_position, vertical_position);
    set_walkable(walkable);
    set_mass(mass);
}
