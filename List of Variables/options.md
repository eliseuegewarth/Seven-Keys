#options.cpp

## class Options : public Object

###Options::Options()
    Environment *env = Environment::get_instance()
    double w = env->canvas->w()
    double h = env->canvas->h()
    Button *set_fullscreen = new Button(this, "fullscreen", "res/interface/menuOpcao/modoJanela.png",
        "res/interface/menuOpcao/SmodoJanela.png")
    Button *windowmode = new Button(this, "windowmode", "res/interface/menuOpcao/comoJogar.png",
        "res/interface/menuOpcao/ScomoJogar.png")
    Button *back = new Button(this, "back", "res/interface/menuOpcao/voltar.png",
        "res/interface/menuOpcao/Svoltar.png")

###Options::~Options()

###void Options::draw_self()
    Environment *env = Environment::get_instance()
    env->canvas->clear(Color::WHITE)
    shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuOpcao/menuOpcao.png")

###bool Options::on_message()
    Object *object
    MessageID id
    Environment *env = Environment::get_instance()
    Button *button = dynamic_cast<Button *>(object)
