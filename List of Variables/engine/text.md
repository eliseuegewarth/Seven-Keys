#Text
##```class Text : public Object```

###Class members

```c++
Object *parent;
```

```c++
const string& text;
```

```c++
const Color& color;
```

```c++
unique_ptr<Impl> m_impl;
```

##```class Text::Impl```

###Class members
```c++
Text *parent;
```

```c++
Environment *env;
```
It is an object of the class environment. Is a pointer to the current instance of the game environment.

```c++
Text *m_parent;
```

```c++
Texture *m_texture;
```
##```Text::Text()```

###Parameters

```c++
Object *parent;
```

```c++
const string& texture;
```

```c++
const Color& color;
```

##```Text::~Text()```

##```void Text::draw_self()```
