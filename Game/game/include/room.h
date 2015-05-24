#ifndef ROOM_H
#define ROOM_H

#include <core/object.h>

class Room: public Object
{
public:
	Room(Object *parent, ObjectID id);

	Room *r_left;
	Room *r_right;
	Room *r_top;
	Room *r_botton;

	void check_entry();
private:
	//bool hasMap;

	void draw_self();
};

#endif