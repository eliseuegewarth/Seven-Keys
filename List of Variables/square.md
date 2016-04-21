#Square

##class Square : public Object, Listener
###variables
    ·double m_speed;
    ·unsigned long m_last;

##Square::Square()
###parameters
    ·Object * parent
    ·ObjectID id
    ·double size
###variables
    ·Environment * env
    ·double y

##Square::~Square()
###variables
    ·Environment * env

##double Square::size()

##bool Square::on_event()
###parameters
const KeyboardEvent& event

##void Square::draw_self()
###variables
    ·const Color color { 80, 180, 205 };
    ·Environment * env = Environment::get_instance();

##void Square::update_self()
###parameters
    ·unsigned long elapsed
###variables
    ·Environment * env = Environment::get_instance();
    ·double x
