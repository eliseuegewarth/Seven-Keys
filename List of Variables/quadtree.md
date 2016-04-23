#Quadtree


##```class Quadtree```
###Variables
```c++
·list<Object*> retrieve
```
```c++
·int MAX_OBJECTS
```
```c++
·int MAX_LEVELS
```
```c++
·int m_level;
```

##```Quadtree::Quadtree()```
###Parameters
```c++
int pLevel
```
```c++
Rect * pBounds
```
##```void Quadtree::clear()```
```c++
·m_objects.clear();
```
##```void Quadtree::split()```
```c++
·int subWidth
```
```c++
·int subHeight
```
```c++
·int x
```
```c++
·int y
```

##```int Quadtree::getIndex()```
###Parameters
```c++
Object * pRect
```
###Variables
```c++
int index
```
```c++
double verticalMidpoint
```
```c++
double horizontalMidpoint
```
```c++
bool topQuadrant
```
```c++
bool bottomQuadrant
```

##```void Quadtree::insert()```
###Parameters
```c++
Object *pRect
```
###Variables
```c++
·int index = getIndex(pRect);
```
```c++
·int i = 0;
```
```c++
·int index = getIndex(m_objects.at(i));
```

##```Quadtree::retrieve()```
###Parameters
```c++
list<Object*> returnObjects
```
```c++
Object* pRect
```
###Variables
```c++
int index
```
