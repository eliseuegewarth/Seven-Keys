/*
 * Implementação da classe TitleScreen.
 *
 * Autor: Edson Alves
 * Data: 29/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "titlescreen.hpp"

#include <ijengine/util/button.hpp>
#include <core/font.hpp>
#include <core/environment.hpp>

#include <iostream>
using namespace std;

TitleScreen::TitleScreen()
    : Level("title")
{
    Environment *env = Environment::get_instance();

    double width = env->canvas->width();
    double height = env->canvas->height();

    set_dimensions(width, height);

    Button *jogar = new Button(this, "jogar", "res/EN-US/interface/menuInicial/jogar.png",
        "res/EN-US/interface/menuInicial/Sjogar.png");
    jogar->align_to(this, Object::RIGHT , Object::MIDDLE);

    Button *options = new Button(this, "options", "res/EN-US/interface/menuInicial/opcao.png",
        "res/EN-US/interface/menuInicial/Sopcao.png");
    options->align_to(this, Object::RIGHT, Object::NONE);
    options->set_vertical_position(jogar->vertical_position() + jogar->height() + 15);

    Button *creditos = new Button(this, "creditos", "res/EN-US/interface/menuInicial/creditos.png",
        "res/EN-US/interface/menuInicial/Screditos.png");
    creditos->align_to(this, Object::RIGHT, Object::NONE);
    creditos->set_vertical_position(options->vertical_position() + options->height()+15);

    Button *exit = new Button(this, "exit", "res/EN-US/interface/menuInicial/sair.png",
        "res/EN-US/interface/menuInicial/Ssair.png");
    exit->align_to(this, Object::RIGHT, Object::NONE);
    exit->set_vertical_position(creditos->vertical_position() + creditos->height() + 15);

    Button *extras = new Button (this, "extras", "res/EN-US/interface/menuInicial/extras.png",
        "res/EN-US/interface/menuInicial/Sextras.png");
    creditos->align_to(this, Object::MIDDLE, Object::NONE);
    extras->set_vertical_position(creditos->vertical_position() +creditos->height() + 15);

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

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/EN-US/interface/menuInicial/menuInicial.png");
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
