/**
 * guard.cpp
 * This class describes the attributes and behaviors of the guard enemie.
 * Licença: LGPL. Sem copyright.
 */

#include "internacionalization.hpp"
#include "7keys.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"
#include "core/mousemotionevent.hpp"
#include <iostream>
#include <fstream>

#define MENU_LANGUAGE_IMAGE "res/language/menuLanguage.png"

#define ENGLISH_LANGUAGE "EN-US"
#define ENGLISH_BUTTON_NAME "english"
#define ENGLISH_BUTTON_IMAGE "res/language/english.png"
#define ENGLISH_SELECTED_BUTTON_IMAGE "res/language/Senglish.png"

#define ESPANISH_LANGUAGE "ES-GT"
#define ESPANISH_BUTTON_NAME "espanish"
#define ESPANISH_BUTTON_IMAGE "res/language/espanish.png"
#define ESPANISH_SELECTED_BUTTON_IMAGE "res/language/Sespanish.png"

#define PORTUGUESE_LANGUAGE "PT-BR"
#define PORTUGUESE_BUTTON_NAME "portuguese"
#define PORTUGUESE_BUTTON_IMAGE "res/language/portuguese.png"
#define PORTUGUESE_SELECTED_BUTTON_IMAGE "res/language/Sportuguese.png"

#define FRENCH_LANGUAGE "FR-FR"
#define FRENCH_BUTTON_NAME "french"
#define FRENCH_BUTTON_IMAGE "res/language/french.png"
#define FRENCH_SELECTED_BUTTON_IMAGE "res/language/Sfrench.png"

#define NEXT_BUTTON_NAME "next"
#define NEXT_BUTTON_IMAGE "res/language/next.png"
#define NEXT_SELECTED_BUTTON_IMAGE "res/language/Snext.png"

#define PREVIOUS_BUTTON_NAME "previous"
#define PREVIOUS_BUTTON_IMAGE "res/language/previous.png"
#define PREVIOUS_SELECTED_BUTTON_IMAGE "res/language/Sprevious.png"


using namespace std;

const string Internacionalization::GAME_RESOURCE_PATH = "res";

Internacionalization::Internacionalization() : Level(LANGUAGE_PATH)// Class that represents the option of the main menu of the game.
{
    Environment *environment = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    double width = environment->canvas->width();// Receives the width of the game environment.
    double height = environment->canvas->height();// Receives the height of the game environment.

    set_dimensions(width, height);

    Button *english = new Button(this, ENGLISH_BUTTON_NAME, ENGLISH_BUTTON_IMAGE,
        ENGLISH_SELECTED_BUTTON_IMAGE);// Puts the screen in fullscreen.
    english->align_to(this, Object::RIGHT, Object::MIDDLE);
    english->set_vertical_position(150);

    Button *espanish = new Button(this, ESPANISH_BUTTON_NAME, ESPANISH_BUTTON_IMAGE,
        ESPANISH_SELECTED_BUTTON_IMAGE);// Puts the screen in windowed mode.
    espanish->align_to(this, Object::RIGHT, Object::NONE);
    espanish->set_vertical_position(english->vertical_position() + english->height() + 16);

    Button *portuguese = new Button(this, PORTUGUESE_BUTTON_NAME, PORTUGUESE_BUTTON_IMAGE,
        PORTUGUESE_SELECTED_BUTTON_IMAGE);// Puts the screen in windowed mode.
    portuguese->align_to(this, Object::RIGHT, Object::NONE);
    portuguese->set_vertical_position(espanish->vertical_position() + espanish->height() + 16    );

    Button *french = new Button(this, FRENCH_BUTTON_NAME, FRENCH_BUTTON_IMAGE,
        FRENCH_SELECTED_BUTTON_IMAGE);// Puts the screen in windowed mode.
    french->align_to(this, Object::RIGHT, Object::NONE);
    french->set_vertical_position(portuguese->vertical_position() + portuguese->height() + 16);

    Button *next = new Button(this, NEXT_BUTTON_NAME, NEXT_BUTTON_IMAGE,
        NEXT_SELECTED_BUTTON_IMAGE);// Directs to the main menu of the game.
    next->align_to(this, Object::RIGHT, Object::NONE);
    next->set_vertical_position(french->vertical_position() + french->height() + 16);

    Button *previous = new Button(this, PREVIOUS_BUTTON_NAME, PREVIOUS_BUTTON_IMAGE,
        PREVIOUS_SELECTED_BUTTON_IMAGE);// Directs to the main menu of the game.
    previous->align_to(this, Object::MIDDLE, Object::NONE);
    previous->set_vertical_position(next->vertical_position());
    previous->set_horizontal_position(next->horizontal_position() - next->width() - 16);

    english->add_observer(this);
    espanish->add_observer(this);
    portuguese->add_observer(this);
    french->add_observer(this);
    next->add_observer(this);
    previous->add_observer(this);


    add_child(english);
    add_child(espanish);
    add_child(portuguese);
    add_child(french);
    add_child(next);
    add_child(previous);

}

Internacionalization::~Internacionalization()
{
}

// Drow Internacionalization pinctures on the screen.
void Internacionalization::draw_self()
{
    // It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *environment = Environment::get_instance();
    environment->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = environment->resources_manager->get_texture(MENU_LANGUAGE_IMAGE);
    environment->canvas->draw(image.get(), 1, 0);
}

bool Internacionalization::on_message(Object *object, MessageID id, Parameters)// Let the dynamic buttons.
{
    Environment *environment = Environment::get_instance();
    // It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Button *button = dynamic_cast<Button *>(object);
    environment->sfx->play("res/sounds/navegacaomenu.wav", 1);

    if (id != Button::clickedID)
    {
        return false;
    }

    if (not button)
    {
        return false;
    }

    if(button->id() == ENGLISH_LANGUAGE || button->id() == ESPANISH_LANGUAGE ||
       button->id() == PORTUGUESE_LANGUAGE || button->id() == FRENCH_LANGUAGE ||
       button->id() == "next" || button->id() == "previous")
        {
            environment->sfx->play("res/sounds/navegacaomenu.wav",1);
        }

    if (button->id() == ENGLISH_BUTTON_NAME)
    {
        set_next(SevenKeys::ScreenType::HEADPHONE);
        set_language(ENGLISH_LANGUAGE);

    }
    else if (button->id() == ESPANISH_BUTTON_NAME)
    {
        set_next(SevenKeys::ScreenType::HEADPHONE);
        set_language("ES-GT");
        cout << "chegou aqui5" <<endl;
        cout << game_language <<endl;
    }

    else if (button->id() == PORTUGUESE_BUTTON_NAME)
    {
        set_next(SevenKeys::ScreenType::HEADPHONE);
        set_language(PORTUGUESE_LANGUAGE);
    }
    else if (button->id() == FRENCH_BUTTON_NAME)
    {
        set_next(SevenKeys::ScreenType::HEADPHONE);
        set_language(PORTUGUESE_LANGUAGE);

    }
    else if (button->id() == NEXT_BUTTON_NAME)
    {
        set_next(SevenKeys::ScreenType::HEADPHONE);
        set_language(DEFAULT_LANGUAGE_PATH);
        cout << "chegou aqui7" <<endl;
    }
    else if (button->id() == PREVIOUS_BUTTON_NAME)
    {
        set_next(SevenKeys::ScreenType::HEADPHONE);
        set_language(DEFAULT_LANGUAGE_PATH);
        cout << "chegou aqui8" <<endl;
    }

    finish();

    return true;
}

void Internacionalization::set_language(const string& language)
{
    ofstream language_preferences;
    language_preferences.open("language_preferences.txt", ios::out);
    language_preferences << language << endl;
    language_preferences.close();
}

string Internacionalization::get_language()
{
    ifstream language_preferences;
    language_preferences.open("language_preferences.txt", ios::in);
    string language;
    getline (language_preferences,language);
    language_preferences.close();
    return language;
}

string Internacionalization::load_string(const string& source_to_translate)
{
    string path_string;
    path_string = (Internacionalization::GAME_RESOURCE_PATH +
                  "/" + Internacionalization::get_language() +
                  "/" + source_to_translate);
    return path_string;
}
