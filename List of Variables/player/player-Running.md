#Class Running : public SpriteState
---Comment---
##Public:
###```Running(Player *player, bool key)```
---Comment---
####Parameters
#####```Player *player```
---Comment---
#####```bool key```
---Comment---
--
###```~Running()```
---Comment---
--

###```const double m_speed```
---Comment---
--

###```void enter(int from)```
---Comment---
####Parameters
#####```int from```
---Comment---
####Variables
#####```Player::Direction dir```
---Comment---
#####```auto moviment```
---Comment---
#####```double x```
---Comment---
#####```double y```
---Comment---
--

###```void leave(int)```
---Comment---
--

###```void draw()```
---Comment---
--

###```bool on_event(const KeyboardEvent& event)```
---Comment---
####Parameters
#####```const KeyboardEvent& event```
---Comment---
--

###```void update(unsigned long elapsed)```
---Comment---
####Parameters
#####```unsigned long elapsed```
---Comment---
####Variables
#####```double speed```
---Comment---
#####```Player::Direction dir```
---Comment---
#####```int row```
---Comment---
#####```auto moviment```
---Comment---
#####```unsigned long delta```
---Comment---
#####```double x```
---Comment---
#####```double y```
---Comment---
#####```Environment *env```
---Comment---

##Private:
###```Player *m_player```
---Comment---
--
###```unique_ptr<Animation> m_animation```
---Comment---
--
###```short m_left```
---Comment---
--
###```short m_right```
---Comment---
--
###```short m_top```
---Comment---
--
###```short m_down```
---Comment---
--
###```unsigned long m_last```
---Comment---
--
###```bool m_key```
---Comment---
--
###```bool m_running```
---Comment---
--
###```bool m_pushing```
---Comment---
--
