#Class stage

##Stage::Stage()

·ObjectID id
·int lives
·double * sanity
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
