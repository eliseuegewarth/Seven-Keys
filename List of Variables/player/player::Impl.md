
#Class Player::Impl

##public:
###Impl(Player *player, bool key)```
--

###int m_sanity_loss
--
###Direction direction() const
--
###void set_direction(Direction direction)
--

###const pair<double, double>& moviment() const
--

###void set_moviment(double xaxis, double yaxis)
--
###void set_current(string nova, int posx, int posy)
--
###void set_strength(double strength)
--
###double strength()
--
###void set_health(double health)
--
###double health()
--
###void set_sanity(double sanity)
--
###double sanity()
--
###double stamina()
--
###void set_stamina(double stamina)
--
###double damage()
--
###void get_pill(string id)
#####const list<Object *> items = m_player->children();
#####Environment *env = Environment::get_instance();
#####char path[256];
#####Item* pill
--
###void get_weapon(string weapon_id)
#####Environment *env = Environment::get_instance();
#####double size = env->canvas->w()/35;
#####char weapon_path[256];
#####Item* lWeapon
#####Weapon* weapon
--
###void get_key()
#####Environment *env = Environment::get_instance();
#####Item* key
--
###void set_key(bool input)
###bool has_key()
--
###void show_health()
#####Environment *env = Environment::get_instance();
#####Rect healthbar {(double)env->canvas->w()/15, (double)env->canvas->h()/24, m_player->health()*2, 12};
#####Rect borda
--

###void show_sanity()
#####Environment *env = Environment::get_instance();
#####Rect sanitybar {(double)env->canvas->w()/15, (double)env->canvas->h()/17, m_player->sanity()*2, 12};
#####Rect borda
--

###void show_stamina()
#####Environment *env = Environment::get_instance();
#####double stamina = m_player->stamina()*2;
#####Rect staminabar {(double)env->canvas->w()/15, (double)env->canvas->h()/13, stamina, 12};
#####Rect borda
--

###void show_inventory()
#####Environment *env
#####double size
--

###Rect item1
--
###Rect item2
--
###Rect item3
--
###Rect item4
--
###Rect not_item
--

###void use_pill()
#####double recover = 35;
#####const list<Object *> items = m_player->children();
#####auto item
--

###void use_weapon()
--

###void take_item()
--

###void jump_level()
--

###void open_door()
--

###void push_item()
--

###void you_died()
--

###void hit()
#####char message[256];
#####double dmg_total;
#####const list<Object *> filhos = m_player->children();
#####auto filho
#####Sight *visao
--

###int life()
--

##Private:
###Player *m_player
--
###Direction m_direction
--
###pair<double, double> m_moviment
--
###bool m_key
--
###double m_strength
--
###double m_health
--
###double m_sanity
--
###double m_stamina
--
###int m_pill
--
###bool m_hweapon
--
###Weapon* m_weapon
--
###bool m_secondary
--
###double m_damage
--
###int m_life
--
