/*
 * Classe que representa um retângulo no espaço bidimensional.
 *
 * Autor: Edson Alves
 * Data: 13/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef RECT_H
#define RECT_H

class Rect
{
public:
    Rect(double horizontal_position = 0, double vertical_position = 0, double width = 0, double height = 0);

    double horizontal_position() const;
    double vertical_position() const;
    double width() const;
    double height() const;

    void set_horizontal_position(double horizontal_position);
    void set_vertical_position(double vertical_position);
    void set_width(double width);
    void set_height(double height);

    void set_position(double horizontal_position, double vertical_position);
    void set_dimensions(double width, double height);

    bool contains(double horizontal_position, double vertical_position) const;
    Rect intersection(const Rect& r) const;

protected:
    double m_horizontal_position, m_vertical_position;
    double m_width, m_height;
};

#endif
