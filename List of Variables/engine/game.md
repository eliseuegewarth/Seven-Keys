#Game
##```class Game : public Listener```
Class that represents a game.

###Class members
```c++
string m_id;
```
Map identifier file.

```c++
Level *m_level;
```
Stores the game levels.

```c++
bool m_done;
```
Stores if it was create or not the level.

```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.


##```Game::Game()```


###Parameters
```c++
const string& id;
```
Identifier of stage.


###Parameters
```c++
Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

##```Game::init()```
Method to init the game.
Initialized the game whith ours 
"inicializa o jogo com todas as pre configurações."

###Parameters
```c++
const string& title;
```
```c++
int width;
```
variable that stores the width of the resolution.

```c++
int height;
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

##```Game::init()```
Method to init the game.

###Parameters
```c++
const string& path;
```
```c++
int wight;
```
variable that stores the width of the resolution.

```c++
int height;
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

```c++
unsigned long now;
```
Number of milliseconds since the SDL library initialized. 

```c++
string next;
```


##```unsigned long Game::update_timestep() const```


##```bool Game::on_event()```


###Parameters
```c++
const SystemEvent& event;
```


##```bool Game::on_event()```


###Parameters
```c++
const KeyboardEvent& event;
```

##```void Game::update_screen()```


##```void Game::delay()```
###Parameters
```c++
unsigned long ms;
```

##```Level * Game::load_level()```

