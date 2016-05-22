#ifndef ROOM_H
#define ROOM_H

#include <core/object.h>
#include <core/rect.h>
#include <list>

#include "item.h"
#include "guard.h"
#include "ghost.h"
#include "quadtree.h"
#include <cmath>

#define INFINITE 99999.9

using std::list;

class Guard;

class Room: public Object
{
public:
	Room(Object *parent, ObjectID id, string type = "None", Room *left = nullptr, Room *top = nullptr, Room *right = nullptr, Room *bottom = nullptr, int stage_id = 1);

	~Room();

	Room *r_left;
	Room *r_right;
	Room *r_top;
	Room *r_bottom;

	string type;
	int stage_id;
	int pos_x;
	int pos_y;

	void check_entry();
	string room_type();

	static ActionID guardDeathID;

	list <Object *> items;

	void add_list(Object *);
	const list<Object *>& get_items();
	void remove_item(Object *);

	Quadtree * quad;

private:
	Guard *m_guard;

    bool m_doors;
    Rect center_area;

    void draw_self();
	void draw_id(Room *,Room *, int, int);
	void draw_items(string, string, int, int, int, int, bool);

    void update_self(unsigned long);

    void add_door(string type, char direction, int x, int y);
    void pre_drawing(const string item_name, string item_type, int percentage,
    	int pos_x, int pos_y, int width, int height, bool walkable);

    void fill_floor(const string& name);
    void add_walls(const string& name);
    void add_corners(const string& name);
    void add_guard(const string& name);
    void add_ghost(const string& name);
    void add_items(int stage_id);
    void notify_creation(const string& position);
    void add_final_door();


    bool place(Object *object, double x, double y);
};

#endif
