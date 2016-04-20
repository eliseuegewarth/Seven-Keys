#MouseButtonEvent

###variables
    ·typedef enum ButtonState
    ·typedef enum Button

##MouseButtonEvent::MouseButtonEvent()
###parameters
    ·ButtonState state
    ·Button button,
    ·double x
    ·double y

##MouseButtonEvent::state() const

##MouseButtonEvent::button() const

##double MouseButtonEvent::x() const

##double MouseButtonEvent::y() const

##MouseButtonEvent

##MouseButtonEvent::from_SDL()
###parameters
    ·const SDL_Event& event
###variables and methods
    ·MouseButtonEvent::ButtonState state = (event.type == SDL_MOUSEBUTTONDOWN ?
    ·MouseButtonEvent::PRESSED : MouseButtonEvent::RELEASED);
    ·MouseButtonEvent::Button button;
