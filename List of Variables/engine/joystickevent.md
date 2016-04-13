# Seven Keys

# Class JoyStickEvent



```c++
static bool joystick_was_init = false;
```

```c++
static map<int, JoyStickEvent::Button> m_joystick_table;
```

```c++
void init_table_joystick()
```

```c++
JoyStickEvent::JoyStickEvent(State state, Button button)
    : m_state(state), m_button(button)
```

```c++
JoyStickEvent::State
```

```c++
JoyStickEvent::Button
```

```c++
JoyStickEvent::Button button = m_joystick_table[event.cbutton.button];
```

```c++
JoyStickEvent::PRESSED : JoyStickEvent::RELEASED);
```

```c++
JoyStickEvent::State state = (event.type == SDL_CONTROLLERBUTTONDOWN ?
```

```c++
JoyStickEvent::from_SDL(const SDL_Event& event)
```
