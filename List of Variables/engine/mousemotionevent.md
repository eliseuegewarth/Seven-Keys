#MouseMotionEvent

##```class MouseMotionEvent```

###Class Members
```c++
typedef enum { DOWN, UP } MotionState;
```
Define the Motion states of mouse moviment
```c++
typedef enum { LEFT, RIGHT, MIDDLE } Button;
```
Define the states of mouse button
```c++
int m_x;
```
Mouse position in axis x(horizontal)
```c++
int m_y;
```
Mouse position in axis y(vertical)
```c++
int m_x_rel;
```

```c++
int m_y_rel;
```

```c++
MotionState m_buttons[3];
```

##```MouseMotionEvent::MouseMotionEvent()```
###parameters
```c++
int x
```
Mouse position in axis x(horizontal)
```c++
int y
```
Mouse position in axis y(vertical)
```c++
int x_rel
```
```c++
int y_rel
```
```c++
MotionState left
```
Position where the mouse is moving (left)
```c++
MotionState right
```
Position where the mouse is moving (right)
```c++
MotionState middle
```
Position where the mouse is moving (middle)
##```MouseMotionEvent::state() const```
State of the buttons, if it is pressed or not
###parameters
```c++
MouseMotionEvent::Button button
```
Button that is pressed
##```int MouseMotionEvent::x() const```
Mouse position in axis x(horizontal)
##```int MouseMotionEvent::y() const```
Mouse position in axis y(vertical)
##```int MouseMotionEvent::x_rel() const```

##```intMouseMotionEvent::y_rel() const```

##```MouseMotionEvent::from_SDL()```
Reads the movements from the SDL library and returns the states for class
###parameters
```c++
const SDL_Event& event
```
Mouse event detected by the SDL library
###variables
```c++
int x
```
Mouse position in axis x(horizontal)
```c++
int y
```
Mouse position in axis y(vertical)
```c++
int xrel
```
```c++
int yrel
```
```c++
Uint8 state
```
```c++
MotionState left
```
