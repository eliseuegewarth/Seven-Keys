/*
 * Implementação da classe que representa um ponto no espaço bidimensional.
 *
 * Autor: Edson Alves
 * Data: 13/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/point.hpp"

Point::Point(double horizontal_position, double vertical_position)
    : m_horizontal_position(horizontal_position), m_vertical_position(vertical_position)
{
}

double
Point::horizontal_position() const
{
    return m_horizontal_position;
}

double
Point::vertical_position() const
{
    return m_vertical_position;
}

void
Point::set_horizontal_position(double horizontal_position)
{
    m_horizontal_position = horizontal_position;
}

void
Point::set_vertical_position(double vertical_position)
{
    m_vertical_position = vertical_position;
}

void
Point::set(double horizontal_position, double vertical_position)
{
    m_horizontal_position = horizontal_position;
    m_vertical_position = vertical_position;
}
