#include "fixed.hpp"

Fixed::Fixed() : point_number(0) {
    std::cout << "Default constructor called" << std::endl;
    (void)this->point_number;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed&  Fixed::operator=(const Fixed &copy) {
    std::cout << "Assignation operator called" << std::endl;
    this->point_number = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->point_number);
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->point_number = raw;
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    this->point_number = roundf(n * (1 << this->n_bits));
}

Fixed::Fixed(int const n) {
    std::cout << "Int constructor called" << std::endl;
    this->point_number = n << this->n_bits;
}

int Fixed::toInt( void ) const {
    return (this->point_number >> this->n_bits);
}

float Fixed::toFloat( void ) const {
    return ((double)this->point_number / (double)(1 << this->n_bits));
}

std::ostream &operator << (std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}