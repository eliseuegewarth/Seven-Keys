/*
 * Implementation of class that represents a circle in bidimensional space.
 */
#include "core/circle.hpp"

#include <cassert> 

/**
 * @brief [Circle class constructor that has the radius and the reference center as parameters.]
 * 
 * @param center_point_of_circle [Parameter that contains information of the circle's Reference Center that will be instantiated.]
 * @param circle_radius [Parameter that contains the information of the circle radius that will be instantiated.]
 */
Circle::Circle(const Point& center_point_of_circle, double circle_radius)
{
    this->center_point_of_circle = (center_point_of_circle);
    this->set_radius(circle_radius);
}

/**
 * @brief [This method returns the information of the circle's Reference Center.]
 * @return [Return a Point object of circle's Reference Center.]
 */
Point Circle::center() const
{
    return this->center_point_of_circle;
}

/**
 * @brief [This method returns the information of the circle radius.]
 * @return [Return a double value.]
 */
double Circle::radius() const
{
    return this->circle_radius;
}

/**
 * @brief [Changes circle reference center.]
 * 
 * @param center_point_of_circle [Parameter that contains information of the circle's Reference Center that will be instantiated.]
 */
void Circle::set_center(const Point& center_point_of_circle)
{
    this->center_point_of_circle = center_point_of_circle;
}

/**
 * @brief [Changes circle radius.]
 * 
 * @param circle_radius [Parameter that contains the information of the circle radius that will be instantiated.]
 */
void Circle::set_radius(double circle_radius)
{
    assert(circle_radius > 0);
    this->circle_radius = circle_radius;
}

/**
 * @brief [Changes the circle features.]
 * 
 * @param center_point_of_circle [Parameter that contains information of the circle's Reference Center that will be instantiated.]
 * @param circle_radius [Parameter that contains the information of the circle radius that will be instantiated.]
 */
void
Circle::set(const Point& center_point_of_circle, double circle_radius)
{
    this->set_center( center_point_of_circle);
    this->set_radius( circle_radius);
}
