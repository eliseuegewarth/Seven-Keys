/*
 * Implementação da classe TitleScreen.
 *
 * Autor: Edson Alves
 * Data: 29/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "titlescreen.h"
 
#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>

#include <iostream>
using namespace std;

TitleScreen::TitleScreen()
    : Level("title")
{
    Environment *env = Environment::get_instance();

    double w = env->canvas->width();
    double h = env->canvas->height();

    set_dimensions(w, h);

    Button *jogar = new Button(this, "jogar", "res/interface/menuInicial/jogar.png",
        "res/interface/menuInicial/Sjogar.png");
    jogar->align_to(this, Object::RIGHT , Object::MIDDLE);

    Button *options = new Button(this, "options", "res/interface/menuInicial/opcao.png",
        "res/interface/menuInicial/Sopcao.png");
    options->align_to(this, Object::RIGHT, Object::NONE);
    options->set_y(jogar->y() + jogar->h() + 15);

    Button *creditos = new Button(this, "creditos", "res/interface/menuInicial/creditos.png",
        "res/interface/menuInicial/Screditos.png");
    creditos->align_to(this, Object::RIGHT, Object::NONE);
    creditos->set_y(options->y() + options->h()+15);

    Button *exit = new Button(this, "exit", "res/interface/menuInicial/sair.png",
        "res/interface/menuInicial/Ssair.png");
    exit->align_to(this, Object::RIGHT, Object::NONE);
    exit->set_y(creditos->y() + creditos->h() + 15);

    Button *extras = new Button (this, "extras", "res/interface/menuInicial/extras.png",
        "res/interface/menuInicial/Sextras.png");
    creditos->align_to(this, Object::MIDDLE, Object::NONE);
    extras->set_y(creditos->y() +creditos->h() + 15);

    jogar->add_observer(this);
    options->add_observer(this);
    creditos->add_observer(this);
    exit->add_observer(this);
    extras->add_observer(this);

    add_child(jogar);
    add_child(options);
    add_child(creditos);
    add_child(exit);
    add_child(extras);
}

TitleScreen::~TitleScreen()
{
}

void
TitleScreen::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuInicial/menuInicial.png");
    env->canvas->draw(image.get(), 1, 0);
}

bool
TitleScreen::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    Button *button = dynamic_cast<Button *>(object);
    Environment *env = Environment::get_instance();
    if (not button)
    {
        return false;
    }

    if (button->id() == "jogar")
    {
        set_next("trans1");
    } else if (button->id() == "options")
    {
        env->sfx->play("res/sounds/navegacaomenu.wav", 1);
        set_next("options");
    }
    else if(button->id() == "creditos")
        set_next("creditos");
    else if (button-> id() == "extras")
        set_next("extras");

    finish();

    return true;
}
