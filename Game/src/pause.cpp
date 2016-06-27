#include "pause.hpp"
#include "7keys.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"

#include <iostream>
#include <cassert>

using namespace std;

/**
 * @brief Creates the environment of the pause menu.
 * instantiates the pause page, from the time, the buttons and the background.
 */
Pause::Pause()
    : Level(SevenKeys::ScreenType::PAUSE)
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
    Button *backGame = new Button(this, "backGame",
                                  "res/EN-US/interface/menuPausa/voltarJogo.png",
                                  "res/EN-US/interface/menuPausa/SvoltarJogo.png");

    assert((backGame != NULL) && "Failed to pick up the instance of button");

    backGame->align_to(this, Object::RIGHT, Object::NONE);
    backGame->set_vertical_position(200);

    // Directs to the main menu of the game.
    Button *backMenu = new Button(this, "backMenu",
                                  "res/EN-US/interface/menuExtras/voltar.png",
                                  "res/EN-US/interface/menuExtras/Svoltar.png");

    assert((backMenu != NULL) && "Failed to pick up the instance of button");

    backMenu->align_to(this, Object::RIGHT, Object::NONE);
    backMenu->set_vertical_position(backGame->vertical_position() + backGame->height()+20);

    // Closes the game.
    Button *exit = new Button(this, "exit",
                              "res/EN-US/interface/menuExtras/sair.png",
                              "res/EN-US/interface/menuExtras/Ssair.png");

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

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/EN-US/interface/menuPausa/fundoPausa.png");
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
        set_next(SevenKeys::ScreenType::MAIN_SCREEN);
    }

    finish();

    status_button = true;
    return status_button;

}
