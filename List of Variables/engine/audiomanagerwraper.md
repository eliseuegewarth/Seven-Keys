#AudioManagerWrapper

###variables
    ·AudioManagerSfx * sfx() const;
    ·AudioManagerMusic * music() const;

##AudioManagerWrapper::AudioManagerWrapper()

##AudioManagerWrapper::~AudioManagerWrapper()

##void AudioManagerWrapper::init()

##AudioManagerSfx * AudioManagerWrapper::sfx() const

##AudioManagerMusic * AudioManagerWrapper::music() const

##void AudioManagerWrapper::open_audio()

##void AudioManagerWrapper::close_audio()
###variables
    ·int frequency
    ·int channels
    ·const int k_numbers_of_times_opened
    ·int times_to_close
