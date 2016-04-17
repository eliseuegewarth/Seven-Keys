#Resources Manager

##ResourcesManager::get_texture(const string& id) throw (Exception)

##ResourcesManager::acquire_texture(const string& id) throw (Exception)
    ·Texture *texture = Texture::from_file(id);
    ·m_textures[id] = ptr;

##ResourcesManager::get_font(const string& id) throw (Exception)

##ResourcesManager::acquire_font(const string& id) throw (Exception)
    ·Font *font = Font::from_file(id);
    ·m_fonts[id] = ptr;

##ResourcesManager::get_music(const string& id) throw (Exception)

##ResourcesManager::acquire_music(const string& id) throw (Exception)
    ·Music *music = Music::from_file(id);
    ·m_musics[id] = ptr;

##ResourcesManager::get_sound_effect(const string& id) throw (Exception)

##ResourcesManager::acquire_sound_effect(const string& id) throw (Exception)
    ·SoundEffect *sfx = SoundEffect::from_file(id);
    ·m_sound_effects[id] = ptr;

##ResourcesManager::get_bitmap(const string& id) throw (Exception)

##ResourcesManager::get_settings(const string& id) throw (Exception)

##ResourcesManager::acquire_bitmap(const string& id) throw (Exception)
    ·Bitmap *bitmap = Bitmap::from_file(id);
    ·m_bitmaps[id] = ptr;

##ResourcesManager::acquire_settings(const string& id) throw (Exception)
    ·Settings *settings = Settings::from_file(id);
    ·settings = new Settings();
    ·m_settings[id] = ptr;

##void ResourcesManager::scale(double k)
    ·shared_ptr<Texture> texture = t.second;
