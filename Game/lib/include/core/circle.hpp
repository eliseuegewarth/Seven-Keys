/*
 * Class that represents a circle in bidimensional space. 
 */
#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.hpp"

class Circle
{
    public:
        Circle(const Point& center_point_of_circle = Point(), double circle_radius = 0);

        Point center() const;
        
        double radius() const;
        
        void set_center(const Point& center_point_of_circle);
    
        void set_radius(double circle_radius);

        void set(const Point& center_point_of_circle, double circle_radius);

    private:

        // Point type attribute that is the reference center of the circle object.
        Point center_point_of_circle;

        // Attribute of double type that represents the circumference radius of the circle object. 
        double circle_radius;
};

#endif
