#Square

##class Square : public Object, Listener
###variables
```c++
·double m_speed;
```

```c++
·unsigned long m_last;
```
Last game time saved since the start of the game. It's like an old Elapsed time.

##Square::Square()
###parameters
```c++
·Object * parent
```
The parent is the map object that will contains the .
```c++
·ObjectID id
```
Identifier of object
```c++
·double size
```
Square size that will be created, height and width

###variables
```c++
·Environment * env
```
```c++
·double y
```

##Square::~Square()
###variables
```c++
·Environment * env
```


##double Square::size()
Returns one of the sides of the square, width or height

##bool Square::on_event()
Return if the square is on an event
###parameters
```c++
const KeyboardEvent& event
```
Keyboard action

##void Square::draw_self()
Draws the animation of the environment on screen
###variables
```c++
·const Color color { 80, 180, 205 };
```
Color of the square
```c++
·Environment * env = Environment::get_instance();
```
Instance of the environment

##void Square::update_self()
Updates the environment on the screen
###parameters
```c++
·unsigned long elapsed
```
Elapsed time since the game start.
###variables
```c++
·Environment * env = Environment::get_instance();
```
Instance of the environment
```c++
·double x
```
