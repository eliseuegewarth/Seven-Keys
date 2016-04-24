#Ghost

##```class Ghost : public Object```
###Class Members
```c++
·typedef enum { NONE, IDLE, RUNNING } State;
```
```c++
·typedef enum { MOVED, STOPPED } Event;
```
```c++
·typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;
```
```c++
·string type;
```
```c++
·int player_posx;
```
```c++
·int player_posy;
```
```c++
·double m_damage;
```
```c++
·unique_ptr<Animation> m_animation;
```
```c++
·Direction m_direction;
```
```c++
·unsigned long m_last = 0;
```

##```Ghost::Ghost()```
###Parameters
```c++
Object *parent
```
```c++
ObjectID id
```
```c++
double x
```
```c++
double y
```
```c++
int mass
```
```c++
bool walkable
```
```c++
string t
```
```c++
int dir
```

##```Ghost::~Ghost()```

##```Ghost::direction()```

##```void Ghost::update_vision()```

##```void Ghost::set_direction()```
###Parameters
```c++
Direction direction
```
##```void Ghost::draw_self()```

##```void Ghost::walk()```
###Variables
```c++
·double speed = 0.6;
```

##```void Ghost::update_direction()```
###Parameters
```c++
unsigned long elapsed
```
###Variables
```c++
·int random = rand()%100;
```

##```void Ghost::get_playerx()```
###Parameters
```c++
int pos_x
```

##```void Ghost::get_playery()```
###Parameters
```c++
int pos_y
```

##```double Ghost::damage()```

##```void Ghost::update_self()```
###Parameters
```c++
unsigned long elapsed
```

##void Ghost::change_animation()
###Parameters
```c++
string path
```
