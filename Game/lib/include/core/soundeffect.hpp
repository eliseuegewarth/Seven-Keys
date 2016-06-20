/*
 * Class which represents a sound effect file.
 * Licença: LGPL. Sem copyright.
 */
#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H

#include <string>
#include <memory>
#include <SDL2/SDL_mixer.h>
#include "core/exception.hpp"

using std::string;
using std::unique_ptr;

class SoundEffect
{
public:
    explicit SoundEffect(Mix_Chunk* const soundeffect);
    ~SoundEffect();

    Mix_Chunk* mix_chunk() const;
    int channel() const;
    void set_channel(const int channel);

    static SoundEffect * from_file(const string& path) throw (Exception);

private:
    class Impl;
    unique_ptr<Impl> m_impl;
};

#endif
