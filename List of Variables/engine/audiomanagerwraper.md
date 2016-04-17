#AudioManagerWrapper

##AudioManagerWrapper::AudioManagerWrapper()

##AudioManagerWrapper::~AudioManagerWrapper()

##void AudioManagerWrapper::init() throw (Exception)
    ·sfx_manager = new AudioManagerSfx();
    ·music_manager = new AudioManagerMusic();

##AudioManagerSfx * AudioManagerWrapper::sfx() const

##AudioManagerMusic * AudioManagerWrapper::music() const

##void AudioManagerWrapper::open_audio()

##void AudioManagerWrapper::close_audio()
    ·int frequency
    ·int channels
    ·Uint16 format
    ·const int k_numbers_of_times_opened = Mix_QuerySpec(&frequency, &format, &channels);
    ·int times_to_close = k_numbers_of_times_opened;
