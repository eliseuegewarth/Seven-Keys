#JoyStickEvent

    ·static bool joystick_was_init = false;
    ·static map<int, JoyStickEvent::Button> m_joystick_table;

    ·void init_table_joystick()

##JoyStickEvent::JoyStickEvent

##JoyStickEvent::State

##JoyStickEvent::state() const

##JoyStickEvent::Button

##JoyStickEvent::button() const

##JoyStickEvent

##JoyStickEvent::from_SDL(const SDL_Event& event)

##JoyStickEvent::State state = (event.type == SDL_CONTROLLERBUTTONDOWN ?

##JoyStickEvent::PRESSED : JoyStickEvent::RELEASED);

##JoyStickEvent::Button button = m_joystick_table[event.cbutton.button];
