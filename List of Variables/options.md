#Options

##```class Options : public Object```
Class that represents the option of the main menu of the game.

##```Options::Options()```


###Parameters
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
Button *set_fullscreen;
```
Puts the screen in fullscreen.

```c++
Button *windowmode;
```
Puts the screen in windowed mode.

```c++
Button *back;
```
Directs to the main menu of the game.


##```void Options::draw_self()```
Drow options pinctures on the screen.

```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

##```bool Options::on_message()```
Let the dynamic buttons.

```c++
Environment *env = Environment::get_instance()
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.


