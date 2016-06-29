#include "pause.hpp"
#include "7keys.hpp"
#include "internacionalization.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"

#include <iostream>
#include <cassert>

using namespace std;

#define RESUME_GAME_BUTTON_PATH "interface/pauseMenu/resume.png"
//Path of button "resume"
#define ON_FOCUS_RESUME_GAME_BUTTON_PATH "interface/pauseMenu/Sresume.png"
//Path of button "resume", used when is selected
#define BACK_TO_MAIN_MENU_BUTTON_PATH "interface/pauseMenu/mainMenu.png"
//Path of button "back to main menu"
#define ON_FOCUS_BACK_TO_MAIN_MENU_BUTTON_PATH "interface/pauseMenu/mainMenu.png"
//Path of button "back to main menu", used when is selected
#define EXIT_BUTTON_PATH "interface/pauseMenu/exit.png"
//Path of button "exit"
#define ON_FOCUS_EXIT_BUTTON_PATH "interface/pauseMenu/Sexit.png"
//Path of button "exit", used when is selected
#define PAUSE_BACKGROUD_PATH "interface/pauseMenu/pauseMenu.png"
//Path of background of pause menu

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
    string path_resume_button = Internacionalization::load_string(RESUME_GAME_BUTTON_PATH);
    string path_Sresume_button = Internacionalization::load_string(ON_FOCUS_RESUME_GAME_BUTTON_PATH);
    Button *resume = new Button(this, "resume", path_resume_button, path_Sresume_button);

    assert((resume != NULL) && "Failed to pick up the instance of button");

    resume->align_to(this, Object::RIGHT, Object::NONE);
    resume->set_vertical_position(200);

    // Directs to the main menu of the game.
    string path_back_button = Internacionalization::load_string(BACK_TO_MAIN_MENU_BUTTON_PATH);
    string path_Sback_button = Internacionalization::load_string(ON_FOCUS_BACK_TO_MAIN_MENU_BUTTON_PATH);
    Button *main_menu_button = new Button(this, "main_menu_button", path_back_button, path_Sback_button);

    assert((main_menu_button != NULL) && "Failed to pick up the instance of button");

    main_menu_button->align_to(this, Object::RIGHT, Object::NONE);
    main_menu_button->set_vertical_position(resume->vertical_position() + resume->height()+20);

    // Closes the game.
    string path_exit = Internacionalization::load_string(EXIT_BUTTON_PATH);
    string path_Sexit = Internacionalization::load_string(ON_FOCUS_EXIT_BUTTON_PATH);
    Button *exit = new Button(this, "exit", path_exit, path_Sexit);

    assert((exit != NULL) && "Failed to pick up the instance of button");

    exit->align_to(this, Object::RIGHT, Object::NONE);
    exit->set_vertical_position(resume->vertical_position() + resume->height()+20);

    resume->add_observer(this);
    main_menu_button->add_observer(this);
    exit->add_observer(this);

    add_child(resume);
    add_child(main_menu_button);
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

    if (button->id() == "resume")
    {
        status_button = false;
    }

    else if (button->id() == "main_menu_button")
    {
        set_next(SevenKeys::ScreenType::MAIN_SCREEN);
    }

    finish();

    status_button = true;
    return status_button;

}
