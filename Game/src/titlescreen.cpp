/*
 * Implementação da classe TitleScreen.
 *
 * Autor: Edson Alves
 * Data: 29/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "titlescreen.hpp"
#include "internacionalization.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"

#include <iostream>
using namespace std;

TitleScreen::TitleScreen()
    : Level("title")
{
    Environment *env = Environment::get_instance();

    double width = env->canvas->width();
    double height = env->canvas->height();

    set_dimensions(width, height);

    string path_play_button = Internacionalization::load_string("interface/menuInicial/jogar.png");
    string path_Splay_button = Internacionalization::load_string("interface/menuInicial/Sjogar.png");
    Button *jogar = new Button(this, "jogar", path_play_button, path_Splay_button);
    jogar->align_to(this, Object::RIGHT , Object::MIDDLE);

    string path_option_button = Internacionalization::load_string("interface/menuInicial/opcao.png");
    string path_Soption_button = Internacionalization::load_string("interface/menuInicial/Sopcao.png");
    Button *options = new Button(this, "options", path_option_button, path_Soption_button);
    options->align_to(this, Object::RIGHT, Object::NONE);
    options->set_vertical_position(jogar->vertical_position() + jogar->height() + 15);

    string path_credits_button = Internacionalization::load_string("interface/menuInicial/creditos.png");
    string path_Scredits_button = Internacionalization::load_string("interface/menuInicial/Screditos.png");
    Button *creditos = new Button(this, "creditos", path_credits_button, path_Scredits_button);
    creditos->align_to(this, Object::RIGHT, Object::NONE);
    creditos->set_vertical_position(options->vertical_position() + options->height()+15);

    string path_exit_button = Internacionalization::load_string("interface/menuInicial/sair.png");
    string path_Sexit_button = Internacionalization::load_string("interface/menuInicial/Ssair.png");
    Button *exit = new Button(this, "exit", path_exit_button, path_Sexit_button);
    exit->align_to(this, Object::RIGHT, Object::NONE);
    exit->set_vertical_position(creditos->vertical_position() + creditos->height() + 15);

    string path_extras_button = Internacionalization::load_string("interface/menuInicial/extras.png");
    string path_Sextras_button = Internacionalization::load_string("interface/menuInicial/Sextras.png");
    Button *extras = new Button (this, "extras", path_extras_button, path_Sextras_button);
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

    string path_main_menu = Internacionalization::load_string("interface/menuInicial/menuInicial.png");
    shared_ptr<Texture> image = env->resources_manager->get_texture(path_main_menu);
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
