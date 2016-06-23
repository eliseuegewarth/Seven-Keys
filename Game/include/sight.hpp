#ifndef SIGHT_H
#define SIGHT_H

#include "core/object.hpp"
#include "core/rect.hpp"
#include <string>

using namespace std;

class Sight : public Object
{
public:
    Sight(Object *parent, ObjectID id, double horizontal_position, double vertical_position, double width, double height);
    ~Sight();

private:
    void draw_self();
    void update_self();
};

#endif
