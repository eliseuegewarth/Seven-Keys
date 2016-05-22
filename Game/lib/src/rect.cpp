/*
 * Implementação da lasse que representa um retângulo no espaço bidimensional.
 *
 * Autor: Edson Alves
 * Data: 13/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/rect.h"

#include <iostream>

using std::min;
using std::max;

Rect::Rect(double x, double y, double width, double height)
    : m_x(x), m_y(y), m_width(width), m_height(height)
{
}

double
Rect::x() const
{
    return m_x;
}

double
Rect::y() const
{
    return m_y;
}

double
Rect::width() const
{
    return m_width;
}

double
Rect::height() const
{
    return m_height;
}

void
Rect::set_x(double x)
{
    m_x = x;
}

void
Rect::set_y(double y)
{
    m_y = y;
}

void
Rect::set_width(double width)
{
    m_width = width;
}

void
Rect::set_height(double height)
{
    m_height = height;
}

void
Rect::set_position(double x, double y)
{
    m_x = x;
    m_y = y;
}

void
Rect::set_dimensions(double width, double height)
{
    m_width = width;
    m_height = height;
}

bool
Rect::contains(double x, double y) const
{
    return x >= m_x and x <= m_x + m_width and y >= m_y and y <= m_y + m_height;
}

Rect
Rect::intersection(const Rect& r) const
{
    typedef struct _Area
    {
        double left, right;
        double top, bottom;
    } Area;

    Area a { x(), x() + width(), y(), y() + height() };
    Area b { r.x(), r.x() + r.width(), r.y(), r.y() + r.height() };

    if (b.right < a.left or b.left > a.right or b.top > a.bottom
        or b.bottom < a.top)
    {
        return Rect(0, 0, 0, 0);
    }
    else
    {
        double xmin = (max)(a.left, b.left);
        double xmax = (min)(a.right, b.right);
        double ymin = (max)(a.top, b.top);
        double ymax = (min)(a.bottom, b.bottom);

        return Rect(xmin, ymin, xmax - xmin, ymax - ymin);
    }
}
