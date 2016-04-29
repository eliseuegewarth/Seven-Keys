#Video
##```class Video```

###Class members
```c++
SDL_Window *m_window;
```


```c++
SDL_Renderer *m_renderer;
```


```c++
Canvas *m_canvas;
```


```c++
Camera *m_camera;
```


```c++
int m_w;
```


```c++
int m_h;
```


##```void Video::init()```

###Parameters
```c++
int rc;
```

##```void Video::set_resolution()```

###Parameters
```c++
int w;
```


```c++
int h;
```


```c++
double scale;
```


```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
void Video::set_fullscreen();
```


```c++
int flag;
```


```c++
int rc;
```


##```bool Video::fullscreen() const```

###Parameters
```c++
bool fullscreen;
```

##```void Video::set_window_name()```


##```pair<int, int> Video::resolution() const```


##```anvas * Video::canvas() const```


##```Camera * Video::camera() const```



```c++

```

```c++

```

```c++

```