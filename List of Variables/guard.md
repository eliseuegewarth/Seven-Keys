#Guard

##```class Guard : public Object```
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
·static ActionID removeGuardID;
```
```c++
·static ActionID walkID;
```
```c++
·string m_old_type;
```
```c++
·string m_type;
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
·double m_health;
```
```c++
·unique_ptr<Animation> m_animation;
```
```c++
·Direction m_direction;
```
```c++
·unsigned long m_last;
```

##```ActionID Guard::removeGuardID```
##```ActionID Guard::walkID```

##```Guard::Guard()```
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
bool walkable
```
```c++
int mass
```
```c++
string t
```
```c++
int dir
```

##```Guard::~Guard()```

##```Guard::direction()```

##```void Guard::update_vision()```
```c++
·const list<Object * > filhos
```
```c++
·Sight * visao
```

##```void Guard::set_direction()```
###Parameters
```c++
Direction direction
```
##```void Guard::draw_self()```

##```void Guard::walk()```
###Parameters
```c++
unsigned long elapsed
```
###Variables
```c++
·double speed = 1;
```
```c++
·Environment * env = Environment::get_instance();
```


##```void Guard::update_direction()```
###Parameters
```c++
unsigned long elapsed
```

##```void Guard::get_playerx()```
###Parameters
```c++
int pos_x
```


##```void Guard::get_playery()```
###Parameters
```c++
int pos_y
```

##```double Guard::damage()```

##```void Guard::update_self()```
###Parameters
```c++
unsigned long elapsed
```


##```void Guard::change_animation()```
###Parameters
```c++
string path
```

##```double Guard::health()```

##```string Guard::type()```

##```string Guard::old_type()```

##```void Guard::set_type()```
###Parameters
```c++
string t
```

##```void Guard::set_old_type()```
###Parameters
```c++
string t
```

##```void Guard::receive_dmg()```
###Parameters
```c++
double dmg
```
