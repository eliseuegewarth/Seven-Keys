#Class stage

##Stage::Stage()

·ObjectID id → parameter from constructor Item(), it's the object's id

·int lives → parameter from constructor Item(), it's quantity of player's lifes (Min: 0 / Max: 3)

·double * sanity → parameter from constructor Item(), it's the quantity of player's sanity (Min: 0 / Max: 100)

·char aux[10]

·char temp[10]

·int quantidade_de_salas

##Stage::update_self()

·unsigned long

·const list<Object*> map_filhos

·Rect a

·Rect b

·Rect c

·Boss * boss

·const list<Object * > items

·char message[512]

·Guard * guarda

·const list<Object * > filhos

·Environment * env

·Rect a2

·Rect b2

·Rect c2

·Ghost * ghost

##Stage::on_message()

·Object *

·MessageID id

·Parameters p

·char new_stage[256]

·const list<Object * > npcs

·double dmg
