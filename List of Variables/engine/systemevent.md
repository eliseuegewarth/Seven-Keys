#Systemevent
##```class SystemEvent```

###Class members
```c++
typedef enum { UNKNOWN, QUIT } Type;
```

```c++
Type m_type;
```
##```SystemEvent::SystemEvent()```

###Parameters
```c++
SystemEvent::Type type;
```

##```SystemEvent::Type SystemEvent::type() const```

##```SystemEvent SystemEvent::from_SDL()```

###Parameters
```c++
const SDL_Event& event;
```
