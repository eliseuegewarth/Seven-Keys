#Pause

##```class Pause : public Object```
Class that represents the pause option of the main menu of the game.

##```Pause::Pause()```
Creates the environment of the pause menu.

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
Button *backGame;
```
Directs the environment where the game was paused.

```c++
Button *backMenu;
```
Directs to the main menu of the game.

```c++
Button *exit;
```
Closes the game.


##```void Pause::draw_self()```
Drow pause pinctures on the screen.

```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

##```bool Pause::on_message()```
Let the dynamic buttons.

```c++
Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.
