#MouseMotionEvent

##```class MouseMotionEvent```

###Class Members
```c++
typedef enum { DOWN, UP } MotionState;
```
```c++
typedef enum { LEFT, RIGHT, MIDDLE } Button;
```
```c++
int m_x, m_y;
```
```c++
int m_x_rel, m_y_rel;
```
```c++
MotionState m_buttons[3];
```

##```MouseMotionEvent::MouseMotionEvent()```
###parameters
```c++
int x
```
```c++
int y
```
```c++
int x_rel
```
```c++
int y_rel
```
```c++
MotionState left
```
```c++
MotionState right
```
```c++
MotionState middle
```
##```MouseMotionEvent::state() const```
###parameters
```c++
MouseMotionEvent::Button button
```
##```int MouseMotionEvent::x() const```

##```int MouseMotionEvent::y() const```

##```int MouseMotionEvent::x_rel() const```

##```intMouseMotionEvent::y_rel() const```

##```MouseMotionEvent::from_SDL()```
###parameters
```c++
const SDL_Event& event
```
###variables
```c++
int x
```
```c++
int y
```
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
