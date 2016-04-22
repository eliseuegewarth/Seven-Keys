#Credits

##Creditos::Creditos()

·double w → screen width

·double h → screen hight

·Button * back → back to main menu

##Creditos::draw_self()

·Environment * env → using for set the ambient

·shared_ptr<Texture> image → load credits image

##Creditos::on_message()

·Object * object → paramenter from on_message()

·MessageID id → paramenter from on_message()

·Button * button → dinamically casts an object for back to detect if the back button was clicked.
