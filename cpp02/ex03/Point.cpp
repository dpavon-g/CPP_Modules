# include "Point.hpp"

Point::Point() : x(0), y(0) {
    std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {
    std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const Fixed &n1, const Fixed &n2) : x(n1), y(n2){
    std::cout << "Reference constructor called" << std::endl;
}

Point::~Point() {
    std::cout << "Destructor called" << std::endl;
}

// Point   Point::getPoint() const {
//     return *this;
// }

Fixed   Point::getx() const{
    return this->x;
}

Fixed   Point::gety() const{
    return this->y;
}

Point&  Point::operator=(const Point &copy){
    std::cout << "Assignation operator called" << std::endl;
    ( Fixed ) this->x = copy.x;
    ( Fixed ) this->y = copy.y;
    return *this;
}