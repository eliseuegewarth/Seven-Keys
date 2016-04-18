#Quadtree

##Quadtree::Quadtree(int pLevel, Rect * pBounds)
	·m_level = pLevel;
	·m_bounds = pBounds;

##void Quadtree::clear()
	·m_objects.clear();

##void Quadtree::split()
	·int subWidth
   	·int subHeight
   	·int x
   	·int y

##int Quadtree::getIndex(Object * pRect)
   	·int index = -1;
   	·double verticalMidpoint = m_bounds->x() + (m_bounds->w() / 2);
   	·double horizontalMidpoint = m_bounds->y() + (m_bounds->h() / 2);

   	·bool topQuadrant = (pRect->y() < horizontalMidpoint && pRect->y() + pRect->h() < horizontalMidpoint);
   	·bool bottomQuadrant = (pRect->y() > horizontalMidpoint);

##void Quadtree::insert(Object *pRect) {
   	·int index = getIndex(pRect);
 	·int i = 0;
    ·int index = getIndex(m_objects.at(i));

##Quadtree::retrieve(list<Object*> returnObjects, Object* pRect) {
   	·int index = getIndex(pRect);

##class Quadtree
    ·Quadtree(int pLevel, Rect *pBounds);
    ·~Quadtree();
     ·void clear();
     ·void split();
     ·int getIndex(Object *rect);
     ·void insert(Object *rect);
     ·list<Object*> retrieve(list<Object*> returnObj, Object *rect);

 	·int MAX_OBJECTS = 5;
 	·int MAX_LEVELS = 10;
 	·int m_level;
 	
