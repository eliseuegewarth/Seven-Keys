#Extras

##```class Extras : public Level```
###Class members
```c++
bool on_message(Object *sender, MessageID id, Parameters parameters);
```
##```Extras::Extras()```
###Parameters
```c++
	Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
	double w = env->canvas->w();
```
Variable that receives the width of the game environment.

```c++
	double h = env->canvas->h();
```
Variable that receives the height of the game environment.

```c++
	 Button *cutscene = new Button(this, "cutscene", "res/interface/menuExtras/cutscenes.png",
        "res/interface/menuExtras/Scutscenes.png");	
```

```c++
	Button *historia = new Button(this, "historia", "res/interface/menuExtras/historia.png",
        "res/interface/menuExtras/Shistoria.png");
```

```c++
	 Button *back = new Button(this, "back", "res/interface/menuExtras/voltar.png",
        "res/interface/menuExtras/Svoltar.png");
```

##```void Extras::draw_self()```
###Parameters
```c++
Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

##```bool Extras::on_message(Object *object, MessageID id, Parameters)```
