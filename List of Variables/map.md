#Map

##```class Boss : public Object```
###Class members
```c++
int qut_salas;
```


```c++
int stage_id;
```


```c++
Room * current_room;
```


```c++
Room * room();
```


```c++
const list<Object *>& items()
```


```c++
Boss * m_boss;
```


```c++
vector <Room*> room_list;
```


```c++
Room * last_room;
```


```c++
double last_summon;
```


```c++
bool **matriz;
```


```c++
void CreateRoom(Room *, int*, int, int, int, int);
```


```c++
bool on_message(Object *object, MessageID id, Parameters p);
```


##```Map::Map()```

###Parameters
```c++
int qnt_salas
```


```c++
int stage_id
```


```c++
GenerateMap(qnt_salas, stage_id);
```


```c++
Boss *boss = new Boss(this, "boss", 0, 0, 999, true, Boss::LEFT);
```


##```void Map::CreateRoom()```

###Parameters
```c++
Room *room
```


```c++
int *id
```


```c++
int x;
```


```c++
int y;
```


```c++
int x
```


```c++
int stage_id
```


```c++
int randomVar
```


```c++
int randomType; 
```


```c++
string type;
```


```c++
char sala[256];
```

    
##```void Map::GenerateMap()```


###Parameters
```c++
int quantidade_salas;
```


```c++
int stage_id
```


```c++
int x = quantidade_salas/2;
```


```c++
int y = quantidade_salas/2;
```


```c++
int id = 1
```


```c++
matriz;
```


```c++
Room *room;
```


```c++
Room * aux;
```

    
##```void Map::remove_item()```


###Parameters
```c++
Object *item
```


##```Room * Map::room()```


##```void Map::set_current()```
###Parameters
```c++
Room *nova;
```


##```Map::items()```


##```bool Map::on_message()```


###Parameters
```c++
MessageID id;
```


```c++
Parameters p
```


##```void Map::update_self()```


###Parameters
```c++
unsigned long elapsed
```

