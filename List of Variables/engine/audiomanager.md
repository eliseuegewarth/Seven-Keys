#AudioManager

##class AudioManager final

###variables
    ·static constexpr int k_infinite_loop = -1;
    ·enum class AudioType

##namespace
    ·static constexpr auto k_all_channels
    ·static constexpr auto k_any_channel

##AudioManager<AudioType::Music>::AudioManager()

##void AudioManager<AudioType::Music>::play()
###parameters
    ·const string& path
    ·const int times
###variables
    ·const auto music
    ·const auto k_played_music

##void AudioManager<AudioType::Music>::set_volume()
###parameters
    ·const int percent
###variables
    ·const auto k_volume_value

##void AudioManager<AudioType::Music>::pause()

##void AudioManager<AudioType::Music>::resume()

##void AudioManager<AudioType::Music>::stop()

##void AudioManager<AudioType::Music>::fade_out()
###parameters
    ·const double seconds
###variables
    ·const auto k_milliseconds
    ·static_cast<int>(seconds*1000);
    ·const auto k_faded

##bool AudioManager<AudioType::Music>::faded_out()
    ·const auto k_fading
    ·const auto k_playing

##AudioManager<AudioType::SoundEffect>::AudioManager()

##void AudioManager<AudioType::SoundEffect>::play()
###parameters
    ·const string& path
    ·const int times
###variables
    ·const auto sound_effect
    ·const auto k_played_channel

##void AudioManager<AudioType::SoundEffect>::set_volume()
###parameters
    ·const int percent
###variables
    ·const auto k_volume_value

##void AudioManager<AudioType::SoundEffect>::pause()

##void AudioManager<AudioType::SoundEffect>::resume()

##void AudioManager<AudioType::SoundEffect>::stop()

##void AudioManager<AudioType::SoundEffect>::fade_out()
###parameters
    ·const double seconds
###variables
    ·const auto k_milliseconds
