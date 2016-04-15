#Class fronted

##public:

###FrontEnd::FrontEnd()

·const string &id
·const string &texture
·unsigned long duration
·const Color &bg
·Rect r

###Impl()

·Level * parent
·const string &texture
·unsigned long duration
·const Color &background
·Environment * env

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
·unsigned long m_start
·unsigned long m_duration
·unsigned long m_in
·unsigned long m_out
·int m_x
·int m_y
