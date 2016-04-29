#include "pause.h"

#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>

#include <iostream>
using namespace std;

Pause::Pause() : Level("pause")// Creates the environment of the pause menu.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.

    double w = env->canvas->w();// Receives the width of the game environment.
    double h = env->canvas->h();// Receives the height of the game environment.

    set_dimensions(w, h);

    Button *backGame = new Button(this, "backGame", "res/interface/menuPausa/voltarJogo.png",
        "res/interface/menuPausa/SvoltarJogo.png");// Directs the environment where the game was paused.
    backGame->align_to(this, Object::RIGHT, Object::NONE);
    backGame->set_y(200);

    Button *backMenu = new Button(this, "backMenu", "res/interface/menuExtras/voltar.png",
        "res/interface/menuExtras/Svoltar.png");// Directs to the main menu of the game.
    backMenu->align_to(this, Object::RIGHT, Object::NONE);
    backMenu->set_y(backGame->y() + backGame->h()+20);

    Button *exit = new Button(this, "exit", "res/interface/menuExtras/sair.png",
        "res/interface/menuExtras/Ssair.png");// Closes the game.
    exit->align_to(this, Object::RIGHT, Object::NONE);
    exit->set_y(backGame->y() + backGame->h()+20);

    backGame->add_observer(this);
    backMenu->add_observer(this);
    exit->add_observer(this);

    add_child(backGame);
    add_child(backMenu);
    add_child(exit);

}

Pause::~Pause()
{
}

void Pause::draw_self() // Drow pause pinctures on the screen.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    env->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuPausa/fundoPausa.png");
    env->canvas->draw(image.get(), 1, 0);
}

bool Pause::on_message(Object *object, MessageID id, Parameters)// Let the dynamic buttons.
{
    // It is an object of the class environment. Is a pointer to the current instance of the game environment.
    //Environment *env = Environment::get_instance(); NOT USED.

    if (id != Button::clickedID)
    {
        return false;
    }

    Button *button = dynamic_cast <Button *>(object);

    if (not button)
    {
        return false;
    }
    if (button->id() == "backGame")
    {
        return false;
    } else if (button->id() == "backMenu")
    {
        set_next("title");
    }

    finish();

    return true;
    
}


