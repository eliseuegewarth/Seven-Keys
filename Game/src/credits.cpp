#include "credits.hpp"
#include <ijengine/util/button.h>
#include <core/font.h>
#include <core/environment.h>
#include <cassert>
#include <iostream>

/**
 * credits.cpp
 * @brief [Class that implements the credits of the game.]
 * Licença: LGPL. Sem copyright.
 */

using namespace std;

const string resume_button_path = "res/interface/menuCredits/resume.png";

const string resume_button_path_highlight = "res/interface/menuCredits/ \
                                                resumeHighlight.png";

const string screen_credits_image_path = "res/interface/menuCredits/ \
                                                screenCredits.png";

Credits::Credits() : Level("credits")
{
    /* It is an object of the class environment.
    Is a pointer to the current instance of the game environment.
    */
    Environment *env = Environment::get_instance();

    assert(env != NULL && "Failed to pick up the instance of environment");

    double width = env->canvas->width();
    double height = env->canvas->height();

    set_dimensions(width, height);

    // Button used to return to main menu
    Button *back = new Button(this, "back", resume_button_path,
                              resume_button_path_highlight);

    assert(back != NULL && "Failed to create resume button.");

    back->align_to(this, Object::RIGHT, Object::RIGHT);
    back->set_y(520);

    back->add_observer(this);
    add_child(back);

}

Credits::~Credits() {}

void Credits::draw_self()
{
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");
    env->canvas->clear(Color::WHITE);

    // Image background of the credits
    shared_ptr<Texture> image = env->resources_manager->
          get_texture(screen_credits_image_path);

    assert(image != NULL && "Unable to find screenCredits.png path");
    env->canvas->draw(image.get(), 1, 0);
}

bool Credits::on_message(Object *object, MessageID id, Parameters)
{

    assert((object != NULL) && "Object needs to be different from NULL");
    assert((not id.empty()) && "id needs to be different drom the empty");

    if (id != Button::clickedID)
    {
        return false;
    }

    // Button used to verify if the back button was clicked
    Button *button = dynamic_cast <Button *>(object);

    if (not button)
    {
        return false;
    }
    if (button->id() == "back")
    {
        set_next("title");
    }

    finish();

    return true;
}
