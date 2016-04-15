#Class camera

##public:

###Impl()
·Camera * camera
·Mode mode

###Camera::Camera()
·double x
·double y
·double w
·double h
·Mode mode

###Camera::update_self()
·unsigned long
·double x
·double y

###Camera::follow()
·const Object * object

###Camera::set_limits()
·const Rect &limits

##private:
·Camera * m_camera
·Mode m_mode
·const Object * m_target
·Rect m_limits
