#MouseMotionEvent

##MouseMotionEvent::MouseMotionEvent(int x, int y, int x_rel, int y_rel,
    MotionState left, MotionState right, MotionState middle)
    : m_x(x), m_y(y), m_x_rel(x_rel), m_y_rel(y_rel),
      m_buttons { left, right, middle }

##MouseMotionEvent::MotionState

##MouseMotionEvent::state(MouseMotionEvent::Button button) const

##int MouseMotionEvent::x() const

##int MouseMotionEvent::y() const

##int MouseMotionEvent::x_rel() const

##intMouseMotionEvent::y_rel() const

##MouseMotionEvent::from_SDL(const SDL_Event& event)
    ·int x = event.motion.x;
    ·int y = event.motion.y;
    ·int xrel = event.motion.xrel;
    ·int yrel = event.motion.yrel;
    ·Uint8 state = event.motion.state;
    ·MotionState left = UP, right = UP, middle = UP;
