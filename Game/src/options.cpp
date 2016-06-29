#include "options.hpp"
#include "7keys.hpp"
#include "internacionalization.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"
#include "core/mousemotionevent.hpp"
#include <iostream>
using namespace std;

Options::Options() : Level(SevenKeys::ScreenType::OPTIONS)// Class that represents the option of the main menu of the game.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    double width = env->canvas->width();// Receives the width of the game environment.
    double height = env->canvas->height();// Receives the height of the game environment.

    set_dimensions(width, height);
    string path_fullscreen = Internacionalization::load_string("interface/optionsMenu/fullScreen.png");
    string path_Sfullscreen = Internacionalization::load_string("interface/optionsMenu/SfullScreen.png");
    Button *set_fullscreen = new Button(this, "fullscreen", path_fullscreen, path_Sfullscreen);
    // Puts the screen in fullscreen.
    set_fullscreen->align_to(this, Object::RIGHT, Object::MIDDLE);

    string path_windowed_mode = Internacionalization::load_string("interface/optionsMenu/windowedMode.png");
    string path_Swindowed_mode = Internacionalization::load_string("interface/optionsMenu/SwindowedMode.png");
    Button *windowmode = new Button(this, "windowmode", path_windowed_mode, path_Swindowed_mode);
    // Puts the screen in windowed mode.
    windowmode->align_to(this, Object::RIGHT, Object::NONE);
    windowmode->set_vertical_position(set_fullscreen->vertical_position() + set_fullscreen->height() + 20);

    string path_back = Internacionalization::load_string("interface/optionsMenu/back.png");
    string path_Sback = Internacionalization::load_string("interface/optionsMenu/Sback.png");
    Button *back = new Button(this, "back", path_back, path_Sback);
    // Directs to the main menu of the game.
    back->align_to(this, Object::RIGHT, Object::NONE);
    back->set_vertical_position(windowmode->vertical_position() + windowmode->height() + 20);

    set_fullscreen->add_observer(this);
    windowmode->add_observer(this);
    back->add_observer(this);

    add_child(set_fullscreen);
    add_child(windowmode);
    add_child(back);



}

Options::~Options()
{
}

void Options::draw_self()// Drow options pinctures on the screen.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    env->canvas->clear(Color::WHITE);

    string path_option_menu = Internacionalization::load_string("interface/optionsMenu/optionsMenu.png");
    shared_ptr<Texture> image = env->resources_manager->get_texture(path_option_menu);
    env->canvas->draw(image.get(), 1, 0);
}

bool Options::on_message(Object *object, MessageID id, Parameters)// Let the dynamic buttons.
{
    Environment *env = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Button *button = dynamic_cast<Button *>(object);
    env->sfx->play("res/sounds/navegacaomenu.wav", 1);

    if (id != Button::clickedID)
    {
        return false;
    }

    if (not button)
    {
        return false;
    }

    if(button->id() == "fullscreen" || button->id() == "windowmode" || button->id() == "back")
            env->sfx->play("res/sounds/navegacaomenu.wav",1);

    if (button->id() == "fullscreen")
    {
        env->video->set_fullscreen();
        set_next(SevenKeys::ScreenType::OPTIONS);
    }
    else if (button->id() == "windowmode")
    {
        env->video->set_fullscreen(false);
        set_next(SevenKeys::ScreenType::OPTIONS);
    }

    else if (button->id() == "back")
    {
        set_next(SevenKeys::ScreenType::MAIN_SCREEN);
    }

    finish();

    return true;
}
