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

    // Directs to the cutscene of the game.
    string path_cutscenes = Internacionalization::load_string("interface/menuExtras/cutscenes.png");
    string path_Scutscenes = Internacionalization::load_string("interface/menuExtras/Scutscenes.png");
    Button *cutscene = new Button(this, "cutscene", path_cutscenes, path_Scutscenes);

    assert((cutscene != NULL) && "Failed to pick up the instance of button");
    cutscene->align_to(this, Object::MIDDLE, Object::NONE);
    cutscene->set_vertical_position(200);

    // Directs to the history of the game.
    string path_history = Internacionalization::load_string("interface/menuExtras/historia.png");
    string path_Shistory = Internacionalization::load_string("interface/menuExtras/Shistoria.png");
    Button *historia = new Button(this, "historia", path_history, path_Shistory);

    assert((historia != NULL) && "Failed to pick up the instance of button");
    historia->align_to(this, Object::MIDDLE, Object::NONE);
    historia->set_vertical_position(cutscene->vertical_position() + cutscene->height() + 20);

    // Directs to the main menu of the game.
    string path_back = Internacionalization::load_string("interface/menuExtras/voltar.png");
    string path_Sback = Internacionalization::load_string("interface/menuExtras/Svoltar.png");
    Button *back = new Button(this, "back", path_back, path_Sback);

    assert((back != NULL) && "Failed to pick up the instance of button");
    back->align_to(this, Object::MIDDLE, Object::NONE);
    back->set_vertical_position(historia->vertical_position() + historia->height() + 20);

    cutscene->add_observer(this);
    historia->add_observer(this);
    back->add_observer(this);

    add_child(cutscene);
    add_child(historia);
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

    string path_menu_extras = Internacionalization::load_string("interface/menuExtras/menuExtras.png");
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
