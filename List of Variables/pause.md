#Pause

##```class Pause : public Object```
###Class members
```c++
 bool on_message(Object *sender, MessageID id, Parameters parameters);
```

##```Pause::Pause()```
###Parameters
```c++
Environment *env = Environment::get_instance();
```
```c++
double w = env->canvas->w();
``` 
```c++
double h = env->canvas->h();
```
```c++
Button *backGame = new Button(this, "backGame", "res/interface/menuPausa/voltarJogo.png",
        "res/interface/menuPausa/SvoltarJogo.png");
```
```c++
Button *backMenu = new Button(this, "backMenu", "res/interface/menuExtras/voltar.png",
        "res/interface/menuExtras/Svoltar.png");
```
```c++
Button *exit = new Button(this, "exit", "res/interface/menuExtras/sair.png",
        "res/interface/menuExtras/Ssair.png");
```


##```void Pause::draw_self()```
###Parameters
```c++
Environment *env = Environment::get_instance();
```

##```bool Pause::on_message(Object *object, MessageID id, Parameters)```
###Parameters
```c++
Environment *env = Environment::get_instance();
```