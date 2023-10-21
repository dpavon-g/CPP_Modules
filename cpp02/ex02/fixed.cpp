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

// Operadores de multiplicación y división.

Fixed Fixed::operator*(const Fixed &n2) {
    return Fixed(this->toFloat() * n2.toFloat());
}

Fixed Fixed::operator/(const Fixed &n2) {
    return Fixed(this->toFloat() / n2.toFloat());
}

// Operadores de suma y resta.

Fixed Fixed::operator+(const Fixed &n2) {
    return Fixed(this->toFloat() + n2.toFloat());
}

Fixed Fixed::operator-(const Fixed &n2) {
    return Fixed(this->toFloat() - n2.toFloat());
}

// Operadores de pre y post incremento y decremento.

Fixed&	Fixed::operator++() {
    ++this->point_number;
    return *this;
}

Fixed	Fixed::operator++(int) {
    Fixed temp(*this);
    temp.point_number = this->point_number;
    this->point_number++;
    return temp;
}

Fixed&	Fixed::operator--() {
    --this->point_number;
    return *this;
}

Fixed	Fixed::operator--(int) {
    Fixed temp(*this);
    temp.point_number = this->point_number;
    this->point_number--;
    return temp;
}

// Operadores de comparación.

bool Fixed::operator<(const Fixed& other) const {
        return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other) const {
        return this->toFloat() > other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) const {
        return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) const {
        return this->toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const {
        return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) const {
        return !(this->toFloat() == other.toFloat());
}

Fixed Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a : b);
}

Fixed Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a : b);
}

Fixed Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}

Fixed Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}