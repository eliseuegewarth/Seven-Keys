#Class keyboardevent

##private:

·State m_state → set the state of keyboardevent

·Key m_key → set the keys allowed to being listeneds

·Modifier m_modifier

·static bool wha_init → check if the event whas initializable

·static map<int, KeyboardEvent::Key> m_key_table → list of allowed keys

###KeyboardEvent::Modifier key_modifier()

·Uint16 modifier

###KeyboardEvent::from_SDL()

·const SLD_Event &event → event transmitted
