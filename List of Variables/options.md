#Options

##```class Options : public Object```
###Class members
```c++
bool on_message(Object *sender, MessageID id, Parameters parameters);
```
##```Options::Options()```
###Parameters
```c++
Environment *env = Environment::get_instance()
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.
```c++
double w = env->canvas->w()
```
Variable that receives the width of the game environment.
```c++
double h = env->canvas->h()
```
Variable that receives the height of the game environment.
```c++
Button *set_fullscreen = new Button(this, "fullscreen", "res/interface/menuOpcao/modoJanela.png",
        "res/interface/menuOpcao/SmodoJanela.png")
```

```c++
Button *windowmode = new Button(this, "windowmode", "res/interface/menuOpcao/comoJogar.png",
        "res/interface/menuOpcao/ScomoJogar.png")
```
```c++
Button *back = new Button(this, "back", "res/interface/menuOpcao/voltar.png",
        "res/interface/menuOpcao/Svoltar.png")
```

###```Options::~Options()```

##```void Options::draw_self()```
###Parameters
```c++
Environment *env = Environment::get_instance()
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.
```c++
env->canvas->clear(Color::WHITE)
```
```c++
shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuOpcao/menuOpcao.png")
``` 

##```bool Options::on_message()```
###Parameters
```c++
Object *object
```
```c++
MessageID id
```
```c++
Environment *env = Environment::get_instance()
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
Button *button = dynamic_cast<Button *>(object)
```
   
