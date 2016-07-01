/**
 * quadtree.hpp
 * Class that implements 
 * Licença: LGPL. Sem copyright.
 */

#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <vector>
#include <array>
#include "core/rect.hpp"
#include "core/object.hpp"

using namespace std;
using std::vector;
using std::array;
using std::list;
class Quadtree
{
public:
    Quadtree(int pLevel, Rect *pBounds);
    ~Quadtree();

    void clear();
    void split();
    int getIndex(Object *rect);
    void insert(Object *rect);
    //List of objects to be recovered
    list<Object*> retrieve(list<Object*> returnObj, Object *rect);

private:
	int MAX_OBJECTS = 5; //Maximum number of objects
	int MAX_LEVELS = 10; //Maximum number of levels
	int m_level; //Level to be initialize
	vector <Object *> m_objects;
	array<Quadtree*,4> m_nodes;
	Rect *m_bounds;
};

#endif
