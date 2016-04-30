#include "creditos.h"
#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>
#include <cassert>

#include <iostream>
using namespace std;

const string resume_button_path = "res/interface/menuCreditos/voltar.png";
const string resume_button_path_alternative = "res/interface/menuCreditos/Svoltar.png";

Creditos::Creditos()
    : Level("creditos")
{
    //// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();

    assert(env != NULL && "Failed to pick up the instance of environment");

    double w = env->canvas->w();
    double h = env->canvas->h();

    set_dimensions(w, h);

    Button *back = new Button(this, "back", resume_button_path,
                              resume_button_path_alternative);

    assert(back != NULL && "Failed to create resume button.");

    back->align_to(this, Object::RIGHT, Object::RIGHT);
    back->set_y(520);

    back->add_observer(this);
    add_child(back);

}
Creditos::~Creditos()
{
}

void
Creditos::draw_self()
{
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");
    env->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuCreditos/telaCreditos.png");
    assert(image != NULL && "Unable to find telaCreditos.png path");
    env->canvas->draw(image.get(), 1, 0);
}

bool
Creditos::on_message(Object *object, MessageID id, Parameters)
{

    assert((object != NULL) && "Object needs to be different from NULL");
    assert((not id.empty()) && "id needs to be different drom the empty");

    if (id != Button::clickedID)
    {
        return false;
    }

    Button *button = dynamic_cast <Button *>(object);

    if (not button)
    {
        return false;
    }
    if (button->id() == "back")
    {
        set_next("title");
    }

    finish();

    return true;
}
