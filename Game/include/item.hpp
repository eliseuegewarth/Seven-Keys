/**
 * item.hpp
 * Class that implements the Item object class.
 * Licença: LGPL. Sem copyright.
 */

#ifndef ITEM_HPP
#define ITEM_HPP

#include "core/image.hpp"
#include <string>

using namespace std;

class Item : public Image
{
public:
    Item(Object *parent, ObjectID id, const string& path, double horizontal_position,
    double vertical_position, double mass, bool walkable);
};

#endif
