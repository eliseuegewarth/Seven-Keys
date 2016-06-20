#include "options.hpp"

#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>
#include <core/mousemotionevent.h>
#include <iostream>
using namespace std;

Options::Options() : Level("options")// Class that represents the option of the main menu of the game.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    double width = env->canvas->width();// Receives the width of the game environment.
    double height = env->canvas->height();// Receives the height of the game environment.

    set_dimensions(width, height);

    Button *set_fullscreen = new Button(this, "fullscreen", "res/interface/menuOpcao/modoJanela.png",
        "res/interface/menuOpcao/SmodoJanela.png");// Puts the screen in fullscreen.
    set_fullscreen->align_to(this, Object::RIGHT, Object::MIDDLE);

    Button *windowmode = new Button(this, "windowmode", "res/interface/menuOpcao/comoJogar.png",
        "res/interface/menuOpcao/ScomoJogar.png");// Puts the screen in windowed mode.
    windowmode->align_to(this, Object::RIGHT, Object::NONE);
    windowmode->set_y(set_fullscreen->y() + set_fullscreen->height() + 20);

    Button *back = new Button(this, "back", "res/interface/menuOpcao/voltar.png",
        "res/interface/menuOpcao/Svoltar.png");// Directs to the main menu of the game.
    back->align_to(this, Object::RIGHT, Object::NONE);
    back->set_y(windowmode->y() + windowmode->height() + 20);

    set_fullscreen->add_observer(this);
    windowmode->add_observer(this);
    back->add_observer(this);

    add_child(set_fullscreen);
    add_child(windowmode);
    add_child(back);



}

Options::~Options()
{
}

void Options::draw_self()// Drow options pinctures on the screen.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    env->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuOpcao/menuOpcao.png");
    env->canvas->draw(image.get(), 1, 0);
}

bool Options::on_message(Object *object, MessageID id, Parameters)// Let the dynamic buttons.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Button *button = dynamic_cast<Button *>(object);
    env->sfx->play("res/sounds/navegacaomenu.wav", 1);

    if (id != Button::clickedID)
    {
        return false;
    }

    if (not button)
    {
        return false;
    }

    if(button->id() == "fullscreen" || button->id() == "windowmode" || button->id() == "back")
            env->sfx->play("res/sounds/navegacaomenu.wav",1);

    if (button->id() == "fullscreen")
    {
        env->video->set_fullscreen();
        set_next("options");
    }
    else if (button->id() == "windowmode")
    {
        env->video->set_fullscreen(false);
        set_next("options");
    }

    else if (button->id() == "back")
    {
        set_next("title");
    }

    finish();

    return true;
}
