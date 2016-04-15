#Room

##ActionID Room::guardDeathID { "guardDeathID()" };

##static int randint(int a, int b)
    ·int N
    ·int r

##Room::Room
    ·Object *parent
    ·ObjectID id
    ·string type
    ·Room *left
    ·Room *top
    ·Room *right
    ·Room *bottom
    ·int s_id
    ·Environment *env = Environment::get_instance();
    ·quad = new Quadtree

##Room::~Room()

##string Room::room_type()

##void Room::add_items(int stage_id)
·typedef struct _ItemInfo {
·string name;
·string type;
·int variations;
·int weight;
·bool walkable;
·bool unique;
·double mass;
·int x
·int y;

·list<ItemInfo> items;
·int total_weight
·char prepath[256];
·sprintf(prepath,"res/items/");
·char newpath[256];
·Item* item = new Item
·static const int MAX_ITENS
·int num_items
·int p
·int total
·char path[512];
·char prepath[256];
·int variation = randint(1, it->variations);
·double x
·double y
·Item* item = new Item

##void Room::add_list(Object  * item)
·const list<Object *>&

##Room::get_items()

##void Room::check_entry()
·Environment *env = Environment::get_instance();

##void Room::draw_id(Room * anterior, Room * sala, int x, int y)
·Environment *env = Environment::get_instance();

##void Room::draw_self()
·Environment *env = Environment::get_instance();

##void Room::add_door(string type, char direction, int x, int y)
·char doorID[128];
·char door_sprite[256];
·int stages = 1;
·Item *porta = new Item
·Item *porta = new Item
·const list<Object *> items = this->children();
·char buffer[256];

##void Room::add_final_door()
·double x
·double y
·char dir;

##void Room::remove_item(Object *item)

##void Room::fill_floor(const string& name)
·char path[512];
·int stages = 1;
·Image *image = new Image(nullptr, name, path);
·Environment *env = Environment::get_instance();
·Canvas *canvas = env->canvas;
·int w = canvas->w() / image->w();
·int h = canvas->h() / image->h();
Item *floor = new Item

##void Room::add_walls(const string& name)
·Environment *env = Environment::get_instance();
·Canvas *canvas = env->canvas;
·char pos[4] = {'l', 't', 'r', 'b'};
·char path[512];
·int stages = 1;
·Image *image = new Image(nullptr, name, path);
·double x
·double y
·Item *wall = new Item

##void Room::add_corners(const string& name)
·Environment *env = Environment::get_instance();
·Canvas *canvas = env->canvas;
·char path[512];
·int stages = 1;
·Image *image = new Image
·double x
·double y
·Item *corner = new Item

##void Room::add_guard(const string& name)
·string type = "easy";
·int random = randint(0,2);
·Guard *guard = new Guard

##void Room::add_ghost(const string& name)
·string type = "easy";


##bool Room::place(Object *object, double x, double y)
·int w
·int h
·int tries
·Rect a
·Rect b
·Rect c

##void Room::notify_creation(const string& position)

##void Room::update_self(unsigned long)
·Rect a
·Rect b
·Rect c
·Guard * guarda
·Guard * guarda
·Ghost *ghost = new Ghost
·string path;          
·Item *body = new Item
·const list<Object *> npcs = children();
