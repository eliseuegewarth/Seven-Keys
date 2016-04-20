#Button

##class Button::Impl
###variables
    ·typedef enum { IDLE, ACTIVE } State;

##Impl()

    ·Button * button

##Impl()
###parameters
    ·Button * button
    ·const string& idle_image_id
    ·const string& active_image_id
    ·Environment * env = Environment::get_instance();
##~Impl()

##void set_text()
###parameters
    ·const string& text
    ·const Color& color
##void set_color()
###parameters
    ·const Color& idle
    ·const Color& active
##void set_border()
###parameters
    ·int thickness
    ·const Color& color
##bool on_event()
###parameters
    ·const MouseButtonEvent& event
    ·char coords[64];
##·void draw_self()
###parameters
    ·Environment * env = Environment::get_instance();


    ·Button * m_button;
    ·Text * m_text;
    ·Color m_idle, m_active, m_border;
    ·int m_thickness;
    ·State m_state;
    ·shared_ptr<Texture> m_idle_texture, m_active_texture;

##ActionID Button::clickedID

##Button::Button()
###parameters
    ·Object * parent
    ·ObjectID id
    ·double w
    ·double h
###variables and methods
    ·Environment * env = Environment::get_instance();

##Button::Button()
###parameters
    ·Object * parent
    ·ObjectID id
    ·const string& idle_image_id
    ·const string& active_image_id
###variables and methods
    ·Environment * env = Environment::get_instance();

##Button::~Button()
###variables and methods
    ·Environment * env = Environment::get_instance();

##void Button::draw_self()

##bool Button::on_event()
###parameters
    ·const MouseButtonEvent& event
##bool Button::on_event()
###parameters
    ·const MouseMotionEvent& event
##void Button::set_text()
###parameters
    ·const string& text
    ·const Color& color
##void Button::set_color()
###parameters
    ·const Color& idle
    ·const Color& active
##void Button::set_border()
###parameters
    ·int thickness
    ·const Color& color
