#```Class Circle```
Class that represents a circle in bidimensional space.
##Public:
###```Circle(const Point& center_point_of_circle = Point(), double circle_radius = 0)```
Circle class constructor that has the radius and the reference center as parameters.
####Parameters
#####```const Point& center_point_of_circle```
Parameter that contains information of the circle's Reference Center that will be instantiated.
#####```double circle_radius```
Parameter that contains the information of the circle radius that will be instantiated.
--
###```Point center() const```
This method returns the information of the circle's Reference Center.
--
###```double radius() const```
This method returns the information of the circle radius.
--
###```void set_center(const Point& center_point_of_circle)```
Changes circle reference center.
####Parameters
#####```const Point& center_point_of_circle```
Parameter that contains information of the circle's Reference Center that will be instantiated.
--
###```void set_radius(double circle_radius)```
Changes circle radius.
####Parameters
#####```double circle_radius```
Parameter that contains the information of the circle radius that will be instantiated.
--
###```void set(const Point& center_point_of_circle, double circle_radius)```
Changes the circle features.
####Parameters
#####```const Point& center_point_of_circle```
Parameter that contains information of the circle's Reference Center that will be instantiated.
#####```double circle_radius```
Parameter that contains the information of the circle radius that will be instantiated.
--
##Private:
###```Point center_point_of_circle```
Point type attribute that is the reference center of the circle object.
--
###```double circle_radius```
Attribute of double type that represents the circumference radius of the circle object. 
--
