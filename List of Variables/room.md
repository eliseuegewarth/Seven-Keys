#Room

###variables
    ·INFINITE 99999.9

class Guard;

class Room: public Object
	·Room *r_left;
	·Room *r_right;
	·Room *r_top;
	·Room *r_bottom;
	·int stage_id;
	·int pos_x;
	·int pos_y;
	·list <Object *> items;
    ·const list<Object *>& get_items();
	·Guard *m_guard;
    ·bool m_doors;
    ·Rect center_area;

##void draw_items();

##void pre_drawing();
###parameters
    ·const string item_name
    ·string item_type
    ·int percentage,
	·int pos_x
    ·int pos_y
    ·int width
    ·int height
    ·bool walkable

#ActionID Room::guardDeathID { "guardDeathID()" };

##static int randint()
###parameters
    ·int a
    ·int b
###variables and methods
    ·int N
    ·int r

##Room::Room
###parameters
    ·Object *parent
    ·ObjectID id
    ·string type
    ·Room *left
    ·Room *top
    ·Room *right
    ·Room *bottom
    ·int s_id
###variables and methods
    ·Environment *env = Environment::get_instance();
    ·quad = new Quadtree

##Room::~Room()

##string Room::room_type()

##void Room::add_items()
###parameters
    ·int stage_id
###variables and methods
    ·list<ItemInfo> items;
    ·int total_weight
    ·char prepath[256];
    ·char newpath[256];
    ·Item* item
    ·static const int MAX_ITENS
    ·int num_items
    ·int p
    ·int total
    ·char path[512];
    ·char prepath[256];
    ·int variation
    ·double x
    ·double y
    ·Item* item

####struct _ItemInfo
#####variables
    ·string name;
    ·string type;
    ·int variations;
    ·int weight;
    ·bool walkable;
    ·bool unique;
    ·double mass;
    ·int x
    ·int y;

##void Room::add_list()
###parameters
    ·Object  * item

###variables
    ·const list<Object *>&

##Room::get_items()

##void Room::check_entry()
    ·Environment *env = Environment::get_instance();

##void Room::draw_id()
###parameters
    ·Room * anterior
    ·Room * sala
    ·int x
    ·int y
###variables and methods
    ·Environment *env = Environment::get_instance();

##void Room::draw_self()
###variables and methods
    ·Environment *env = Environment::get_instance();

##void Room::add_door()
###parameters
    ·string type
    ·char direction
    ·int x
    ·int y
###variables and methods
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

##void Room::remove_item()
###parameters
    ·Object *item

##void Room::fill_floor()
###parameters
    ·const string& name
###variables and methods
    ·char path[512];
    ·int stages = 1;
    ·Image *image = new Image(nullptr, name, path);
    ·Environment *env = Environment::get_instance();
    ·Canvas *canvas = env->canvas;
    ·int w = canvas->w() / image->w();
    ·int h = canvas->h() / image->h();
    ·Item *floor = new Item

##void Room::add_walls()
###parameters
    ·const string& name
###variables and methods
    ·Environment *env = Environment::get_instance();
    ·Canvas *canvas = env->canvas;
    ·char pos[4] = {'l', 't', 'r', 'b'};
    ·char path[512];
    ·int stages = 1;
    ·Image *image = new Image(nullptr, name, path);
    ·double x
    ·double y
    ·Item *wall = new Item

##void Room::add_corners()
###parameters
    ·const string& name
###variables and methods
    ·Environment *env = Environment::get_instance();
    ·Canvas *canvas = env->canvas;
    ·char path[512];
    ·int stages = 1;
    ·Image *image = new Image
    ·double x
    ·double y
    ·Item *corner = new Item

##void Room::add_guard()
###parameters
    ·const string& name
###variables and methods
    ·string type = "easy";
    ·int random = randint(0,2);
    ·Guard *guard = new Guard

##void Room::add_ghost()
###parameters
    ·const string& name
###variables and methods
    ·string type = "easy";
    ·int i

##bool Room::place()
###parameters
    ·Object *object
    ·double x
    ·double y
###variables and methods
    ·int w
    ·int h
    ·int tries
    ·Rect a
    ·Rect b
    ·Rect c

##void Room::notify_creation()
###parameters
    ·const string& position

##void Room::update_self()
###parameters
    ·unsigned long
###variables and methods
    ·Rect a
    ·Rect b
    ·Rect c
    ·Guard * guarda
    ·Guard * guarda
    ·Ghost *ghost
    ·string path;          
    ·Item *body = new Item
    ·const list<Object *> npcs = children();
