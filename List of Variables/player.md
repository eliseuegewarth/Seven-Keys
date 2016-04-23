#Class Player : public Sprite

##Public:
###```typedef enum { NONE, IDLE, RUNNING, DUCK } State```
###```typedef enum { MOVED, STOPPED, DUCKING, STANDING } Event```
###```typedef enum { LEFT, UP, RIGHT, DOWN } Direction```
--
###```Player(Object *parent, const string& id)```
####Parameters
#####```Object *parent```
#####```const string& id```
###```~Player()```
--
###```int m_sanity_loss```
--
###```Direction direction() const```
###```void set_direction(Direction direction)```
####Parameters
#####```Direction direction```
--
###```const pair<double, double>& moviment() const```
--
###```void set_moviment(double xaxis, double yaxis)```

####Parameters
#####```double xaxis```
#####```double yaxis```
--
###```static ActionID hitExitDoorID```
###```static ActionID jumpNextLevelID```
###```static ActionID takeItemID```
###```static ActionID openDoorID```
###```static ActionID pushItemID```
###```static ActionID repeatLevelID```
###```static ActionID changeRoomID```
###```static ActionID getHitID```
--
###```void set_current(string room, int x, int y)```
####Parameters
#####```string room```
#####```int x```
#####```int y```
--
###```int life()```
###```double health()```
###```double sanity()```
###```double strength()```
###```double stamina()```
###```double damage()```

###```void set_life(int life)```
####Parameters
#####```int life```
--
###```void set_health(double health)```
####Parameters
#####```double health```
--
###```void set_sanity(double sanity)```
####Parameters
#####```double sanity```
--
###```void set_strength(double strength)```
####Parameters
#####```double strength```
--
###```void set_stamina(double stamina)```
####Parameters
#####```double stamina```
--
###```void set_key(bool input)```
####Parameters
#####```bool input```
--
###```void get_key()```
###```bool has_key()```

###```void get_pill(string id)```
####Parameters
#####```string id```
--
###```void get_weapon(string weapon_id)```
####Parameters
#####```string weapon_id```
--

###```void take_item()```
###```void jump_level()```
###```void open_door()```
###```void push_item()```
###```void use_pill()```
###```void use_weapon()```
###```void you_died()```
###```void hit()```
###```void die()```

###```void show_health()```
###```void show_sanity()```
###```void show_inventory()```
###```void show_stamina()```

##Private:
###```bool m_key```
###```int m_pill```
###```bool m_hweapon```
###```Weapon* m_weapon```
###```bool m_secondary```
###```double m_damage```
###```unique_ptr<Impl> m_impl```
--
