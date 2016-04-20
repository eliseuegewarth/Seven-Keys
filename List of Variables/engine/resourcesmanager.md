#Resources Manager

###variables

class Texture;
class Font;
class Music;
class SoundEffect;
class Bitmap;
class Settings;

class ResourcesManager:
    <!--
    private:
    map < string, shared_ptr<Texture> > m_textures;
    map < string, shared_ptr<Font> > m_fonts;
    map < string, shared_ptr<Music> > m_musics;
    map < string, shared_ptr<SoundEffect> > m_sound_effects;
    map < string, shared_ptr<Bitmap> > m_bitmaps;
    map < string, shared_ptr<Settings> > m_settings;

    shared_ptr<Texture> acquire_texture(const string& id) throw (Exception);
    shared_ptr<Font> acquire_font(const string& id) throw (Exception);
    shared_ptr<Music> acquire_music(const string& id) throw (Exception);
    shared_ptr<SoundEffect> acquire_sound_effect(const string& id) throw (Exception);
    shared_ptr<Bitmap> acquire_bitmap(const string& id) throw (Exception);
    shared_ptr<Settings> acquire_settings(const string& id) throw (Exception);
    -->
##ResourcesManager::get_texture()
###parameters
    ·const string& id

##ResourcesManager::acquire_texture()
###parameters
    ·const string& id
###variables and methods
    ·Texture * texture = Texture::from_file(id);

##ResourcesManager::get_font()
###parameters
    ·const string& id

##ResourcesManager::acquire_font()
###parameters
    ·const string& id
###variables and methods
    ·Font * font = Font::from_file(id);

##ResourcesManager::get_music()
###parameters
    ·const string& id

##ResourcesManager::acquire_music()
###parameters
    ·const string& id
###variables and methods
    ·Music * music = Music::from_file(id);

##ResourcesManager::get_sound_effect()
###parameters
    ·const string& id

##ResourcesManager::acquire_sound_effect(const string& id) throw (Exception)
###parameters
    ·const string& id
###variables and methods
    ·SoundEffect * sfx = SoundEffect::from_file(id);

##ResourcesManager::get_bitmap()
###parameters
    ·const string& id

##ResourcesManager::get_settings()
###parameters
    ·const string& id

##ResourcesManager::acquire_bitmap()
###parameters
    ·const string& id
###variables and methods
    ·Bitmap * bitmap = Bitmap::from_file(id);

##ResourcesManager::acquire_settings()
###parameters
    ·const string& id
###variables and methods
    ·Settings * settings = Settings::from_file(id);

##void ResourcesManager::scale()
###parameters
    ·double k
###variables and methods
    ·shared_ptr<Texture> texture = t.second;
