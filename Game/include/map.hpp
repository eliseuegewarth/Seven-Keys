#ifndef MAP_H
#define MAP_H


#include "core/object.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <utility>
#include <cassert>

#include "room.hpp"
#include "boss.hpp"
#include "stage.hpp"


using std::pair;
using std::list;
using std::vector;

class Map: public Object
{
public:
	Map(int qut_salas, int stage_id);

    enum Position {LEFT = 1, RIGHT = 2, TOP = 3, BOTTOM = 4};
	Room * current_room;
	Room * room();

	Boss * boss() { return m_boss;}


	void set_current(Room *room);
	void GenerateMap(int, int);
	void remove_item(Object* );

    const list<Object *>& items() ;

    Boss * m_boss;
private:
	vector <Room*> room_list;
	Room * last_room;

	double last_summon;

    bool **matriz;
	void CreateRoom(Room *, int*, int, int, int, int);
	bool on_message(Object *object, MessageID id, Parameters p);
	// void draw_self();
 	void update_self(unsigned long);
};
#endif
