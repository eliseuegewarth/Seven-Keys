#ifndef ITEM_H
#define ITEM_H

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
