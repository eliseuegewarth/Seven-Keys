# ```Class Boss : public Object```
This class describes the attributes and behaviors of the enemy boss.
##Public:
###```typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction```
Defines the direction in which the boss can move around.
--
###```Boss(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, int dir)```
Loads the information about the boss on the map.
####Parameters
#####```Object *parent```
The parent is the map Object that will contains the boss.
#####```ObjectID id```
Identifier of object type. in case of this class, aways have to be "boss".
#####```double x```
The position in horizontal(x) axis where boss will be placed. 
#####```double y```
The position in vertival(y) axis where boss will be placed. 
#####```int mass```
Contains Object Boss mass information.
#####```bool walkable```
Defines whether the boss is an object able to walk.
#####```int dir```
Sets the initial movement direction.
--
###```~Boss()```
0Destructor of Boss class.
--
###```Direction direction()```
Just returns informations of m_direction.
--
###```void get_playerx(int pos_x)```
Receive the player's horizontal position. This information is used at Boss's artificial intelligence.
####Parameters
#####```int pos_x```
That's the player's horizontal position.
--
###```void get_playery(int pos_y)```
Receive the player's vertical position. This information is used at Boss's artificial intelligence.
####Parameters
#####```int pos_y```
That's the player's vertical position.
--
###```void set_direction(Direction direction)```
Modifies the movement direction.
####Parameters
#####```Direction direction```
The value of the direction that will be setted.
--
###```void update_vision()```
Does not implement any behavior.
--
###```void walk()```
Walk to the player's position at a constant speed.
####Variables
#####```double speed```
Define the boss walking speed.
--
###```void update_direction(unsigned long elapsed)```
Updates the sprite of object (boss) based on the boss movement direction.
####Parameters
#####```unsigned long elapsed```
Elapsed time since the game start. This parameter is not used here.
--
###```void set_position(double x, double y)```
This method defines the boss's position in the room.
####Parameters
#####```double x```
The boss horizontal position.
#####```double y```
The boss vertical position.
--
###```bool summoned()```
Returns true if the boss was summoned at the stage.
--
###```bool created()```
Returns true if the boss was created.
--
###```void set_summoned(bool t)```
Set the m_summoned status with the 't' value.
####Paramenters
#####```bool t```
Contain the summoned state value.
--
###```void set_created(bool t)```
Set the m_created status with the 't' value
####Paramenters
#####```bool t```
Contain the created state value.
--
###```double damage()```
Returns the boss attack damage value.
--
##Private:
###```int player_posx```
The player's horizontal position.
--
###```int player_posy```
The player's vertical position.
--
###```double m_damage```
The boss attack damage value.
--
###```bool m_summoned```
Indicates the summon state of the boss.
--
###```bool m_created```
Indicates the creation state of the boss.
--
###```void draw_self()```
Draws the animation of boss on screen.
--
###```void update_self(unsigned long elapsed)```
Updates the boss's position on the map and walk.
####Parameters
#####```unsigned long elapsed```
Elapsed time since the game start.
--
###```unique_ptr<Animation> m_animation```
It is the animation of the boss that will be loaded on the screen.
--
###```Direction m_direction```
The Boss movement direction.
--
###```unsigned long m_last```
Last game time saved since the start of the game. It's like an old Elapsed time. Is Not used.
