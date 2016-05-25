#MouseButtonEvent

###variables
```c++
typedef enum Button
```
Define the states of mouse button [LEFT button, RIGHT button, MIDDLE button]
```c++
typedef enum ButtonState
```
Define the states of mouse button [Button Pressed or Button Released]

##```MouseButtonEvent::MouseButtonEvent()```
###parameters
```c++
ButtonState state
```
State of mouse button
```c++
Button button,
```
mouse button that are pressed
```c++
double x
```
Mouse position in axis x(horizontal) in pixels
```c++
double y
```
Mouse position in axis x(horizontal)in pixels

##```MouseButtonEvent::state() const```
State of the buttons, if it is pressed or not
##```MouseButtonEvent::button() const```
Mouse button that are pressed
##```double MouseButtonEvent::x() const```
Position where the mouse button was pressed on the screen in axis x(horizontal)
##```double MouseButtonEvent::y() const```
position where the mouse button was pressed on the screen in axis y(vertical)

##```MouseButtonEvent::from_SDL()```
Reads the button that are pressed from the SDL library and returns the states for class
###parameters
```c++
·const SDL_Event& event
```
Mouse event detected by the SDL library
###variables and methods
```c++
MouseButtonEvent::ButtonState state
```
