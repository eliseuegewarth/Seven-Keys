#AudioManagerWrapper

###variables
```c++
AudioManagerSfx * sfx() const;
```
```c++
AudioManagerMusic * music() const;
```

##```AudioManagerWrapper::AudioManagerWrapper()```

##```AudioManagerWrapper::~AudioManagerWrapper()```

##```void AudioManagerWrapper::init()```

##```AudioManagerSfx * AudioManagerWrapper::sfx() const```

##```AudioManagerMusic * AudioManagerWrapper::music() const```

##```void AudioManagerWrapper::open_audio()```

##```void AudioManagerWrapper::close_audio()```
###variables
```c++
int frequency
```
```c++
int channels
```
```c++
const int k_numbers_of_times_opened
```
```c++
int times_to_close
```
