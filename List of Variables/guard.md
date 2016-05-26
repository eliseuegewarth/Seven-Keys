#Guard

##```class Guard : public Object```
This class describes the attributes and behaviors of the guard
###Class Members
```c++
·typedef enum { NONE, IDLE, RUNNING } State;
```
Define the states of ghost guard
```c++
·typedef enum { MOVED, STOPPED } Event;
```
Sets the event that the ghost guard is currently
```c++
·typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;
```
Sets the direction that the ghost guard will move
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
Position that the player is in this moment(on axis x), used to make the guard move in that direction
```c++
·int player_posy;
```
Position that the player is in this moment(on axis y), used to make the guard move in that direction
```c++
·double m_damage;
```
Damage of the Guard
```c++
·double m_health;
```
Health of the Guard
```c++
·unique_ptr<Animation> m_animation;
```
Animation of the guard
```c++
·Direction m_direction;
```
Direction that the guard is moving
```c++
·unsigned long m_last;
```
Last time that updated the direction

##```ActionID Guard::removeGuardID```
##```ActionID Guard::walkID```

##```Guard::Guard()```
Loads the guard information in the game
###Parameters
```c++
Object *parent
```
The parent is the map object that will contains the ghost guard.
```c++
ObjectID id
```
identifier of object
```c++
double x
```
Guard position on the map in the axis x(horizontal)
```c++
double y
```
Guard position on the map in the axis y(vertical)
```c++
bool walkable
```
Defines if the ghost guard is an object able to walk
```c++
int mass
```
Contains mass information of the guard object
```c++
string t
```
```c++
int dir
```
Defines the initial direction of moviment

##```Guard::~Guard()```
Destructor of the ghost guard

##```Guard::direction()```
Just returns informations of m_direction.

##```void Guard::update_vision()```
```c++
·const list<Object * > filhos
```
```c++
·Sight * visao
```

##```void Guard::set_direction()```
Modifies the movement direction
###Parameters
```c++
Direction direction
```
The value of the direction that will be setted.

##```void Guard::draw_self()```
Draws the animation of ghost guard on screen.

##```void Guard::walk()```
Walk to the player's position at a constant speed.
###Parameters
```c++
unsigned long elapsed
```
Elapsed time since the game start. This parameter is not used here.

###Variables
```c++
·double speed;
```
Define the guard walking speed.
```c++
·Environment * env = Environment::get_instance();
```

##```void Guard::update_direction()```
Update direction of the movement of the guard
###Parameters
```c++
unsigned long elapsed
```
Elapsed time since the game start. This parameter is not used here.

##```void Guard::get_playerx()```
Receive the player's horizontal position. This information is used at Guard artificial intelligence.
###Parameters
```c++
int pos_x
```
That's the player's horizontal position.

##```void Guard::get_playery()```
Receive the player's vertical position. This information is used at Guard artificial intelligence.
###Parameters
```c++
int pos_y
```
That's the player's vertical position.

##```double Guard::damage()```
Returns the ghost guard attack damage value.

##```void Guard::update_self()```
Updates the ghost guard position on the map and walk.
###Parameters
```c++
unsigned long elapsed
```
Elapsed time since the game start. This parameter is not used here.

##```void Guard::change_animation()```
It is the animation of the ghost guard that will be loaded on the screen.
###Parameters
```c++
string path
```

##```double Guard::health()```
Returns the ghost guard health value.

##```string Guard::type()```
Returns the type of the guard

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
