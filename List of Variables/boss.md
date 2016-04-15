#Boss.cpp

## class Boss : public Object
### Constants and Enum
### Class Members

### Methods
public:
    typedef enum { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;

    Boss(Object *parent, ObjectID id, double x, double y, int mass, bool walkable, int dir);
    ~Boss();

    Direction direction();
    void get_playerx(int pos_x);
    void get_playery(int pos_y);
    void set_direction(Direction direction);
    void update_vision();
    void walk();
    void update_direction(unsigned long elapsed);

    void set_position(double x, double y);

    bool summoned() {return m_summoned;}
    bool created() {return m_created;}

    void set_summoned(bool t);
    void set_created(bool t);

    double damage();

private:
    int player_posx;
    int player_posy;
    double m_damage;
    bool m_summoned;
    bool m_created;

    void draw_self();
    void update_self(unsigned long elapsed);
    unique_ptr<Animation> m_animation;
    Direction m_direction;
    unsigned long m_last = 0;
