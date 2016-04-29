#Extras

##```class Extras : public Level```
Class that represents the extra option of the main menu of the game.

##```Extras::Extras()```
Creates the environment of the extras menu.

```c++
	Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
	double w;
```
Receives the width of the game environment.

```c++
	double h;
```
Receives the height of the game environment.

```c++
	 Button *cutscene;	
```
Directs to the cutscene of the game.

```c++
	Button *historia;
```
Directs to the history of the game.

```c++
	 Button *back;
```
Directs to the main menu of the game.

##```void Extras::draw_self()```
Drow extras pinctures on the screen.

###Parameters
```c++
Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

##```bool Extras::on_message()```
Let the dynamic buttons.
