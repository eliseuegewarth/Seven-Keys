#MouseButtonEvent

##MouseButtonEvent::MouseButtonEvent(ButtonState state, Button button,
    double x, double y) : m_state(state), m_button(button), m_x(x), m_y(y)

##MouseButtonEvent::ButtonState

##MouseButtonEvent::state() const

##MouseButtonEvent::Button

##MouseButtonEvent::button() const

##double MouseButtonEvent::x() const

##double MouseButtonEvent::y() const

##MouseButtonEvent

##MouseButtonEvent::from_SDL(const SDL_Event& event)
    ·MouseButtonEvent::ButtonState state = (event.type == SDL_MOUSEBUTTONDOWN ?
    ·MouseButtonEvent::PRESSED : MouseButtonEvent::RELEASED);
    ·MouseButtonEvent::Button button;
