#ifndef ROOM_H
#define ROOM_H

#include "core/object.hpp"
#include "core/rect.hpp"
#include <list>

#include "item.hpp"
#include "guard.hpp"
#include "ghost.hpp"
#include "quadtree.hpp"
#include <cmath>

#define INFINITE 99999.9

using std::list;

class Guard;

class Room: public Object
{
public:
	Room(Object *parent, ObjectID id, string type = "None",
		Room *left = nullptr, Room *top = nullptr,
		Room *right = nullptr, Room *bottom = nullptr, int stage_id = 1);

	~Room();

	Room *room_in_left;
	Room *room_in_right;
	Room *room_in_top;
	Room *room_in_bottom;

	string type;
	int stage_id;
	int vertical_position;
	int horizontal_position;

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

    void add_door(string type, char direction, int horizontal_position, int vertical_position);
    void pre_drawing(const string item_name, string item_type, int percentage,
    				int horizontal_position, int vertical_position, int width, int height, bool walkable);

    void fill_floor(const string& name);
    void add_walls(const string& name);
    void add_corners(const string& name);
    void add_guard(const string& name);
    void add_ghost(const string& name);
    void add_items(int stage_id);
    void notify_creation(const string& position);
    void add_final_door();


    bool place(Object *object, double horizontal_position, double vertical_position);
};

#endif
