/*
 * Implementação da lasse que representa um retângulo no espaço bidimensional.
 *
 * Autor: Edson Alves
 * Data: 13/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/rect.hpp"

#include <iostream>

using std::min;
using std::max;

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param horizontal_position [description]
 * @param vertical_position [description]
 * @param width [description]
 * @param height [description]
 */
Rect::Rect(double horizontal_position, double vertical_position, double width, double height)  
{
    m_horizontal_position = horizontal_position;
    m_vertical_position = vertical_position;
    m_width = width;
    m_height = height;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
double Rect::horizontal_position() const
{
    return m_horizontal_position;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
double Rect::vertical_position() const
{
    return m_vertical_position;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
double Rect::width() const
{
    return m_width;
}
/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
double Rect::height() const
{
    return m_height;
}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param horizontal_position [description]
 */
void Rect::set_horizontal_position(double horizontal_position)
{
    m_horizontal_position = horizontal_position;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param vertical_position [description]
 */
void Rect::set_vertical_position(double vertical_position)
{
    m_vertical_position = vertical_position;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param width [description]
 */
void Rect::set_width(double width)
{
    m_width = width;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param height [description]
 */
void Rect::set_height(double height)
{
    m_height = height;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param horizontal_position [description]
 * @param vertical_position [description]
 */
void Rect::set_position(double horizontal_position, double vertical_position)
{
    m_horizontal_position = horizontal_position;
    m_vertical_position = vertical_position;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param width [description]
 * @param height [description]
 */
void Rect::set_dimensions(double width, double height)
{
    m_width = width;
    m_height = height;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param horizontal_position [description]
 * @param vertical_position [description]
 * 
 * @return [description]
 */
bool Rect::contains(double horizontal_position, double vertical_position) const
{
    return horizontal_position >= m_horizontal_position and horizontal_position <= m_horizontal_position + m_width and vertical_position >= m_vertical_position and vertical_position <= m_vertical_position + m_height;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param r [description]
 * @return [description]
 */
Rect Rect::intersection(const Rect& r) const
{
    typedef struct _Area
    {
        double left, right;
        double top, bottom;
    } Area;

    Area a { horizontal_position(), horizontal_position() + width(), vertical_position(), vertical_position() + height() };
    Area b { r.horizontal_position(), r.horizontal_position() + r.width(), r.vertical_position(), r.vertical_position() + r.height() };

    if (b.right < a.left or b.left > a.right or b.top > a.bottom
        or b.bottom < a.top)
    {
        return Rect(0, 0, 0, 0);
    }
    else
    {
        double horizontal_position_min = (max)(a.left, b.left);
        double horizontal_position_max = (min)(a.right, b.right);
        double vertical_position_min = (max)(a.top, b.top);
        double vertical_position_max = (min)(a.bottom, b.bottom);

        return Rect(horizontal_position_min, vertical_position_min, 
                            horizontal_position_max - horizontal_position_min, 
                            vertical_position_max - vertical_position_min);
    }
}
