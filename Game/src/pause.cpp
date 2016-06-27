#include "pause.hpp"
#include "internacionalization.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"

#include <iostream>
#include <cassert>

using namespace std;

#define RESUME_GAME_BUTTON_PATH "interface/menuPausa/voltarJogo.png"
//Path of button "resume"
#define ON_FOCUS_RESUME_GAME_BUTTON_PATH "interface/menuPausa/SvoltarJogo.png"
//Path of button "resume", used when is selected
#define BACK_TO_MAIN_MENU_BUTTON_PATH "interface/menuExtras/voltar.png"
//Path of button "back to main menu"
#define ON_FOCUS_BACK_TO_MAIN_MENU_BUTTON_PATH "interface/menuExtras/voltar.png"
//Path of button "back to main menu", used when is selected
#define EXIT_BUTTON_PATH "interface/menuExtras/sair.png"
//Path of button "exit"
#define ON_FOCUS_EXIT_BUTTON_PATH "interface/menuExtras/Ssair.png"
//Path of button "exit", used when is selected
#define PAUSE_BACKGROUD_PATH "interface/menuPausa/fundoPausa.png"
//Path of background of pause menu

/**
 * @brief Creates the environment of the pause menu.
 * instantiates the pause page, from the time, the buttons and the background.
 */
Pause::Pause()
    : Level("pause")
{
    /* It is an object of the class environment.
    Is a pointer to the current instance of the game environment.*/
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");

    // Receives the width of the game environment.
    double width = env->canvas->width();

    // Receives the height of the game environment.
    double height = env->canvas->height();

    set_dimensions(width, height);

    // Directs the environment where the game was paused.
    string path_resume_button = Internacionalization::load_string(RESUME_GAME_BUTTON_PATH);
    string path_Sresume_button = Internacionalization::load_string(ON_FOCUS_RESUME_GAME_BUTTON_PATH);
    Button *backGame = new Button(this, "backGame", path_resume_button, path_Sresume_button);

    assert((backGame != NULL) && "Failed to pick up the instance of button");

    backGame->align_to(this, Object::RIGHT, Object::NONE);
    backGame->set_vertical_position(200);

    // Directs to the main menu of the game.
    string path_back_button = Internacionalization::load_string(BACK_TO_MAIN_MENU_BUTTON_PATH);
    string path_Sback_button = Internacionalization::load_string(ON_FOCUS_BACK_TO_MAIN_MENU_BUTTON_PATH);
    Button *backMenu = new Button(this, "backMenu", path_back_button, path_Sback_button);

    assert((backMenu != NULL) && "Failed to pick up the instance of button");

    backMenu->align_to(this, Object::RIGHT, Object::NONE);
    backMenu->set_vertical_position(backGame->vertical_position() + backGame->height()+20);

    // Closes the game.
    string path_sair = Internacionalization::load_string(EXIT_BUTTON_PATH);
    string path_Ssair = Internacionalization::load_string(ON_FOCUS_EXIT_BUTTON_PATH);
    Button *exit = new Button(this, "exit", path_sair, path_Ssair);

    assert((exit != NULL) && "Failed to pick up the instance of button");

    exit->align_to(this, Object::RIGHT, Object::NONE);
    exit->set_vertical_position(backGame->vertical_position() + backGame->height()+20);

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

/**
 * @brief [Drow pause pinctures on the screen.]
 */
void Pause::draw_self()
{
    /* It is an object of the class environment.
    Is a pointer to the current instance of the game environment.*/
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Filed to pick up the instance of environment");
    env->canvas->clear(Color::WHITE);

    string path_fundo_pausa = Internacionalization::load_string(PAUSE_BACKGROUD_PATH);
    shared_ptr<Texture> image = env->resources_manager->get_texture(path_fundo_pausa);
    assert((image != NULL) && "image to pick up the instance of environment");
    env->canvas->draw(image.get(), 1, 0);
}

/**
 * @brief [Let the dynamic buttons]
 *
 * @return [returns the status of the button, if it was clicked or not]
 */

bool Pause::on_message(Object *object, MessageID id, Parameters)
{
    assert((object != NULL) && "Object needs to be different from NULL");
    assert((not id.empty()) && "id needs to be different drom the empty");

    bool status_button;

    if (id != Button::clickedID)
    {
        status_button = false;
    }

    Button *button = dynamic_cast <Button *>(object);
    assert((button != NULL) && "Failed to pick up the instance of button");


    if (not button)
    {
        status_button = false;
    }

    if (button->id() == "backGame")
    {
        status_button = false;
    }

    else if (button->id() == "backMenu")
    {
        set_next("title");
    }

    finish();

    status_button = true;
    return status_button;

}
