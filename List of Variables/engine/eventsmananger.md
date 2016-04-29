##Class eventsmanager

##private:

·unique_ptr<Impl> m_impl → list of impl elements

###list<SDL_Event grab_SDL_events()

·SDL_Event event →
·list<SDL_Event> events → list of SDL events

###void register_listener()

·Listener * listener → regist listener

###void unregister_listener()

·Listener * listener → remove listener

###void dispatch_pending_events()

·SystemEvent se → System event from SDL
·MouseMotionEvent me → Capture the mouse motion sense
·auto e → Iterator for list of events
·auto ls → Iterator for list of listeners
·KeyboardEvent ke → Capture keyboard events
·JoyStickEvent je → Capture Joystick events
·list<Listener * > m_listeners → List of listeners
