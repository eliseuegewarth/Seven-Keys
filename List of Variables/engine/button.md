#Button

##class Button::Impl
    ·typedef enum { IDLE, ACTIVE } State;

##Impl(Button *button)

##Impl(Button *button, const string& idle_image_id,
       const string& active_image_id)

    ·Environment *env = Environment::get_instance();
    ·m_idle_texture = env->resources_manager->get_texture(idle_image_id);
    ·m_active_texture = env->resources_manager->get_texture(active_image_id);

##~Impl()

##Sets
    ###void set_text(const string& text, const Color& color)

    ###void set_color(const Color& idle, const Color& active)
        ·m_idle = idle;
        ·m_active = active;

    ###void set_border(int thickness, const Color& color)
        ·m_border = color;
        ·m_thickness = thickness;

    ###bool on_event(const MouseButtonEvent& event)
        ·char coords[64];
        ·m_state = ACTIVE;
        ·m_state = IDLE;

    ###void draw_self()
        ·Environment *env = Environment::get_instance();

##Private & Methods

    ·Button *m_button;
    ·Text *m_text;
    ·Color m_idle, m_active, m_border;
    ·int m_thickness;
    ·State m_state;
    ·shared_ptr<Texture> m_idle_texture, m_active_texture;

##ActionID Button::clickedID = "clicked()";

##Button::Button(Object *parent, ObjectID id, double w, double h)

    ·Environment *env = Environment::get_instance();

##Button::Button(Object *parent, ObjectID id, const string& idle_image_id,
    const string& active_image_id)

    ·Environment *env = Environment::get_instance();

##Button::~Button()
    ·Environment *env = Environment::get_instance();

##void Button::draw_self()

##bool Button::on_event(const MouseButtonEvent& event)

##bool Button::on_event(const MouseMotionEvent& event)

##void Button::set_text(const string& text, const Color& color)

##void Button::set_color(const Color& idle, const Color& active)

##void Button::set_border(int thickness, const Color& color)
