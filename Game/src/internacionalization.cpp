#include "internacionalization.hpp"

#include "util/button.hpp"
#include "core/font.hpp"
#include "core/environment.hpp"
#include "core/mousemotionevent.hpp"
#include <iostream>

#define MENU_LANGUAGE_IMAGE "res/language/menuLanguage.png"

#define ENGLISH_LANGUAGE "res/language/english"
#define ENGLISH_BUTTON_IMAGE "res/language/english.png"
#define ENGLISH_SELECTED_BUTTON_IMAGE "res/language/Senglish.png"

#define ESPANISH_LANGUAGE "espanish"
#define ESPANISH_BUTTON_IMAGE "res/language/espanish.png"
#define ESPANISH_SELECTED_BUTTON_IMAGE "res/language/Sespanish.png"

#define PORTUGUESE_LANGUAGE "portuguese"
#define PORTUGUESE_BUTTON_IMAGE "res/language/portuguese.png"
#define PORTUGUESE_SELECTED_BUTTON_IMAGE "res/language/Sportuguese.png"

#define FRENCH_LANGUAGE "french"
#define FRENCH_BUTTON_IMAGE "res/language/french.png"
#define FRENCH_SELECTED_BUTTON_IMAGE "res/language/Sfrench.png"

#define NEXT "next"
#define NEXT_BUTTON_IMAGE "res/language/next.png"
#define NEXT_SELECTED_BUTTON_IMAGE "res/language/Snext.png"

#define PREVIOUS "previous"
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

    Button *english = new Button(this, ENGLISH_LANGUAGE, ENGLISH_BUTTON_IMAGE,
        ENGLISH_SELECTED_BUTTON_IMAGE);// Puts the screen in fullscreen.
    english->align_to(this, Object::RIGHT, Object::MIDDLE);
    english->set_vertical_position(150);

    Button *espanish = new Button(this, ESPANISH_LANGUAGE, ESPANISH_BUTTON_IMAGE,
        ESPANISH_SELECTED_BUTTON_IMAGE);// Puts the screen in windowed mode.
    espanish->align_to(this, Object::RIGHT, Object::NONE);
    espanish->set_vertical_position(english->vertical_position() + english->height() + 16);

    Button *portuguese = new Button(this, PORTUGUESE_LANGUAGE, PORTUGUESE_BUTTON_IMAGE,
        PORTUGUESE_SELECTED_BUTTON_IMAGE);// Puts the screen in windowed mode.
    portuguese->align_to(this, Object::RIGHT, Object::NONE);
    portuguese->set_vertical_position(espanish->vertical_position() + espanish->height() + 16    );

    Button *french = new Button(this, FRENCH_LANGUAGE, FRENCH_BUTTON_IMAGE,
        FRENCH_SELECTED_BUTTON_IMAGE);// Puts the screen in windowed mode.
    french->align_to(this, Object::RIGHT, Object::NONE);
    french->set_vertical_position(portuguese->vertical_position() + portuguese->height() + 16);

    Button *next = new Button(this, NEXT, NEXT_BUTTON_IMAGE,
        NEXT_SELECTED_BUTTON_IMAGE);// Directs to the main menu of the game.
    next->align_to(this, Object::RIGHT, Object::NONE);
    next->set_vertical_position(french->vertical_position() + french->height() + 16);

    Button *previous = new Button(this, "previous", "res/language/previous.png",
        "res/language/Sprevious.png");// Directs to the main menu of the game.
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

void Internacionalization::draw_self()// Drow Internacionalization pinctures on the screen.
{
    Environment *environment = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    environment->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = environment->resources_manager->get_texture( MENU_LANGUAGE_IMAGE);
    environment->canvas->draw(image.get(), 1, 0);
}

bool Internacionalization::on_message(Object *object, MessageID id, Parameters)// Let the dynamic buttons.
{
    Environment *environment = Environment::get_instance();// It is an object of the class environment. Is a pointer to the current instance of the game environment.
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
       button->id() == "portuguese" || button->id() == "french" ||
       button->id() == "next" || button->id() == "previous")
        {
            environment->sfx->play("res/sounds/navegacaomenu.wav",1);
        }

    if (button->id() == ENGLISH_LANGUAGE)
    {
        set_next("fone");
        set_language(DEFAULT_LANGUAGE_PATH);
    }
    else if (button->id() == ESPANISH_LANGUAGE)
    {
        set_next("fone");
        set_language(ESPANISH_LANGUAGE);
    }
    else if (button->id() == "portuguese")
    {
        set_next("fone");
        set_language("portuguese");
    }
    else if (button->id() == "french")
    {
        set_next("fone");
        set_language("french");
    }
    else if (button->id() == "next")
    {
        set_next("fone");
        set_language(DEFAULT_LANGUAGE_PATH);
    }
    else if (button->id() == "previous")
    {
        set_next("fone");
        set_language(DEFAULT_LANGUAGE_PATH);
    }

    finish();

    return true;
}

Internacionalization* Internacionalization::get_instance()
{
    static Internacionalization* singleton;

    if (not singleton)
    {
        singleton = new Internacionalization();
    }
    return singleton;
}

void Internacionalization::set_language(const string& language)
{
    this->game_language = language;
}

string Internacionalization::get_language()
{
    return this->game_language;
}

/*string Internacionalization::load_string(const string& language, const string& source_to_translate)*/
string Internacionalization::load_string(const string& source_to_translate)
{
    /*
    assert(language != nullptr);
    assert(source_to_translate != nullptr);
    */
    string path_string;
    path_string = (Internacionalization::GAME_RESOURCE_PATH + "/" + this->game_language + "/" + source_to_translate);

    return path_string;
}