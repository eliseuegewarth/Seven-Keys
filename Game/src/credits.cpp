#include "credits.hpp"
#include "7keys.hpp"
#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"
#include <cassert>
#include <iostream>

#include "internacionalization.hpp"

/**
 * credits.cpp
 * @brief [Class that implements the credits of the game.]
 * Licença: LGPL. Sem copyright.
 */

#define RESUME_BUTTON_IMAGE_PATH "interface/creditsMenu/back.png"
#define RESUME_BUTTON_SELECTED_IMAGE_PATH "interface/creditsMenu/Sback.png"
#define CREDITS_BACKGROUND_IMAGE_PATH "interface/creditsMenu/creditsMenu.png"
#define CREDITS_RESUME_BUTTON_ID "back"


using namespace std;


Credits::Credits() : Level(SevenKeys::ScreenType::CREDITS)
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
    string path_back = Internacionalization::load_string(RESUME_BUTTON_IMAGE_PATH);
    string path_back_highlight = Internacionalization::load_string(RESUME_BUTTON_SELECTED_IMAGE_PATH);
    Button *back = new Button(this, CREDITS_RESUME_BUTTON_ID, path_back,
                              path_back_highlight);

    assert(back != NULL && "Failed to create resume button.");

    back->align_to(this, Object::RIGHT, Object::RIGHT);
    back->set_vertical_position(520);

    back->add_observer(this);
    add_child(back);

}

Credits::~Credits() {}

void Credits::draw_self()
{
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "Failed to pick up the instance of environment");
    env->canvas->clear(Color::WHITE);

    string path_credits = Internacionalization::load_string(CREDITS_BACKGROUND_IMAGE_PATH);
    shared_ptr<Texture> image = env->resources_manager->
          get_texture(path_credits);

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
    if (button->id() == CREDITS_RESUME_BUTTON_ID)
    {
        set_next(SevenKeys::ScreenType::MAIN_SCREEN);
    }

    finish();

    return true;
}
