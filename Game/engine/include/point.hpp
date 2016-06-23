/*
 * Classe que representa um ponto no espaço bidimensional.
 *
 * Autor: Edson Alves
 * Data: 13/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(double horizontal_position = 0, double vertical_position = 0);

    double horizontal_position() const;
    double vertical_position() const;

    void set_horizontal_position(double horizontal_position);
    void set_vertical_position(double vertical_position);
    void set(double horizontal_position, double vertical_position);

private:
    double m_horizontal_position, m_vertical_position;
};

#endif
