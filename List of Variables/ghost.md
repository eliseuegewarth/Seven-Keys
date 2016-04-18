#Ghost

##Ghost::Ghost(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, string t, int dir)
    ·this->set_mass(mass);
    ·this->set_w(70);
    ·this->set_h(70);
    ·this->set_walkable(walkable);
    ·update_vision();

##Ghost::~Ghost()

##Ghost::Direction

##Ghost::direction()

##void Ghost::update_vision()

##void Ghost::set_direction(Direction direction)

##void Ghost::draw_self()

##void Ghost::walk()
    ·double speed = 0.6;

##void Ghost::update_direction(unsigned long elapsed)
    ·int random = rand()%100;

##void Ghost::get_playerx(int pos_x)

##void Ghost::get_playery(int pos_y)

##double Ghost::damage()

##void Ghost::update_self(unsigned long elapsed)

##void Ghost::change_animation(string path)

##class Ghost : public Object
	·typedef enum { NONE, IDLE, RUNNING } State;
    ·typedef enum { MOVED, STOPPED } Event;
    ·typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;
    ·Ghost(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, string type, int dir)
    ·Direction direction();
    ·void get_playerx(int pos_x);
    ·void get_playery(int pos_y);
    ·void set_direction(Direction direction);
    ·void update_vision();
    ·void walk();
    ·void update_direction(unsigned long elapsed);
    ·void change_animation(string path);
    ·double damage();
    ·string type;
    ·int player_posx;
    ·int player_posy;
    ·double m_damage;
    ·void draw_self();
    ·void update_self(unsigned long elapsed);
    ·unique_ptr<Animation> m_animation;
    ·Direction m_direction;
    ·unsigned long m_last = 0;
