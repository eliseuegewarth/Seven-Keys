# ```Class Boss : public Object```
---comment---
##Public:
###```typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction```

---comment---
--
###```Boss(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, int dir)```
####Parameters
#####```Object *parent```
---comment---
#####```ObjectID id```
---comment---
#####```double x```
---comment---
#####```double y```
---comment---
#####```int mass```
---comment---
#####```bool walkable```
---comment---
#####```int dir```
---comment---
--
###```~Boss()```
---comment---
--
###```Direction direction()```
---comment---
--
###```void get_playerx(int pos_x)```
---comment---
####Parameters
#####```int pos_x```
---comment---
--
###```void get_playery(int pos_y)```
---comment---
####Parameters
#####```int pos_y```
---comment---
--
###```void set_direction(Direction direction)```
---comment---
####Parameters
#####```Direction direction```
---comment---
--
###```void update_vision()```
---comment---
--
###```void walk()```
---comment---
####Variables
#####```double speed```
---comment---
--
###```void update_direction(unsigned long elapsed)```
---comment---
####Parameters
#####```unsigned long elapsed```
---comment---
--
###```void set_position(double x, double y)```
---comment---
####Parameters
#####```double x```
---comment---
#####```double y```
---comment---
--
###```bool summoned()```
---comment---
--
###```bool created()```
---comment---
--
###```void set_summoned(bool t)```
---comment---
####Paramenters
#####```bool t```
---comment---
--
###```void set_created(bool t)```
---comment---
####Paramenters
#####```bool t```
---comment---
--
###```double damage()```
---comment---
--
##Private:
###```int player_posx```
---comment---
--
###```int player_posy```
---comment---
--
###```double m_damage```
---comment---
--
###```bool m_summoned```
---comment---
--
###```bool m_created```
---comment---
--
###```void draw_self()```
---comment---
--
###```void update_self(unsigned long elapsed)```
####Parameters
#####```unsigned long elapsed```
---comment---
--
###```unique_ptr<Animation> m_animation```
---comment---
--
###```Direction m_direction```
---comment---
--
###```unsigned long m_last```
---comment---
