#Map

##```class Boss : public Object```
###Class members
```c++
int qut_salas
```

```c++
int stage_id
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
int x
```
```c++
int y
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
int randomType = rand() % 3 
```
```c++
string type
```
```c++
char sala[256]
```
```c++

```
    
##```void Map::GenerateMap()```
###Parameters
```c++
int quantidade_salas
```
```c++
int stage_id
```
```c++
int x = quantidade_salas/2
```
```c++
int y = quantidade_salas/2
```
```c++
int id = 1
```
```c++
matriz = (bool**) malloc(sizeof(bool*)*(quantidade_salas));
```
```c++
Room *room = new Room(this, "sala 0", "None", nullptr, nullptr, nullptr, nullptr, stage_id);
```
```c++
Room * aux = room_list.at(rand() % id);
```
    
##```void Map::remove_item()```
###Parameters
```c++
Object *item
```
```c++

```
##```Room * Map::room()```

##```void Map::set_current()```
###Parameters
```c++
Room *nova
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