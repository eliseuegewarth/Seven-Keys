#pause.cpp

## class Pause : public Object

###Pause::Pause()
    Environment *env = Environment::get_instance();
    double w = env->canvas->w();
    double h = env->canvas->h();
    Button *backGame = new Button(this, "backGame", "res/interface/menuPausa/voltarJogo.png",
        "res/interface/menuPausa/SvoltarJogo.png");
    Button *backMenu = new Button(this, "backMenu", "res/interface/menuExtras/voltar.png",
        "res/interface/menuExtras/Svoltar.png");
    Button *exit = new Button(this, "exit", "res/interface/menuExtras/sair.png",
        "res/interface/menuExtras/Ssair.png");

###Pause::~Pause()

###void Pause::draw_self()
    Environment *env = Environment::get_instance();

###bool Pause::on_message(Object *object, MessageID id, Parameters)
    Environment *env = Environment::get_instance();