#ifndef SIGHT_H
#define SIGHT_H

#include <core/object.h>
#include <core/rect.h>
#include <string>

using namespace std;

class Sight : public Object
{
public:
    Sight(Object *parent, ObjectID id, double x, double y, double w, double h);
    ~Sight();

private:
    void draw_self();
    void update_self();
};

#endif