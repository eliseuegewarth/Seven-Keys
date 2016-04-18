#Square

##Square::Square(Object *parent, ObjectID id, double size)

    ·Environment *env = Environment::get_instance();
    ·double y = env->canvas->h()*0.6 - size;

##Square::~Square()
    ·Environment *env = Environment::get_instance();

##double Square::size()

##bool Square::on_event(const KeyboardEvent& event)

##void Square::draw_self()
    ·const Color color { 80, 180, 205 };
    ·Environment *env = Environment::get_instance();

##void Square::update_self(unsigned long elapsed)
    ·Environment *env = Environment::get_instance();
    ·double x = this->x() + m_speed*((elapsed - m_last)/1000.0);

##class Square : public Object, Listener
    ·Square(Object *parent, ObjectID id, double size);
    ·~Square();
    ·double size();
    ·double m_speed;
    ·unsigned long m_last;
    ·void draw_self();
    ·void update_self(unsigned long elapsed);
