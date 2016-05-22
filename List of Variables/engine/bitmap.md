#Bitmap

##```class Bitmap```


c```
int width() const;
```

c```
int height() const;
```

c```
void * data() const;
```

c```
void * pixels() const;
```

c```
void clear();
```


##```class Bitmap::Impl```


###Parameters
c```
void *data;
```

c```
unsigned const int width;
```
    
c```
unsigned const int height;
```


##```int width() const```



##```int height() const```



##```SDL_Surface * data() const```


##```void * pixels() const```


##```Bitmap::Bitmap()```


###Parameters

c```
void *data;
```

c```
const int width;
```

c```
const int height;
```   

##```Bitmap::Bitmap()```


###Parameters 
c```
Canvas *canvas
```

##```void * Bitmap::data() const```


##```int Bitmap::width() const```  


##```int Bitmap::height() const```  


##```Bitmap * Bitmap::from_file()```  


###Parameters
c```
const string& path
```

##```void * Bitmap::pixels() const```  


##```void Bitmap::clear()```  


##```Uint32 Bitmap::getpixel()```    


###Parameters 
c```
SDL_Surface *surface;
```

c```
const int x;
```

c```
const int y;
```

##```void Bitmap::putpixel()```    

    
###Parameters 
c```
SDL_Surface *surface;
```

c```
int x;
```

c```
int y;
```

c```
Uint32 pixel;
```

    
##```void Bitmap::fill()```   

###Parameters  
c```
const Rect& r;
```


c```
Uint32 color
```

