/**
 * extras.cpp file.
 */

#include "extras.hpp"

#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>

#include <iostream>
#include <cassert>

using namespace std;

/**
 * @brief Creates the environment of the extras menu.
 */
Extras::Extras() : Level("extras")
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
    Button *cutscene = new Button(this, "cutscene", 
                                  "res/EN-US/interface/menuExtras/cutscenes.png",
                                  "res/EN-US/interface/menuExtras/Scutscenes.png");

    assert((cutscene != NULL) && "Failed to pick up the instance of button");
    cutscene->align_to(this, Object::MIDDLE, Object::NONE);
    cutscene->set_y(200);

    // Directs to the history of the game.
    Button *historia = new Button(this, "historia", 
                                  "res/EN-US/interface/menuExtras/historia.png",
                                  "res/EN-US/interface/menuExtras/Shistoria.png");

    assert((historia != NULL) && "Failed to pick up the instance of button");
    historia->align_to(this, Object::MIDDLE, Object::NONE);
    historia->set_y(cutscene->y() + cutscene->height() + 20);

    // Directs to the main menu of the game.
    Button *back = new Button(this, "back", 
                              "res/EN-US/interface/menuExtras/voltar.png",
                              "res/EN-US/interface/menuExtras/Svoltar.png");

    assert((back != NULL) && "Failed to pick up the instance of button");
    back->align_to(this, Object::MIDDLE, Object::NONE);
    back->set_y(historia->y() + historia->height() + 20);

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

    const shared_ptr<Texture> image = env->resources_manager->
                        get_texture("res/EN-US/interface/menuExtras/menuExtras.png");
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
        set_next("title");
    }
    else
    {
        //nothing to do.
    }

    finish();

    return true;
}
