#Texture
##```class Texture```

###Class members
```c++
void *data;
```

```c++
int w;
```

```c++
int h;
```

```c++
int w() const;
```

```c++
int h() const;
```

```c++
void * data() const;
```

```c++
static Texture * from_file()
```

```c++
void scale(double k);
```

```c++
pair<int, int> size() const;
```

```c++
unique_ptr<Impl> m_impl;
```

##```class Texture::Impl```

###Class members
```c++
void *data;
```

```c++
int w;
```

```c++
int h;
```

```c++
Environment *env;
```

```c++
shared_ptr<Settings> settings;
```

```c++
double k;
```

```c++
int w() const;
```

```c++
int h() const;
```

```c++
void * data() const;
```

```c++
void scale();
```

```c++
pair<int, int> size() const;
```

```c++
int rc
```


```c++
int m_w;
```

```c++
int m_h;
```

```c++
SDL_Texture *m_texture;;
```

##```Texture::Texture()```

###Parameters
```c++
void *data;
```

```c++
int w;
```

```c++
int h;
```

##```void * Texture::data() const```

##```int Texture::w() const```

##```int Texture::h() const```

##```Texture * Texture::from_file()```

###Parameters

```c++
Environment *env;
```

```c++
SDL_Renderer *renderer;
```

```c++
SDL_Texture *texture;
```

```c++
Texture *t;
```

##```void Texture::scale()```

##```pair<int, int> Texture::size() const```


