# Seven Keys

# Class Room

```c++
ActionID Room::guardDeathID { "guardDeathID()" };
```

```c++
static int randint
```

```c++
int a
```

```c++
int b
```

```c++
int N
```

```c++
int r
```

```c++
struct _ItemInfo
```

```c++
string name
```

```c++
string type
```

```c++
int variations
```

```c++
int weight
```

```c++
bool walkable
```

```c++
bool unique
```

```c++
double mass
```

```c++
int x
```

```c++
int y
```

```c++
Room::Room(Object *parent, ObjectID id, string type, Room *left, Room *top, Room *right, Room *bottom, int s_id)
          :Object(parent, id), r_left(left), r_right(right), r_top(top), r_bottom(bottom), type(type), stage_id(s_id),
          m_doors(false)
```

```c++
Environment *env = Environment::get_instance()
```

```c++
quad = new Quadtree(0, new Rect(0, 0, env->canvas->w(), env->canvas->h()))
```

```c++
Room::~Room()
```

```c++
string Room::room_type()
```

```c++
void Room::add_items(int stage_id)
```

```c++
typedef struct _ItemInfo{} ItemInfo
```

```c++
string name
```

```c++
string type
```

```c++
int variations
```

```c++
int weight
```

```c++
bool walkable
```

```c++
bool unique
```

```c++
double mass
```

```c++
int x
```

```c++
int y
```



```c++
list<ItemInfo> items;
```

```c++
int total_weight = 0
```

```c++
char prepath[256];
```


```c++
char newpath[256];
```

```c++
Item* item = new Item(this, "key", newpath, 300, 300, 1.0, true);
```

```c++
static const int MAX_ITENS = 15;
```

```c++
int num_items = randint(0, MAX_ITENS);
```

```c++
int p = randint(1, total_weight);
```

```c++
int total = it->weight;
```

```c++
char path[512];
```

```c++
char prepath[256];
```

```c++
double x = it->x;
```

```c++
double y = it->y;
```

```c++
Item* item = new Item(this, it->name, path, x, y, it->mass, it->walkable);
```

```c++
Room::add_list(Object  * item)
```

```c++
Room::get_items()
```

```c++
void Room::draw_id(Room * anterior, Room * sala, int x, int y)
```

```c++
void Room::draw_self()
```

```c++
Environment *env = Environment::get_instance();
```

```c++
void Room::add_door(string type, char direction, int x, int y)
```

```c++
char doorID[128];
```

```c++
char door_sprite[256];
```

```c++
int stages = 1;
```

```c++
Item *porta = new Item(this, "door", door_sprite, x, y, INFINITE, true);
```

```c++
Item *porta = new Item(this, "finalDoor", door_sprite, x, y, INFINITE, true);
```

```c++
const list<Object *> items = this->children();
```

```c++
char buffer[256];
```


```c++
void Room::add_final_door()
```

```c++
double x = 0 + (r_top || r_bottom)*600 + (bool)r_left*1200;
```

```c++
double y = 0 + (r_left || r_right)*320 + (bool)r_top*640;
```

```c++
char dir;
```

```c++
void Room::remove_item(Object *item)
```

```c++
void Room::fill_floor(const string& name)
```

```c++
char path[512];
```

```c++
int stages = 1;
```
```c++
Image *image = new Image(nullptr, name, path);
```
```c++
Environment *env = Environment::get_instance();

```
```c++
Canvas *canvas = env->canvas;

```
```c++
int w = canvas->w() / image->w();

```
```c++
int h = canvas->h() / image->h();

```

```c++
Item *floor = new Item(this, name, path, i*image->w(), j*image->h(), INFINITE, true);
add_child(floor);

```
```c++
void Room::add_walls(const string& name)

```
```c++
Environment *env = Environment::get_instance();

```
```c++
Canvas *canvas = env->canvas;

```
```c++
char pos[4] = {'l', 't', 'r', 'b'};

```
```c++
char path[512];

```
```c++
int stages = 1;

```
```c++
Image *image = new Image(nullptr, name, path);

```
```c++
double x = i % 2 ? image->w()*j : i/2 * (canvas->w() - image->w());

```
```c++
double y = i % 2 ? i/2 * (canvas->h() - image->h()) : image->h()*k;

```

```c++
Item *wall = new Item(this, name, path, x, y, INFINITE, false);
add_child(wall);

```
```c++
void Room::add_corners(const string& name)

```
```c++
Environment *env = Environment::get_instance();

```
```c++
Canvas *canvas = env->canvas;

```

```c++
char path[512];

```
```c++
Image *image = new Image(nullptr, name, path);

```
```c++
double x = i % 3 ? canvas->w() - image->w() : 0;

```
```c++
double y = i/2 ? canvas->h() - image->h() : 0;

```

```c++
Item *corner = new Item(this, name, path, x, y, INFINITE, false);
add_child(corner);

```
```c++
void Room::add_guard(const string& name)

```
```c++
int random = randint(0,2);

```
```c++
Guard *guard = new Guard(this, name, 0, 0, 60, false, type, randint(0,3));

```
```c++

void Room::add_ghost(const string& name)
```
```c++
Ghost *ghost = new Ghost(this, name, 0, 0, 9999, true, "normal", randint(0,3));

```
```c++
bool Room::place(Object *object, double x, double y)

```
```c++
int w = center_area.w();

```
```c++
int h = center_area.h();

```
```c++
int tries = 0;

```

```c++
Rect a { x, y, object->w(), object->h() };

```
```c++
Rect b = obj->bounding_box();

```
```c++
Rect c = a.intersection(b);

```

```c++
void Room::notify_creation(const string& position)

```
```c++
void Room::update_self(unsigned long)

```
```c++

const list<Object *> npcs = children();
```
```c++
Rect a = npc2->bounding_box();

```
```c++
Rect b = npc->bounding_box();

```
```c++
Rect c = a.intersection(b);

```

```c++
Guard * guarda = (Guard*) npc;

```

```c++
Ghost *ghost = new Ghost(this, "ghost", 0, 0, 9999, true, guarda->m_old_type, randint(0,3));

```
```c++
string path;

```
```c++
Item *body = new Item(this, "body", path, 0, 0, 9999, true);

```
