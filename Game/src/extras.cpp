/**
 * extras.cpp file.
 */

#include "extras.hpp"
#include "7keys.hpp"
#include "internacionalization.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"

#include <iostream>
#include <cassert>

using namespace std;

/**
 * @brief Creates the environment of the extras menu.
 */
Extras::Extras() : Level(SevenKeys::ScreenType::EXTRAS)
{
    /* It is an object of the class environment.
    Is a pointer to the current instance of the game environment.*/
    const Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");

    // Receives the width of the game environment.
    const double width = env->canvas->width();

    // Receives the height of the game environment.
    const double height = env->canvas->height();

    set_dimensions(width, height);

    // Directs to the cinematics of the game.
    string path_cinematics = Internacionalization::load_string("interface/extrasMenu/cinematics.png");
    string path_Scinematics = Internacionalization::load_string("interface/extrasMenu/Scinematics.png");
    Button *cinematics = new Button(this, "cinematics", path_cinematics, path_Scinematics);

    assert((cinematics != NULL) && "Failed to pick up the instance of button");
    cinematics->align_to(this, Object::MIDDLE, Object::NONE);
    cinematics->set_vertical_position(200);

    // Directs to the history of the game.
    string path_history = Internacionalization::load_string("interface/extrasMenu/history.png");
    string path_Shistory = Internacionalization::load_string("interface/extrasMenu/Shistory.png");
    Button *history = new Button(this, "history", path_history, path_Shistory);

    assert((history != NULL) && "Failed to pick up the instance of button");
    history->align_to(this, Object::MIDDLE, Object::NONE);
    history->set_vertical_position(cinematics->vertical_position() + cinematics->height() + 20);

    // Directs to the main menu of the game.
    string path_back = Internacionalization::load_string("interface/extrasMenu/back.png");
    string path_Sback = Internacionalization::load_string("interface/extrasMenu/Sback.png");
    Button *back = new Button(this, "back", path_back, path_Sback);

    assert((back != NULL) && "Failed to pick up the instance of button");
    back->align_to(this, Object::MIDDLE, Object::NONE);
    back->set_vertical_position(history->vertical_position() + history->height() + 20);

    cinematics->add_observer(this);
    history->add_observer(this);
    back->add_observer(this);

    add_child(cinematics);
    add_child(history);
    add_child(back);
}

Extras::~Extras()
{
}

/**
 * @brief Drow extras pinctures on the screen.
 */
void Extras::draw_self()
{
    /* It is an object of the class environment.
    Is a pointer to the current instance of the game environment.*/
    const Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");
    env->canvas->clear(Color::WHITE);

    string path_menu_extras = Internacionalization::load_string("interface/extrasMenu/extrasMenu.png");
    const shared_ptr<Texture> image = env->resources_manager->get_texture(path_menu_extras);
    assert((image != NULL) && "image to pick up the instance of environment");
    env->canvas->draw(image.get(), 1, 0);
}

/**
 * @brief Let the dynamic buttons.
 *
 * @param object [description]
 * @param id [description]
 * @return returns if the button was clicked or not, that is their status.
 */
bool Extras::on_message(Object *object, MessageID id, Parameters)
{
    assert((object != NULL) && "Object needs to be different from NULL");
    assert((not id.empty()) && "id needs to be different drom the empty");
    if (id != Button::clickedID)
    {
        return false;
    }
    else
    {
        //nothing to do.
    }

    Button *button = dynamic_cast <Button *>(object);
    assert((button != NULL) && "Failed to pick up the instance of button");

    if (not button)
    {
        return false;
    }
    else{
        //nothing to do.
    }
    if (button->id() == "back")
    {
        set_next(SevenKeys::ScreenType::MAIN_SCREEN);
    }
    else
    {
        //nothing to do.
    }

    finish();

    return true;
}
