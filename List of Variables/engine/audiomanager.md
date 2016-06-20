#AudioManager

##```class AudioManager final```

###variables
```c++
static constexpr int k_infinite_loop = -1;
```
```c++
enum class AudioType
```
##namespace
```c++
static constexpr auto k_all_channels
```
```c++
static constexpr auto k_any_channel
```

##```AudioManager<AudioType::Music>::AudioManager()```

##```void AudioManager<AudioType::Music>::play()```
###parameters
```c++
const string& path
```
```c++
const int times
```
###variables
```c++
const auto music
```
```c++
const auto k_played_music
```

##```void AudioManager<AudioType::Music>::set_volume()```
###parameters
```c++
const int percent
```
###variables
```c++
const auto k_volume_value
```

##```void AudioManager<AudioType::Music>::pause()```

##```void AudioManager<AudioType::Music>::resume()```

##```void AudioManager<AudioType::Music>::stop()```

##```void AudioManager<AudioType::Music>::fade_out()```
###parameters
```c++
const double seconds
```
###variables
```c++
const auto k_milliseconds
```
```c++
static_cast<int>(seconds*1000);
```
```c++
const auto k_faded
```
##```bool AudioManager<AudioType::Music>::faded_out()```
```c++
const auto k_fading
```
```c++
const auto k_playing
```

##```AudioManager<AudioType::SoundEffect>::AudioManager()```

##```void AudioManager<AudioType::SoundEffect>::play()```
###parameters
```c++
const string& path
```
```c++
const int times
```
###variables
```c++
const auto sound_effect
```
```c++
const auto k_played_channel
```

##```void AudioManager<AudioType::SoundEffect>::set_volume()```
###parameters
```c++
const int percent
```
###variables
```c++
const auto k_volume_value
```
##```void AudioManager<AudioType::SoundEffect>::pause()```

##```void AudioManager<AudioType::SoundEffect>::resume()```

##```void AudioManager<AudioType::SoundEffect>::stop()```

##```void AudioManager<AudioType::SoundEffect>::fade_out()```
###parameters
```c++
const double seconds
```
###variables
```c++
const auto k_milliseconds
```
