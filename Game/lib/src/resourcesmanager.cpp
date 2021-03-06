/*
 * Implementação da classe que representa um gerenciador de recursos
 * reutilizáveis.
 *
 * Autor: Edson Alves
 * Data: 20/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/resourcesmanager.hpp"

#include "core/texture.hpp"
#include "core/font.hpp"
#include "core/music.hpp"
#include "core/soundeffect.hpp"
#include "core/bitmap.hpp"
#include "core/settings.hpp"

shared_ptr<Texture>
ResourcesManager::get_texture(const string& id) throw (Exception)
{
    if (m_textures.find(id) != m_textures.end())
    {
        return m_textures[id];
    }else{
        //do nothing
    }

    return acquire_texture(id);
}

shared_ptr<Texture>
ResourcesManager::acquire_texture(const string& id) throw (Exception)
{
    Texture *texture = Texture::from_file(id);

    if (not texture)
    {
        throw Exception("Can't load texture " + id);
    }else{
        //do nothing
    }

    shared_ptr<Texture> ptr(texture);
    m_textures[id] = ptr;

    return ptr;
}

shared_ptr<Font>
ResourcesManager::get_font(const string& id) throw (Exception)
{
    if (m_fonts.find(id) != m_fonts.end())
    {
        return m_fonts[id];
    }else{
        //do nothing
    }

    return acquire_font(id);
}

shared_ptr<Font>
ResourcesManager::acquire_font(const string& id) throw (Exception)
{
    Font *font = Font::from_file(id);

    if (not font)
    {
        throw Exception("Can't load font " + id);
    }else{
        //do nothing
    }

    shared_ptr<Font> ptr(font);
    m_fonts[id] = ptr;

    return ptr;
}

shared_ptr<Music>
ResourcesManager::get_music(const string& id) throw (Exception)
{
    if (m_musics.find(id) != m_musics.end())
    {
        return m_musics[id];
    }else{
        //do nothing
    }

    return acquire_music(id);
}

shared_ptr<Music>
ResourcesManager::acquire_music(const string& id) throw (Exception)
{
    Music *music = Music::from_file(id);

    if (not music)
    {
        throw Exception("Can't load music " + id);
    }else{
        //do nothing
    }

    shared_ptr<Music> ptr(music);
    m_musics[id] = ptr;

    return ptr;
}

shared_ptr<SoundEffect>
ResourcesManager::get_sound_effect(const string& id) throw (Exception)
{
    if (m_sound_effects.find(id) != m_sound_effects.end())
    {
        return m_sound_effects[id];
    }else{
        //do nothing
    }

    return acquire_sound_effect(id);
}

shared_ptr<SoundEffect>
ResourcesManager::acquire_sound_effect(const string& id) throw (Exception)
{
    SoundEffect *sfx = SoundEffect::from_file(id);

    if (not sfx)
    {
        throw Exception("Can't load sound effect " + id);
    }else{
        //do nothing
    }

    shared_ptr<SoundEffect> ptr(sfx);
    m_sound_effects[id] = ptr;

    return ptr;
}

shared_ptr<Bitmap>
ResourcesManager::get_bitmap(const string& id) throw (Exception)
{
    if (m_bitmaps.find(id) != m_bitmaps.end())
    {
        return m_bitmaps[id];
    }else{
        //do nothing
    }

    return acquire_bitmap(id);
}

shared_ptr<Settings>
ResourcesManager::get_settings(const string& id) throw (Exception)
{
    if (m_settings.find(id) != m_settings.end())
    {
        return m_settings[id];
    }else{
        //do nothing
    }

    return acquire_settings(id);
}

shared_ptr<Bitmap>
ResourcesManager::acquire_bitmap(const string& id) throw (Exception)
{
    Bitmap *bitmap = Bitmap::from_file(id);

    if (not bitmap)
    {
        throw Exception("Can't load bitmap " + id);
    }else{
        //do nothing
    }

    shared_ptr<Bitmap> ptr(bitmap);
    m_bitmaps[id] = ptr;

    return ptr;
}

shared_ptr<Settings>
ResourcesManager::acquire_settings(const string& id) throw (Exception)
{
    Settings *settings = Settings::from_file(id);

    if (not settings)
    {
        settings = new Settings();
    }else{
        //do nothing
    }

    shared_ptr<Settings> ptr(settings);
    m_settings[id] = ptr;

    return ptr;
}

void
ResourcesManager::scale(double k)
{
    for (auto t : m_textures)
    {
        shared_ptr<Texture> texture = t.second;
        texture->scale(k);
    }
}
