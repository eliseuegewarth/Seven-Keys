#JoyStickEvent

##```class JoyStickEvent```

###variables
```c++
typedef enum State;
```
Define the states of joystick buttons [Button Pressed or Button Released]
```c++
typedef enum Button;
```
Define the states of mouse button
[X, CIRCLE, SQUARE, TRIANGLE, SHARE, HOME,
START, L3, R3, L1, R1, UP, DOWN, LEFT, RIGHT]
```c++
State m_state;
```

```c++
Button m_button;
```

```c++
static bool joystick_was_init = false;
```

```c++
static map<int
```

```c++
JoyStickEvent::Button> m_joystick_table;
```

###```void init_table_joystick()```

##```JoyStickEvent::JoyStickEvent()```
###parameters
```c++
State state
```
State of the joystick
```c++
Button button
```
Button that are pressed in the joystick

##```JoyStickEvent::state() const```
method that returns the state of the joystick, like a "get"

##```JoyStickEvent::button() const```
method that returns the button that are pressed in the joystick, like a "get"

##```JoyStickEvent::from_SDL()```
###parameters
```c++
const SDL_Event& event
```
Joystick event detected by the SDL library
