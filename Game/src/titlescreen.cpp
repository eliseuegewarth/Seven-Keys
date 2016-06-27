/*
 * Implementação da classe TitleScreen.
 *
 * Autor: Edson Alves
 * Data: 29/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "titlescreen.hpp"
#include "7keys.hpp"
#include "internacionalization.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"

#include <iostream>
using namespace std;

#define PATH_OF_MUSIC_MENU "res/sounds/navegacaomenu.wav"
#define PLAY_BUTTON_PATH "interface/menuInicial/jogar.png"
#define ON_FOCUS_PLAY_BUTTON_PATH "interface/menuInicial/Sjogar.png"
#define OPTIONS_BUTTON_PATH "interface/menuInicial/opcao.png"
#define ON_FOCUS_OPTIONS_BUTTON_PATH "interface/menuInicial/Sopcao.png"
#define CREDITS_BUTTON_PATH "interface/menuInicial/creditos.png"
#define ON_FOCUS_CREDITS_BUTTON_PATH "interface/menuInicial/Screditos.png"
#define EXIT_BUTTON_PATH "interface/menuInicial/sair.png"
#define ON_FOCUS_EXIT_BUTTON_PATH "interface/menuInicial/Ssair.png"
#define EXTRAS_BUTTON_PATH "interface/menuInicial/extras.png"
#define ON_FOCUS_EXTRAS_BUTTON_PATH "interface/menuInicial/Sextras.png"
#define MAIN_MENU_PATH "interface/menuInicial/menuInicial.png"

TitleScreen::TitleScreen()
    : Level(SevenKeys::ScreenType::MAIN_SCREEN)
{
    Environment *env = Environment::get_instance();

    double width = env->canvas->width();
    double height = env->canvas->height();

    set_dimensions(width, height);

    string path_play_button = Internacionalization::load_string(PLAY_BUTTON_PATH);
    string path_Splay_button = Internacionalization::load_string(ON_FOCUS_PLAY_BUTTON_PATH);
    Button *jogar = new Button(this, "jogar", path_play_button, path_Splay_button);
    jogar->align_to(this, Object::RIGHT , Object::MIDDLE);

    string path_option_button = Internacionalization::load_string(OPTIONS_BUTTON_PATH);
    string path_Soption_button = Internacionalization::load_string(ON_FOCUS_OPTIONS_BUTTON_PATH);
    Button *options = new Button(this, SevenKeys::ScreenType::OPTIONS, path_option_button, path_Soption_button);
    options->align_to(this, Object::RIGHT, Object::NONE);
    options->set_vertical_position(jogar->vertical_position() + jogar->height() + 15);

    string path_credits_button = Internacionalization::load_string(CREDITS_BUTTON_PATH);
    string path_Scredits_button = Internacionalization::load_string(ON_FOCUS_CREDITS_BUTTON_PATH);
    Button *creditos = new Button(this, SevenKeys::ScreenType::CREDITS, path_credits_button, path_Scredits_button);
    creditos->align_to(this, Object::RIGHT, Object::NONE);
    creditos->set_vertical_position(options->vertical_position() + options->height()+15);

    string path_exit_button = Internacionalization::load_string(EXIT_BUTTON_PATH);
    string path_Sexit_button = Internacionalization::load_string(ON_FOCUS_EXIT_BUTTON_PATH);
    Button *exit = new Button(this, "exit", path_exit_button, path_Sexit_button);
    exit->align_to(this, Object::RIGHT, Object::NONE);
    exit->set_vertical_position(creditos->vertical_position() + creditos->height() + 15);

    string path_extras_button = Internacionalization::load_string(EXTRAS_BUTTON_PATH);
    string path_Sextras_button = Internacionalization::load_string(ON_FOCUS_EXTRAS_BUTTON_PATH);
    Button *extras = new Button (this, SevenKeys::ScreenType::EXTRAS, path_extras_button, path_Sextras_button);
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

    string path_main_menu = Internacionalization::load_string(MAIN_MENU_PATH);
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
    } else if (button->id() == SevenKeys::ScreenType::OPTIONS)
    {
        env->sfx->play(PATH_OF_MUSIC_MENU, 1);
        set_next(SevenKeys::ScreenType::OPTIONS);
    }
    else if(button->id() == SevenKeys::ScreenType::CREDITS)
        set_next(SevenKeys::ScreenType::CREDITS);
    else if (button-> id() == SevenKeys::ScreenType::EXTRAS)
        set_next(SevenKeys::ScreenType::EXTRAS);

    finish();

    return true;
}
