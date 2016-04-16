#Map.cpp

## class Boss : public Object


###Map::Map
    int qnt_salas
    int stage_id
    GenerateMap(qnt_salas, stage_id);
    Boss *boss = new Boss(this, "boss", 0, 0, 999, true, Boss::LEFT);

###void Map::CreateRoom()
    Room *room
    int *id
    int x
    int y
    int qnt
    int stage_id
    int randomVar
    int randomType = rand() % 3 
    string type
    char sala[256]
  
// Generate all the map
###void Map::GenerateMap()
    int quantidade_salas
    int stage_id
    int x = quantidade_salas/2
    int y = quantidade_salas/2
    int id = 1
    matriz = (bool**) malloc(sizeof(bool*)*(quantidade_salas));
    Room *room = new Room(this, "sala 0", "None", nullptr, nullptr, nullptr, nullptr, stage_id);
    Room * aux = room_list.at(rand() % id);
    
    
###void Map::remove_item()
    Object *item

###Room * Map::room()

###void Map::set_current()
    Room *nova

###Map::items() 

###bool Map::on_message()
    MessageID id
    Parameters p

###void Map::update_self()
    unsigned long elapsed
