#include "Point.hpp"

int main( void ) {
    const Point a(Fixed(1.5f), Fixed(1.5f));
    const Point b(Fixed(3.5f), Fixed(4.5f));
    const Point c(Fixed(4.5f), Fixed(1.5f));

    const Point p(Fixed(3.67f), Fixed(2.88f));

    if (bsp(a, b, c, p))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    return (0);
}