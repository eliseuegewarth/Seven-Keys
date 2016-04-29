#Square

##class Square : public Object, Listener
###variables
```c++
·double m_speed;
```

```c++
·unsigned long m_last;
```
Last game time saved since the start of the game. It's like an old Elapsed time.
##Square::Square()
###parameters
```c++
·Object * parent
```
```c++
·ObjectID id
```
```c++
·double size
```
###variables
```c++
·Environment * env
```
```c++
·double y
```

##Square::~Square()
###variables
```c++
·Environment * env
```


##double Square::size()

##bool Square::on_event()
###parameters
```c++
const KeyboardEvent& event
```
##void Square::draw_self()
###variables
```c++
·const Color color { 80, 180, 205 };
```
```c++
·Environment * env = Environment::get_instance();
```


##void Square::update_self()
###parameters
```c++
·unsigned long elapsed
```
###variables
```c++
·Environment * env = Environment::get_instance();
```
```c++
·double x
```
