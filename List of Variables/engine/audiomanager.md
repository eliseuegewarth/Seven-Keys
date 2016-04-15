#AudioManager


##namespace

    ·static constexpr auto k_all_channels
    ·static constexpr auto k_any_channel

##AudioManager<AudioType::Music>::AudioManager()

##void AudioManager<AudioType::Music>::play(const string& path, const int times)
    ·const auto music
    ·Environment::get_instance()->resources_manager->get_music(path);
    ·const auto k_played_music

##void AudioManager<AudioType::Music>::set_volume(const int percent)
    ·const auto k_volume_value

##void AudioManager<AudioType::Music>::pause()

##void AudioManager<AudioType::Music>::resume()

##void AudioManager<AudioType::Music>::stop()

##void AudioManager<AudioType::Music>::fade_out(const double seconds)
    ·const auto k_milliseconds
    ·static_cast<int>(seconds*1000);
    ·const auto k_faded

##bool AudioManager<AudioType::Music>::faded_out()
    ·const auto k_fading
    ·const auto k_playing

##AudioManager<AudioType::SoundEffect>::AudioManager()

##void AudioManager<AudioType::SoundEffect>::play(const string& path, const int times)
    ·const auto sound_effect

    ·Environment::get_instance()->resources_manager->get_sound_effect(path);
    ·const auto k_played_channel

##void AudioManager<AudioType::SoundEffect>::set_volume(const int percent)
    ·const auto k_volume_value


##void AudioManager<AudioType::SoundEffect>::pause()

##void AudioManager<AudioType::SoundEffect>::resume()

##void AudioManager<AudioType::SoundEffect>::stop()

##void AudioManager<AudioType::SoundEffect>::fade_out(const double seconds)
    ·const auto k_milliseconds
    ·static_cast<int>(seconds*1000);
