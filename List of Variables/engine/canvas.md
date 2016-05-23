#Canvas
##```class Canvas```
Class that creates the environments of the game.


```c++
typedef enum { NONE, BLEND } BlendMode;
```

```c++
int w() const;
```

```c++
int h() const;
```


```c++
const Color& color() const;
``` 

```c++
shared_ptr<Font> font() const;
```

```c++
BlendMode blend_mode() const;
```

```c++
SDL_Renderer *m_renderer;
```

```c++
int m_w;
```

```c++
int m_h;
```

```c++
Color m_color;
```

```c++
shared_ptr<Font> m_font;
```

```c++
BlendMode m_blend_mode;
```

```c++
SDL_Surface *m_bitmap;
```

```c++
SDL_Texture *m_texture;
```
   
##```Canvas::Canvas()```

###Parameters
```c++
SDL_Renderer *renderer
```

```c++
int w
```

```c++
int h
```

```c++

```
 ##```Canvas::~Canvas()```


##```int Canvas::w()```


##```int Canvas::h()```


##```const Color& Canvas::color()```


##```shared_ptr<Font> Canvas::font()```


##```Canvas::BlendMode Canvas::blend_mode()```


##```void Canvas::set_color()```


###Parameters
```c++
const Color& color
```

##```void Canvas::set_resolution()```

###Parameters
```c++
int w;
```
```c++
int h
```

##```void
Canvas::set_font()```

##```void Canvas::set_blend_mode()```

##```void Canvas::clear()```
###Parameters
```c++
const Color& color
```

##```void Canvas::update()```

##```void Canvas::draw()```
###Parameters
```c++
Environment *env = Environment::get_instance(); 
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
int x = point.x() - env->camera->x();
```
```c++
int y = point.y() - env->camera->y();
```


##```void Canvas::draw()```
###Parameters
```c++
const Line& line;
```
##```void Canvas::draw()```
###Parameters
```c++
const Point& point;
```
```c++
const Color& color;
```
```c++

```
##```void Canvas::draw()```
###Parameters
```c++
const Line& line
```
```c++
Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
int xa = line.a().x() - env->camera->x();
```
```c++
int ya = line.a().y() - env->camera->y();
```
```c++
int xb = line.b().x() - env->camera->x();
```
```c++
int yb = line.b().y() - env->camera->y();
```

```
##```void Canvas::draw()```
###Parameters
```c++
const Line& line
```
```c++
const Color& color
```
```c++

##```void Canvas::draw()```
###Parameters
```c++
const Rect& rect
```
```c++
 Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
int x = rect.x() - env->camera->x();
```
```c++
int y = rect.y() - env->camera->y();
```
##```void Canvas::draw()```
###Parameters
```c++
const Rect& rect;
```
```c++
const Color& color;
```

```c++

```
##```void Canvas::fill()```
###Parameters
```c++
const Rect& rect;
```
```c++
Environment *env = Environment::get_instance();
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.


```c++

```
##```void Canvas::draw()```
###Parameters
```c++
const Circle& circle;
```
```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
int cx;
```
```c++
int cy;
```
```c++
int r;
```
```c++
int error
```

##```void Canvas::fill()```
###Parameters
```c++
const Circle& circle
```
```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
int cx;
```
```c++
int cy;
```
```c++
int r;
```
##```void Canvas::fill()```
###Parameters
```c++
const Circle& circle
```
```c++
const Color& color
```
```c++

```
##```void Canvas::draw()```
###Parameters
```c++
const Circle& circle;
```
```c++
const Color& color
```
##```void Canvas::draw_circle_points()```
###Parameters
```c++
int cx;
```
```c++
int cy;
```
```c++
int x;
```
```c++
int y;
```
##```void Canvas::fill_circle_points()```
###Parameters
```c++
int cx;
```
```c++
int cy;
```
```c++
int x;
```
```c++
int y;
```
##```void Canvas::draw()```
###Parameters
```c++
const Texture *texture;
```
```c++
double x;
```
```c++
double y;
```

##```void Canvas::draw()```
###Parameters
```c++
const Texture *texture;
```
```c++
Rect clip;
```
```c++
double x;
```
```c++
double y;
```

```c++
double w;
```
Variable that receives the width of the game environment.

```c++
double h;
```
Variable that receives the height of the game environment;

```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
int orig_x;
```
Variable that stores the resolution of the x-axis.

```c++
int orig_y;
```
Variable that stores the resolution of the y-axis.

```c++
int orig_w;
```
Variable that stores the width of the game environment

```c++
int orig_h;
```
Variable that stores the height of the game environment.

```c++
int dest_x;
```


```c++
int dest_y;
```
```c++
int dest_w;
```
```c++
int dest_h;
```
```c++
SDL_Texture *image;
```

##```SDL_Renderer * Canvas::renderer()```

##```void Canvas::draw(double x, , )```
###Parameters
```c++
const string& text;
```
```c++
double x;
```
```c++
double y;
```
```c++
const Color& color;
```
```c++
SDL_Surface *surface;
```
```c++
int w;
```
```c++
int h;
```
```c++
 SDL_Texture *texture;
```
```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
int dest_x;
```
```c++
int dest_y;
```

##```Texture * Canvas::render_text()```
###Parameters
```c++
const string& text;
```
```c++
const Color& color;
```
```c++
SDL_Surface *surface;
```
```c++
int w;
```
```c++
int h;
```

##```SDL_Surface * Canvas::bitmap()```

##```void Canvas::draw()```
###Parameters
```c++
const Bitmap *bitmap.
```