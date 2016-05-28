#Ghost

##```class Ghost : public Object```
This class describes the attributes and behaviors of the ghost guard
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
·string type;
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
·unique_ptr<Animation> m_animation;
```
Animation of the ghost guard
```c++
·Direction m_direction;
```
Direction that the guard is moving
```c++
·unsigned long m_last = 0;
```
Last time that updated the direction

##```Ghost::Ghost()```
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
Guard position on the map in the axis x
```c++
double y
```
Guard position on the map in the axis y
```c++
int mass
```
Contains mass information of the guard object
```c++
bool walkable
```
Defines if the ghost guard is an object able to walk
```c++
string t
```
```c++
int dir
```
Defines the initial direction of moviment

##```Ghost::~Ghost()```
Destructor of the ghost guard

##```Ghost::direction()```
Just returns informations of m_direction.

##```void Ghost::update_vision()```
Do nothing

##```void Ghost::set_direction()```
Modifies the movement direction
###Parameters
```c++
Direction direction
```
The value of the direction that will be setted.

##```void Ghost::draw_self()```
Draws the animation of ghost guard on screen.

##```void Ghost::walk()```
Walk to the player's position at a constant speed.
###Variables
```c++
·double speed;
```
Define the ghost guard walking speed.
##```void Ghost::update_direction()```
Updates the sprite of object (ghost guard) based on the ghost guard movement direction.
###Parameters
```c++
unsigned long elapsed
```
Elapsed time since the game start. This parameter is not used here.
###Variables
```c++
·int random;
```

##```void Ghost::get_playerx()```
Receive the player's horizontal position. This information is used at Ghost Guard artificial intelligence.
###Parameters
```c++
int pos_x
```
That's the player's horizontal position.

##```void Ghost::get_playery()```
Receive the player's vertical position. This information is used at Ghost Guard artificial intelligence.
###Parameters
```c++
int pos_y
```
That's the player's vertical position.

##```double Ghost::damage()```
Returns the ghost guard attack damage value.

##```void Ghost::update_self()```
Updates the ghost guard position on the map and walk.
###Parameters
```c++
unsigned long elapsed
```
Elapsed time since the game start.

##```void Ghost::change_animation()```
It is the animation of the ghost guard that will be loaded on the screen.
###Parameters
```c++
string path
```
