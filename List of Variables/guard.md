#Guard
```c++
```
##ActionID Guard::removeGuardID { "removeGuardID()" };
##ActionID Guard::walkID { "walkID()" };

#Guard::Guard()
###Parameters
```c++
Object *parent
```
```c++
ObjectID id
```
```c++
double x
```
```c++
double y
```
```c++
bool walkable
```
```c++
int mass
```
```c++
string t
```
```c++
int dir
```


    ·this->set_mass(mass);
    ·this->set_w(70);
    ·this->set_h(70);
    ·this->set_walkable(walkable);
    ·this->set_old_type(t);
    ·update_vision();

##Guard::~Guard()

##Guard::Direction
##Guard::direction()

##void Guard::update_vision()
    ·const list<Object *> filhos = this->children();
    ·Sight *visao = new Sight(this, "visao", this->x()+40, this->y(), 200, 80);
    ·Sight *visao = new Sight(this, "visao", this->x() - 200, this->y(), 240, 80);
    ·Sight *visao = new Sight(this, "visao", this->x(), this->y() - 200, 80, 240);
    ·Sight *visao = new Sight(this, "visao", this->x(), this->y() + 40, 80, 200);

##void Guard::set_direction(Direction direction)
    ·m_direction = direction;

##void Guard::draw_self()

##void Guard::walk(unsigned long elapsed)
    ·double speed = 1;
    ·Environment *env = Environment::get_instance();

##void Guard::update_direction(unsigned long elapsed)

##void Guard::get_playerx(int pos_x)
    ·player_posx = pos_x;

##void Guard::get_playery(int pos_y)
    ·player_posy = pos_y;

##double Guard::damage()

##void Guard::update_self(unsigned long elapsed)

##void Guard::change_animation(string path)

##double Guard::health()

##string Guard::type()

##string Guard::old_type()

##void Guard::set_type(string t)
    ·m_type = t;

##void Guard::set_old_type(string t)
    ·m_old_type = t;

##void Guard::receive_dmg(double dmg)
    ·m_health = m_health - dmg;

##class Guard : public Object
    ·typedef enum { NONE, IDLE, RUNNING } State;
    ·typedef enum { MOVED, STOPPED } Event;
    ·typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;
    ·Guard(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, string type, int dir)

    ·static ActionID removeGuardID;
    ·static ActionID walkID;


    ·Direction direction();
    ·void get_playerx(int pos_x);
    ·void get_playery(int pos_y);
    ·void set_direction(Direction direction);
    ·void update_vision();
    ·void walk(unsigned long elapsed);
    ·void update_direction(unsigned long elapsed);
    ·void change_animation(string path);
    ·string type();
    ·string old_type();
    ·void set_type(string t);
    ·void set_old_type(string t);
    ·double health();
    ·double damage();
    ·void receive_dmg(double dmg);
    ·string m_old_type;
    ·string m_type;
    ·int player_posx;
    ·int player_posy;
    ·double m_damage;
    ·double m_health;
    ·void draw_self();
    ·void update_self(unsigned long elapsed);
    ·unique_ptr<Animation> m_animation;
    ·Direction m_direction;
    ·unsigned long m_last;
