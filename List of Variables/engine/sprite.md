#Rect
##```class SpriteState```

###Class members
```c++
virtual void update();
```

```c++
virtual void draw();
```

```c++
virtual void leave();
```

```c++
virtual bool on_event();
```

##```class SpriteState```

###Class members
```c++
void report_event();
```

```c++
void change_state();
```

```c++
unique_ptr<Impl> m_impl;
```

##```void add_state()```

###Parameters

```c++
SpriteState *state;
```

```c++
int id;
```

##```void add_transition()```

###Parameters
```c++
int event;
```

```c++
int from;
```

```c++
int to;
```

##```void update_self()```

###Parameters
```c++
unsigned long elapsed;
```
##```void draw_self()```

##```bool on_event()```

###Parameters
```c++
const KeyboardEvent& event;
```

##```bool on_event()```

###Parameters
```c++
const KeyboardEvent& event;
```

##```bool on_event()```

###Parameters
```c++
const MouseButtonEvent& event
```

##```bool on_event()```

###Parameters
```c++
const MouseMotionEvent& event;
```

##```bool on_event()```

###Parameters
```c++
const JoyStickEvent& event;
```

##```void Sprite::report_event()```

###Parameters
```c++
int event;
```

##```void Sprite::change_state()```

###Parameters
```c++
int to;
```

```c++
int from;
```

##```void Sprite::add_state()```

###Parameters
```c++
int id;
```

```c++
SpriteState *state;
```

##```void Sprite::add_transition()```

```c++
int event;
```

```c++
int from;
```

```c++
int to;
```

##```void Sprite::update_self()```

###Parameters
```c++
unsigned long elapsed;
```

##```void Sprite::draw_self()```

##```SpriteState * Sprite::state()```

##```bool Sprite::on_event()```

###Parameters
```c++
const KeyboardEvent& event;
```

##```bool Sprite::on_event()```

###Parameters
```c++
const MouseButtonEvent& event;
```

##```bool Sprite::on_event()```

###Parameters
```c++
const MouseMotionEvent& event;
```

##```bool Sprite::on_event()```

###Parameters
```c++
const JoyStickEvent& event;
```