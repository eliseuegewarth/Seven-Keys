#Class Duck : public SpriteState
---Comment---
##Public:
###```Duck(Player *player)```
---Comment---
####Parameters
#####```Player *player```
---Comment---
--
###```~Duck()```
---Comment---
--

###```void enter(int)```
---Comment---
--
###```void leave(int)```
---Comment---
--
###```bool on_event(const KeyboardEvent& event)```
---Comment---
####Parameters
#####```const KeyboardEvent& event```
---Comment---
####Variables
#####```Player::Direction dir```
---Comment---
#####```int row```
---Comment---
--
##Private:
###```int Player *m_player```
---Comment---
--
###```int unique_ptr<Animation> m_animation```
---Comment---
--
###```int m_left```
---Comment---
--
###```int m_right```
---Comment---
--
###```int m_top```
---Comment---
--
###```int m_down```
---Comment---
--
