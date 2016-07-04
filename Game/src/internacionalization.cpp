/**
 * internacionalization.cpp
 * This class describes the attributes and behaviors of the internacionalization menu.
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

//Path pattern of game images
const string Internacionalization::GAME_RESOURCE_PATH = "res";

//Languages currently available in the game, all belonging to the class language type
const string& Internacionalization::LanguageType::ENGLISH_LANGUAGE = "EN-US";
const string& Internacionalization::LanguageType::ESPANISH_LANGUAGE = "ES-GT";
const string& Internacionalization::LanguageType::PORTUGUESE_LANGUAGE = "PT-BR";
const string& Internacionalization::LanguageType::FRENCH_LANGUAGE = "FR-FR";

//Name of the english language selection button
#define ENGLISH_BUTTON_NAME "english"
//Paths of "english" button
#define ENGLISH_BUTTON_IMAGE "res/language/english.png"
#define ENGLISH_SELECTED_BUTTON_IMAGE "res/language/Senglish.png"

//Name of the espanish language selection button
#define ESPANISH_BUTTON_NAME "espanish"
//Paths of "espanish" button
#define ESPANISH_BUTTON_IMAGE "res/language/espanish.png"
#define ESPANISH_SELECTED_BUTTON_IMAGE "res/language/Sespanish.png"

//Name of the portuguese language selection button
#define PORTUGUESE_BUTTON_NAME "portuguese"
//Paths of "portuguese" button
#define PORTUGUESE_BUTTON_IMAGE "res/language/portuguese.png"
#define PORTUGUESE_SELECTED_BUTTON_IMAGE "res/language/Sportuguese.png"

//Name of the french language selection button
#define FRENCH_BUTTON_NAME "french"
//Paths of "french" button
#define FRENCH_BUTTON_IMAGE "res/language/french.png"
#define FRENCH_SELECTED_BUTTON_IMAGE "res/language/Sfrench.png"

//Name of the next page button
#define NEXT_BUTTON_NAME "next"
//Paths of "next" button
#define NEXT_BUTTON_IMAGE "res/language/next.png"
#define NEXT_SELECTED_BUTTON_IMAGE "res/language/Snext.png"

//Name of the previous page button
#define PREVIOUS_BUTTON_NAME "previous"
//Paths of "previous" button
#define PREVIOUS_BUTTON_IMAGE "res/language/previous.png"
#define PREVIOUS_SELECTED_BUTTON_IMAGE "res/language/Sprevious.png"

using namespace std;


// Class that represents the option of the main menu of the game.
Internacionalization::Internacionalization(bool options) : Level(LANGUAGE_PATH)
{
	// It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *environment = Environment::get_instance();
	// Receives the width of the game environment.
    double width = environment->canvas->width();
	// Receives the height of the game environment.
    double height = environment->canvas->height();

    //Defines the dimensions of the screen that will be created
    set_dimensions(width, height);

    //create the english language button on the screen
    Button *english = new Button(this, ENGLISH_BUTTON_NAME, ENGLISH_BUTTON_IMAGE,
                                 ENGLISH_SELECTED_BUTTON_IMAGE);
    english->align_to(this, Object::RIGHT, Object::MIDDLE);
    english->set_vertical_position(150);

    //create the espanish language button on the screen
    Button *espanish = new Button(this, ESPANISH_BUTTON_NAME, ESPANISH_BUTTON_IMAGE,
                                  ESPANISH_SELECTED_BUTTON_IMAGE);
    espanish->align_to(this, Object::RIGHT, Object::NONE);
    espanish->set_vertical_position(english->vertical_position() +
	                                english->height() + 16);

    //create the portuguese language button on the screen
    Button *portuguese = new Button(this, PORTUGUESE_BUTTON_NAME, PORTUGUESE_BUTTON_IMAGE,
                                    PORTUGUESE_SELECTED_BUTTON_IMAGE);
    portuguese->align_to(this, Object::RIGHT, Object::NONE);
    portuguese->set_vertical_position(espanish->vertical_position() +
	                                  espanish->height() + 16);
    //create the french language button on the screen
    Button *french = new Button(this, FRENCH_BUTTON_NAME, FRENCH_BUTTON_IMAGE,
        FRENCH_SELECTED_BUTTON_IMAGE);// Puts the screen in windowed mode.
    french->align_to(this, Object::RIGHT, Object::NONE);
    french->set_vertical_position(portuguese->vertical_position() +
                                  portuguese->height() + 16);

    //create the next page button on the screen
    Button *next = new Button(this, NEXT_BUTTON_NAME, NEXT_BUTTON_IMAGE,
        NEXT_SELECTED_BUTTON_IMAGE);// Directs to the main menu of the game.
    next->align_to(this, Object::RIGHT, Object::NONE);
    next->set_vertical_position(french->vertical_position() +
                                french->height() + 16);

    //create the next page button on the screen
    Button *previous = new Button(this, PREVIOUS_BUTTON_NAME, PREVIOUS_BUTTON_IMAGE,
        PREVIOUS_SELECTED_BUTTON_IMAGE);// Directs to the main menu of the game.
    previous->align_to(this, Object::MIDDLE, Object::NONE);
    previous->set_vertical_position(next->vertical_position());
    previous->set_horizontal_position(next->horizontal_position() -
                                      next->width() - 16);

    //Add an observer to the actions of the mouse on the created button
    english->add_observer(this);
    espanish->add_observer(this);
    portuguese->add_observer(this);
    french->add_observer(this);
    next->add_observer(this);
    previous->add_observer(this);

    //Add the button as a physical object on the screen
    add_child(english);
    add_child(espanish);
    add_child(portuguese);
    add_child(french);
    add_child(next);
    add_child(previous);

    this->options = options;
}

Internacionalization::~Internacionalization()
{
}

// Drow Internacionalization pictures on the screen.
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

    //Test if something was pressed
    if (id != Button::clickedID)
    {
        return false;
    }else{
        //do nothing
    }

    //Test if a button was pressed
    if (not button)
    {
        return false;
    }else{
        //do nothing
    }

    //Add sound effect to the buttons when they are clicked
    if(button->id() == Internacionalization::LanguageType::ENGLISH_LANGUAGE ||
       button->id() == Internacionalization::LanguageType::ESPANISH_LANGUAGE ||
       button->id() == Internacionalization::LanguageType::PORTUGUESE_LANGUAGE ||
       button->id() == Internacionalization::LanguageType::FRENCH_LANGUAGE ||
       button->id() == NEXT_BUTTON_NAME || button->id() == PREVIOUS_BUTTON_NAME)
    {
            environment->sfx->play("res/sounds/navegacaomenu.wav",1);
    }else{
        //do nothing
    }

    /*
    Test if the class was called in the options class or class 7keys
    and defines what the next screen depending on where it was called
    */
    string next_screen = SevenKeys::ScreenType::HEADPHONE;
    if(this->options){
        next_screen = SevenKeys::ScreenType::OPTIONS;
    }else{
        next_screen = SevenKeys::ScreenType::HEADPHONE;
    }

    /*
    Verifies that the english language button was pressed and
    sets the language of the game as english
     */
    if (button->id() == ENGLISH_BUTTON_NAME)
    {
        set_next(next_screen);
        set_language(Internacionalization::LanguageType::ENGLISH_LANGUAGE);
    }
    /*
    Verifies that the espanish language button was pressed and
    sets the language of the game as espanish
     */
    else if (button->id() == ESPANISH_BUTTON_NAME)
    {
        set_next(next_screen);
        set_language(Internacionalization::LanguageType::ESPANISH_LANGUAGE);
    }
    /*
    Verifies that the portuguese language button was pressed and
    sets the language of the game as portuguese
     */
    else if (button->id() == PORTUGUESE_BUTTON_NAME)
    {
        set_next(next_screen);
        set_language(Internacionalization::LanguageType::PORTUGUESE_LANGUAGE);
    }
    /*
    Verifies that the french language button was pressed and
    sets the language of the game as french
     */
    else if (button->id() == FRENCH_BUTTON_NAME)
    {
        set_next(next_screen);
        set_language(Internacionalization::LanguageType::FRENCH_LANGUAGE);

    }
    //Button functionality not implemented, sets the language of the game as default language
    else if (button->id() == NEXT_BUTTON_NAME)
    {
        set_next(next_screen);
        set_language(DEFAULT_LANGUAGE_PATH);
    }
    //Button functionality not implemented, sets the language of the game as default language
    else if (button->id() == PREVIOUS_BUTTON_NAME)
    {
        set_next(next_screen);
        set_language(DEFAULT_LANGUAGE_PATH);
    }else{
        //do nothing
    }

    finish();

    return true;
}

void Internacionalization::set_language(const string& language)
{
    //
    ofstream language_preferences;
    language_preferences.open("language_preferences.txt", ios::out);
    language_preferences << language << endl;
    language_preferences.close();
}


string Internacionalization::get_language()
{
    ifstream language_preferences;
    language_preferences.open("language_preferences.txt", ios::in);
    string language = "no language";
    getline (language_preferences,language);
    language_preferences.close();
    return language;
}

string Internacionalization::load_string(const string& source_to_translate)
{
    string path_string = (Internacionalization::GAME_RESOURCE_PATH +
                         "/" + Internacionalization::get_language() +
                         "/" + source_to_translate);;
    return path_string;
}

bool Internacionalization::LanguageType::is_language(){
    const string language = Internacionalization::get_language();
    if(language != Internacionalization::LanguageType::ENGLISH_LANGUAGE &&
       language != Internacionalization::LanguageType::ESPANISH_LANGUAGE &&
       language != Internacionalization::LanguageType::PORTUGUESE_LANGUAGE &&
       language != Internacionalization::LanguageType::FRENCH_LANGUAGE){
        return false;
    }else{
        return true;
    }
}
