#JoyStickEvent

##class JoyStickEvent

###variables

    ·typedef enum State;
    ·typedef enum Button;
    ·State m_state;
    ·Button m_button;

    ·static bool joystick_was_init = false;
    ·static map<int, JoyStickEvent::Button> m_joystick_table;

###void init_table_joystick()

##JoyStickEvent::JoyStickEvent()
###parameters
    ·State state
    ·Button button

##JoyStickEvent::state() const

##JoyStickEvent::button() const

##JoyStickEvent::from_SDL()
###parameters
    ·const SDL_Event& event
###variables and methods
    ·JoyStickEvent::State state = (event.type == SDL_CONTROLLERBUTTONDOWN ?
        ·event.type == SDL_CONTROLLERBUTTONDOWN ? JoyStickEvent::PRESSED
    ·JoyStickEvent::Button button
