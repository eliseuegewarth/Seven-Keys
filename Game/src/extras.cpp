#include "extras.h"

#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>
//#include <smpeg/smpeg.h>

#include <iostream>
#include <cassert>
using namespace std;

/**
 * @brief Creates the environment of the extras menu.
 * @details [long description]
 */
Extras::Extras() : Level("extras")
{
    const Environment *env = Environment::get_instance(); // It is an object of the class environment. Is a pointer to the current instance of the game environment.

    const double w = env->canvas->w(); // Receives the width of the game environment.
    const double h = env->canvas->h(); // Receives the height of the game environment.

    set_dimensions(w, h);

    // Directs to the cutscene of the game.
    Button *cutscene = new Button(this, "cutscene", "res/interface/menuExtras/cutscenes.png",
                                  "res/interface/menuExtras/Scutscenes.png"); 
    cutscene->align_to(this, Object::MIDDLE, Object::NONE);
    cutscene->set_y(200);

    // Directs to the history of the game.
    Button *historia = new Button(this, "historia", "res/interface/menuExtras/historia.png",
                                  "res/interface/menuExtras/Shistoria.png");
    historia->align_to(this, Object::MIDDLE, Object::NONE);
    historia->set_y(cutscene->y() + cutscene->h()+20);

    // Directs to the main menu of the game.
    Button *back = new Button(this, "back", "res/interface/menuExtras/voltar.png",
                              "res/interface/menuExtras/Svoltar.png");
    back->align_to(this, Object::MIDDLE, Object::NONE);
    back->set_y(historia->y() + historia->h()+20);

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
 * @details [long description]
 */
void Extras::draw_self()
{
    // It is an object of the class environment. Is a pointer to the current instance of the game environment.
    const Environment *env = Environment::get_instance(); 
    env->canvas->clear(Color::WHITE);

    const shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuExtras/menuExtras.png");
    env->canvas->draw(image.get(), 1, 0);
}

bool Extras::on_message(Object *object, MessageID id, Parameters) // Let the dynamic buttons.
{
    assert((object != NULL) && "Object needs to be different from NULL");
    if (id != Button::clickedID)
    {
        return false;
    }
    else
    {
        //nothing to do.
    }

    Button *button = dynamic_cast <Button *>(object);

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
