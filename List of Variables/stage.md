#Class stage

##Stage::Stage()

·ObjectID id → parameter from constructor Item(), it's the object's id

·int lives → parameter from constructor Item(), it's quantity of player's lifes (Min: 0 / Max: 3)

·double * sanity → parameter from constructor Item(), it's the quantity of player's sanity (Min: 0 / Max: 100)

·char aux[10] → temporary saves the number of the current room

·char temp[10] → temporary saves the id of the room

·int quantidade_de_salas → quantity of rooms (Min: 3 / Max: )

·Player * m_player → instances the player character

·Map * m_map → instances a map with the current quantity of rooms

·int m_num_id → receive temporarily the number of the current room

·double health → set the quantity of player's health (Min: 0 / Max: 100)

##Stage::update_self()

·unsigned long → parameter from update_self. It's just an parameter required by the interface

·const list<Object*> map_filhos → receive the list of the current room's objects

·Rect a → bouding box of player

·Rect b → bounding box of one of room's object

·Rect c → the intersection of the bounding boxes of player and room's object

·auto filho → iterator for map_filhos

·Boss * boss → object final boss

·const list<Object * > items → list of all items of the map

·auto item → iterator for items

·char message[512] → receive player's info and convert to a string

·Guard * guarda → guard's object

·const list<Object * > filhos → list of all items of the map

·Environment * env → set the game's ambient

·Rect a2 → bouding box of player

·Rect b2 → bounding box of one of room's guard

·Rect c2 → the intersection of the bounding boxes of player and room's guard

·Ghost * ghost → ghost's object

##Stage::on_message()

·Object * → parameter required by interface

·MessageID id → message's type {hitExitDoorID,changeRoomID,jumpNextLevelID,repeatLevelID,takeItemID,openDoorID,pushItemID,getHitID,guardDeathID}

·Parameters p → door side that the player entered {left, top, right, bottom}

·char new_stage[256] → receive new stage id

·const list<Object * > npcs → non playable characters of the current room

·double dmg → damage receive by guards {Min: / Max: }
