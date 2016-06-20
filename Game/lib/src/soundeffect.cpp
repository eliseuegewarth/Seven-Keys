/*
 Implementation of AudioHandler class.
 * Licença: LGPL. Sem copyright.
 */
#include "core/soundeffect.hpp"

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param soundeffect [description]
 * @return [description]
 */
class SoundEffect::Impl
{
public:
    Impl(Mix_Chunk* const soundeffect)
        : m_mix_chunk{soundeffect}, m_channel{-1}
    {
    }

    ~Impl()
    {
        if (m_mix_chunk != nullptr)
        {
            Mix_FreeChunk(m_mix_chunk);
        }
    }

    Mix_Chunk * mix_chunk() const
    {
        return m_mix_chunk;
    }

    int channel() const
    {
        return m_channel;
    }

    void set_channel(const int channel)
    {
        m_channel = channel;
    }

private:
    Mix_Chunk* const m_mix_chunk;
    int m_channel;
};

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param soundeffect [description]
 */
SoundEffect::SoundEffect(Mix_Chunk* const soundeffect)
    : m_impl(new Impl(soundeffect))
{

}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
SoundEffect::~SoundEffect()
{
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
Mix_Chunk* SoundEffect::mix_chunk() const
{
    return m_impl->mix_chunk();
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int SoundEffect::channel() const
{
    return m_impl->channel();
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param channel [description]
 */
void SoundEffect::set_channel(const int channel)
{
    m_impl->set_channel(channel);
}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param path [description]
 * @return [description]
 */
SoundEffect * SoundEffect::from_file(const string& path) throw (Exception)
{
    Mix_Chunk *soundeffect = Mix_LoadWAV(path.c_str());

    if (soundeffect == nullptr)
    {
        throw Exception(Mix_GetError());
    }

    SoundEffect *sfx = new SoundEffect(soundeffect);

    if (not sfx)
    {
        throw Exception("Out of memory for a new SoundEffect");
    }

    return sfx;
}
