#Room

####Constants
    ·INFINITE 99999.9

##```class Guard;```

##```class Room: public Object```
###Class Members
```c++
·Room *r_left;
```
```c++
·Room *r_right;
```
```c++
·Room *r_top;
```
```c++
·Room *r_bottom;
```
```c++
·int stage_id;
```
```c++
·int pos_x;
```
```c++
·int pos_y;
```
```c++
·list <Object *> items;
```
```c++
·const list<Object *>& get_items();
```
```c++
·Guard *m_guard;
```
```c++
·bool m_doors;
```
```c++
·Rect center_area;
```

##```void draw_items();```

##```void pre_drawing();```
###Parameters
```c++
·const string item_name
```
```c++
·string item_type
```
```c++
·int percentage,
```
```c++
·int pos_x
```
```c++
·int pos_y
```
```c++
·int width
```
```c++
·int height
```
```c++
·bool walkable
```

##```ActionID Room::guardDeathID { "guardDeathID()" };```

##```static int randint()```
###Parameters
```c++
·int a
```
```c++
·int b
```
###Variables and Methods
```c++
·int N
```
```c++
·int r
```

##```Room::Room```
###Parameters
```c++
·Object *parent
```
```c++
·ObjectID id
```
```c++
·string type
```
```c++
·Room *left
```
```c++
·Room *top
```
```c++
·Room *right
```
```c++
·Room *bottom
```
```c++
·int s_id
```
###Variables and Methods
```c++
·Environment *env = Environment::get_instance();
```
```c++
·quad = new Quadtree
```

##```Room::~Room()```

##```string Room::room_type()```

##```void Room::add_items()```
###Parameters
    ·int stage_id
###Variables and Methods
```c++
·list<ItemInfo> items;
```
```c++
·int total_weight
```
```c++
·char prepath[256];
```
```c++
·char newpath[256];
```
```c++
·Item* item
```
```c++
·static const int MAX_ITENS
```
```c++
·int num_items
```
```c++
·int p
```
```c++
·int total
```
```c++
·char path[512];
```
```c++
·char prepath[256];
```
```c++
·int variation
```
```c++
·double x
```
```c++
·double y
```
```c++
·Item* item
```


####```struct _ItemInfo```
#####Variables
```c++
·string name;
```
```c++
·string type;
```
```c++
·int variations;
```
```c++
·int weight;
```
```c++
·bool walkable;
```
```c++
·bool unique;
```
```c++
·double mass;
```
```c++
·int x
```
```c++
·int y;
```

##```void Room::add_list()```
###Parameters
    ·Object  * item

###Variables
    ·const list<Object * >&

##```Room::get_items()```

##```void Room::check_entry()```
```c++
Environment * env = Environment::get_instance();
```
##```void Room::draw_id()```
###Parameters
```c++
·Room * anterior
```
```c++
·Room * sala
```
```c++
·int x
```
```c++
·int y
```
###Variables and Methods
```c++
·Environment * env = Environment::get_instance();
```

##```void Room::draw_self()```
###Variables and Methods
```c++
·Environment *env = Environment::get_instance();
```
##```void Room::add_door()```
###Parameters
```c++
·string type
```
```c++
·char direction
```
```c++
·int x
```
```c++
·int y
```
###Variables and Methods
```c++
·char doorID[128];
```
```c++
·char door_sprite[256];
```
```c++
·int stages = 1;
```
```c++
·Item *porta = new Item
```
```c++
·Item *porta = new Item
```
```c++
·const list<Object *> items = this->children();
```
```c++
·char buffer[256];
```


##```void Room::add_final_door()```
```c++
·double x
```
```c++
·double y
```
```c++
·char dir;
```

##```void Room::remove_item()```
###Parameters
```c++
·Object *item
```


##```void Room::fill_floor()```
###Parameters
```c++
·const string& name
```
###Variables and Methods
```c++
·char path[512];
```
```c++
·int stages = 1;
```
```c++
·Image *image = new Image(nullptr, name, path);
```
```c++
·Environment *env = Environment::get_instance();
```
```c++
·Canvas *canvas = env->canvas;
```
```c++
·int w = canvas->w() / image->w();
```
```c++
·int h = canvas->h() / image->h();
```
```c++
·Item *floor = new Item
```


##```void Room::add_walls()```
###Parameters
```c++
·const string& name
```
###Variables and Methods
```c++
·Environment *env = Environment::get_instance();
```
```c++
·Canvas *canvas
```
```c++
·char pos[4]
```
```c++
·char path[512];
```
```c++
·int stages = 1;
```
```c++
·Image *image
```
```c++
·double x
```
```c++
·double y
```
```c++
·Item *wall
```

##```void Room::add_corners()```
###Parameters
```c++
·const string& name
```

###Variables and Methods
```c++
·Environment *env = Environment::get_instance();
```
```c++
·Canvas *canvas = env->canvas;
```
```c++
·char path[512];
```
```c++
·int stages = 1;
```
```c++
·Image *image = new Image
```
```c++
·double x
```
```c++
·double y
```
```c++
·Item *corner = new Item
```

##```void Room::add_guard()```
###Parameters
```c++
·const string& name
```
###Variables and Methods
```c++
·string type = "easy";
```
```c++
·int random = randint(0,2);
```
```c++
·Guard *guard = new Guard
```

##```void Room::add_ghost()```
###Parameters
```c++
·const string& name
```
###Variables and Methods
```c++
·string type = "easy";
```
```c++
·int i
```

##```bool Room::place()```
###Parameters
```c++
·Object *object
```
```c++
·double x
```
```c++
·double y
```
###Variables and Methods
```c++
·int w
```
```c++
·int h
```
```c++
·int tries
```
```c++
·Rect a
```
```c++
·Rect b
```
```c++
·Rect c
```

##```void Room::notify_creation()```
###Parameters
```c++
·const string& position
```

##```void Room::update_self()```
###Parameters
```c++
·unsigned long
```
###Variables and Methods
```c++
·Rect a
```
```c++
·Rect b
```
```c++
·Rect c
```
```c++
·Guard * guarda
```
```c++
·Guard * guarda
```
```c++
·Ghost *ghost
```
```c++
·string path;          
```
```c++
·const list<Object *> npcs = children();
```
```c++
·Item *body = new Item
```
