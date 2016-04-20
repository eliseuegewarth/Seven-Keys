#MouseMotionEvent

##class MouseMotionEvent

###variables
    typedef enum MotionState;
    typedef enum Button;

    int m_x, m_y;
    int m_x_rel, m_y_rel;
    MotionState m_buttons[3];

##MouseMotionEvent::MouseMotionEvent()
###parameters
    ·int x
    ·int y
    ·int x_rel
    ·int y_rel
    ·MotionState left
    ·MotionState right
    ·MotionState middle
##MouseMotionEvent::state() const
###parameters
    ·MouseMotionEvent::Button button
##int MouseMotionEvent::x() const

##int MouseMotionEvent::y() const

##int MouseMotionEvent::x_rel() const

##intMouseMotionEvent::y_rel() const

##MouseMotionEvent::from_SDL()
###parameters
    ·const SDL_Event& event
###variables
    ·int x
    ·int y
    ·int xrel
    ·int yrel
    ·Uint8 state
    ·MotionState left
