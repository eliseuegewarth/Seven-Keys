#Class camera

##public:

###Impl()
·Camera * camera → camera object
·Mode mode →

###Camera::Camera()
·double x → position x of the camera
·double y → position y of the camera
·double w → width of the screen
·double h → height x of the screen
·Mode mode

###Camera::update_self()
·unsigned long → parameter required by the interface
·double x →
·double y →

###Camera::follow()
·const Object * object → object of any object of the game

###Camera::set_limits()
·const Rect &limits → limits of the screen

##private:
·Camera * m_camera → camera object
·Mode m_mode →
·const Object * m_target → object that camera is focused
·Rect m_limits → limits of the screen
