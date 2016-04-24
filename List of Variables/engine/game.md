#Game
##```class Game``
Class that represents a game.

###Class members
```c++
string m_id;
```
```c++
Level *m_level;
```
variableariable that stores game levels.

```c++
bool m_done;
```
variable that stores if it was done or not the level.

```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
virtual Level * load_level(const string& id);
```
##```Game::Game(const string& id)```
###Parameters
```c++
Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

##```Game::init()```
Method to init the game.

###Parameters
```c++
const string& title;
```
```c++
int w;
```
variable that stores the width of the resolution.

```c++
int h;
```
variable that stores the screen resolution height.

```c++
double scale;
```
variable that stores the display scale.

```c++
bool fullscreen;
```
boolean variable that stores the state of the screen.

```c++
int volume;
```
Variable that stores the game audio volume.

##```Game::run()```
Method to start the game.