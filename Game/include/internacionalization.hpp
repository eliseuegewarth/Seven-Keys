/**
 * internacionalization.hpp
 * Class that implements the Internacionalization class. That Class implements multi language support.
 * Licença: LGPL. Sem copyright.
 */

#ifndef INTERNACIONALIZATION_HPP
#define INTERNACIONALIZATION_HPP

#include "core/level.hpp"
#include <string>

#define DEFAULT_LANGUAGE_PATH "EN-US"
#define LANGUAGE_PATH "language"
class Image;

class Internacionalization : public Level
{
public:

    class LanguageType
    {
    public:
        static const string& ENGLISH_LANGUAGE;
        static const string& ESPANISH_LANGUAGE;
        static const string& PORTUGUESE_LANGUAGE;
        static const string& FRENCH_LANGUAGE;

        static bool is_language();
    };
    /*static string load_string(const string& language, const string& source_to_translate);*/
    Internacionalization(bool options);

    static string load_string(const string& source_to_translate);
    virtual ~Internacionalization();
    static string get_language();
    bool on_message(Object *object, MessageID id, Parameters);

private:
    bool options;
    void set_language(const string& language);
    static const string GAME_RESOURCE_PATH;
    string game_language;
    void draw_self();
};

#endif
