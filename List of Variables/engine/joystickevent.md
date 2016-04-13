# Seven Keys

# Class JoyStickEvent



```sh
static bool joystick_was_init = false;
```

```sh
static map<int, JoyStickEvent::Button> m_joystick_table;
```

```sh
void init_table_joystick()
```

```sh
JoyStickEvent::JoyStickEvent(State state, Button button)
    : m_state(state), m_button(button)
```

```sh
JoyStickEvent::State
```

```sh
JoyStickEvent::Button
```

```sh
JoyStickEvent::Button button = m_joystick_table[event.cbutton.button];
```

```sh
JoyStickEvent::PRESSED : JoyStickEvent::RELEASED);
```

```sh
JoyStickEvent::State state = (event.type == SDL_CONTROLLERBUTTONDOWN ?
```

```sh
JoyStickEvent::from_SDL(const SDL_Event& event)
```
