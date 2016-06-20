/*
 * Class that represents a texture.
 * Licença: LGPL. Sem copyright.
 */
#ifndef TEXTURE_H
#define TEXTURE_H

#include "core/exception.hpp"

#include <string>
#include <memory>

using std::pair;
using std::string;
using std::unique_ptr;

class Texture
{
public:
    Texture(void *data, int width, int height);
    ~Texture();

    int width() const;
    int height() const;
    void * data() const;

    static Texture * from_file(const string& path) throw (Exception);

    void scale(double k);
    pair<int, int> size() const;

private:
    class Impl;
    unique_ptr<Impl> m_impl;
};

#endif
