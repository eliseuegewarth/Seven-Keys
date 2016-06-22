/*
 * Classe que representa uma animação.
 *
 * Autor: Edson Alves
 * Data: 05/05/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <memory>

using std::string;
using std::unique_ptr;


class Animation
{
public:
    Animation(const string& image, double horizontal_position, double vertical_position, double width, double h,
        int frames, unsigned long speed_in_ms, bool loop = false);
    ~Animation();

    bool is_done() const;

    void update(unsigned long elapsed);
    void draw(double horizontal_position, double vertical_position);

    double w() const;
    double h() const;

    void set_row(int row);

private:
    class Impl;
    unique_ptr<Impl> m_impl;
};

#endif
