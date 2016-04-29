#include "extras.h"

#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>
//#include <smpeg/smpeg.h>

#include <iostream>
using namespace std;

Extras::Extras() : Level("extras") // Creates the environment of the extras menu.
{
    Environment *env = Environment::get_instance(); // It is an object of the class environment. Is a pointer to the current instance of the game environment.

    double w = env->canvas->w(); // Receives the width of the game environment.
    double h = env->canvas->h(); // Receives the height of the game environment.

    set_dimensions(w, h);

    Button *cutscene = new Button(this, "cutscene", "res/interface/menuExtras/cutscenes.png",
        "res/interface/menuExtras/Scutscenes.png"); // Directs to the cutscene of the game.
    cutscene->align_to(this, Object::MIDDLE, Object::NONE);
    cutscene->set_y(200);
    Button *historia = new Button(this, "historia", "res/interface/menuExtras/historia.png",
        "res/interface/menuExtras/Shistoria.png");// Directs to the history of the game.
    historia->align_to(this, Object::MIDDLE, Object::NONE);
    historia->set_y(cutscene->y() + cutscene->h()+20);

    Button *back = new Button(this, "back", "res/interface/menuExtras/voltar.png",
        "res/interface/menuExtras/Svoltar.png");// Directs to the main menu of the game.
    back->align_to(this, Object::MIDDLE, Object::NONE);
    back->set_y(historia->y() + historia->h()+20);

    cutscene->add_observer(this);
    historia->add_observer(this);
    back->add_observer(this);

    add_child(cutscene);
    add_child(historia);
    add_child(back);

}

Extras::~Extras()
{
}

void Extras::draw_self()// Drow extras pinctures on the screen.
{
    Environment *env = Environment::get_instance(); // It is an object of the class environment. Is a pointer to the current instance of the game environment.
    env->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuExtras/menuExtras.png");
    env->canvas->draw(image.get(), 1, 0);
}

bool Extras::on_message(Object *object, MessageID id, Parameters) // Let the dynamic buttons.
{
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
/*
SMPEG * inicializa_smpeg ("res/extras/celera.mpg", U
SDL_Surface * tela);

SMPEG *mpeg;

int skip, sair;

mpeg = NULL;

skip = 0;
sair = 0;

SMPEG_play (mpeg);
*/
