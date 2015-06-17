#ifndef MAP_H
#define MAP_H


#include <core/object.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <utility>

#include "room.h"


using std::pair;
using std::list;
using std::vector;

class Map: public Object
{
public:
	Map(int qut_salas);

    enum Position {LEFT = 1, RIGHT = 2, TOP = 3, BOTTOM = 4};
	Room * current_room;
	Room * room();


	void set_current(Room *room);
	void GenerateMap(int);
	void remove_item(Object* );
	
    const list<Object *>& itens() ;

private:
	vector <Room*> room_list;
	Room * last_room;
    bool **matriz;
	void CreateRoom(Room *, int*, int, int, int);
	void draw_self();
    void update_self(unsigned long);
};
#endif