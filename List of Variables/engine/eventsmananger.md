##Class eventsmanager

##private:

·unique_ptr<Impl> m_impl

###list<SDL_Event grab_SDL_events()

·SDL_Event event
·list<SDL_Event> events

###void register_listener()

·Listener * listener

###void unregister_listener()

·Listener * listener

###void dispatch_pending_events()

·SystemEvent se
·MouseMotionEvent me
·auto e
·auto ls
·KeyboardEvent ke
·JoyStickEvent je
·list<Listener * > m_listeners
