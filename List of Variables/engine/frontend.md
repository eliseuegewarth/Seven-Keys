#Class fronted

##public:

###FrontEnd::FrontEnd()

·const string &id → parameter of constructor
·const string &texture → parameter of constructor
·unsigned long duration → parameter of constructor
·const string& next → parameter of constructor
·unsigned long duration → parameter of constructor
·const Color& → parameter of constructor
·const Color &bg → parameter of constructor
·Environment* env → manages the listener by instance

###Impl()

·Level * parent → parameter of constructor
·const string &texture → parameter of constructor
·unsigned long duration → parameter of constructor
·const Color &background → parameter of constructor
·Environment * env → manages the listener by instance

###Frontend::on_event()

·const MouseButtonEvent &event

###Frontend::update_self()

·unsigned long elapsed
·unsigned long now
·unsigned char a

###Frontend::raw_self()

##private:

·Level * m_parent
·shared_ptr<Texture> m_texture
·Color m_background
·Color m_fav
·unsigned long m_start → set the intro start
·unsigned long m_duration → set the duration of each frame
·unsigned long m_in → fade in time
·unsigned long m_out → fade out time
·int m_x → size x of screen
·int m_y → size y of screen
