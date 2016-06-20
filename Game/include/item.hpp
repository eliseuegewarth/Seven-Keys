#ifndef ITEM_H
#define ITEM_H

#include <core/image.h>
#include <string>

using namespace std;

class Item : public Image
{
public:
    Item(Object *parent, ObjectID id, const string& path, double x,
     double y, double mass, bool walkable);
};

#endif
