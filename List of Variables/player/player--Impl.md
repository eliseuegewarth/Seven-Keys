#Class Player::Impl
---Comment---
##public:
###```Impl(Player *player, bool key)```
---Comment---
####Parameters
#####```Player *player```
---Comment---
#####```bool key```
---Comment---
--
###```int m_sanity_loss```
---Comment---
--
###```Direction direction() const```
---Comment---
--
###```void set_direction(Direction direction)```
---Comment---
####Parameters
#####```Direction direction```
---Comment---
--

###```const pair<double, double>& moviment() const```
---Comment---
--

###```void set_moviment(double xaxis, double yaxis)```
---Comment---
####Parameters
#####```double xaxis```
---Comment---
#####```double yaxis```
---Comment---
--
###```void set_current(string nova, int posx, int posy)```
---Comment---
####Parameters
#####```string nova```
---Comment---
#####```int posx```
---Comment---
#####```int posy```
---Comment---
--
###```void set_strength(double strength)```
---Comment---
####Parameters
#####```double strength```
---Comment---
--
###```double strength()```
---Comment---
--
###```void set_health(double health)```
---Comment---
####Parameters
#####```double health```
---Comment---
--
###```double health()```
---Comment---
--
###```void set_sanity(double sanity)```
---Comment---
####Parameters
#####```double sanity```
---Comment---
--
###```double sanity()```
---Comment---
--
###```double stamina()```
---Comment---
--
###```void set_stamina(double stamina)```
---Comment---
####Parameters
#####```double stamina```
---Comment---
--
###```double damage()```
---Comment---
--
###```void get_pill(string id)```
---Comment---
####Parameters
#####```string id```
---Comment---
####Variables
#####```const list<Object *> items```
---Comment---
#####```Environment *env```
---Comment---
#####```char path[256]```
---Comment---
#####```Item* pill```
---Comment---
--
###```void get_weapon(string weapon_id)```
---Comment---
####Parameters
#####```string weapon_id```
---Comment---
####Variables
#####```Environment *env```
---Comment---
#####```double size```
---Comment---
#####```char weapon_path[256]```
---Comment---
#####```Item* lWeapon```
---Comment---
#####```Weapon* weapon```
---Comment---
--
###```void get_key()```
---Comment---
####Variables
#####```Environment *env```
---Comment---
#####```Item* key```
---Comment---
--
###```void set_key(bool input)```
---Comment---
####Parameters
#####```bool input```
---Comment---
--
###```bool has_key()```
---Comment---
--
###```void show_health()```
---Comment---
####Variables
#####```Environment *env```
---Comment---
#####```Rect healthbar```
---Comment---
#####```Rect borda```
---Comment---
--

###```void show_sanity()```
---Comment---
####Variables
#####```Environment *env```
---Comment---
#####```Rect sanitybar```
---Comment---
#####```Rect borda```
---Comment---
--

###```void show_stamina()```
---Comment---
####Variables
#####```Environment *env```
---Comment---
#####```double stamina```
---Comment---
#####```Rect staminabar```
---Comment---
#####```Rect borda```
---Comment---
--

###```void show_inventory()```
---Comment---
####Variables
#####```Environment *env```
---Comment---
#####```double size```
---Comment---
#####```Rect item1```
---Comment---
#####```Rect item2```
---Comment---
#####```Rect item3```
---Comment---
#####```Rect item4```
---Comment---
#####```Rect not_item```
---Comment---
--

###```void use_pill()```
---Comment---
####Variables
#####```double recover```
---Comment---
#####```const list<Object *> items```
---Comment---
#####```auto item```
---Comment---
--

###```void use_weapon()```
---Comment---
--

###```void take_item()```
---Comment---
--

###```void jump_level()```
---Comment---
--

###```void open_door()```
---Comment---
--

###```void push_item()```
---Comment---
--

###```void you_died()```
---Comment---
--

###```void hit()```
---Comment---
####Variables
#####```char message[256]```
---Comment---
#####```double dmg_total```
---Comment---
#####```const list<Object *> filhos```
---Comment---
#####```auto filho```
---Comment---
#####```Sight *visao```
---Comment---
--

###```int life()```
---Comment---
--

##Private:
###```Player *m_player```
---Comment---
--
###```Direction m_direction```
---Comment---
--
###```pair<double, double> m_moviment```
---Comment---
--
###```bool m_key```
---Comment---
--
###```double m_strength```
---Comment---
--
###```double m_health```
---Comment---
--
###```double m_sanity```
---Comment---
--
###```double m_stamina```
---Comment---
--
###```int m_pill```
---Comment---
--
###```bool m_hweapon```
---Comment---
--
###```Weapon* m_weapon```
---Comment---
--
###```bool m_secondary```
---Comment---
--
###```double m_damage```
---Comment---
--
###```int m_life```
---Comment---
--
