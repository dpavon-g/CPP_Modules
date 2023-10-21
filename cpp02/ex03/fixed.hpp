#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <math.h>

class Fixed
{
	private:
		int	point_number;
		static const int n_bits = 8;
	public:
		Fixed();
		Fixed(int const n);
		Fixed(const float n);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		Fixed	operator*(const Fixed &n2);
		Fixed	operator/(const Fixed &n2);
		Fixed	operator+(const Fixed &n2);
		Fixed	operator-(const Fixed &n2);
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		static Fixed	max(const Fixed& a, const Fixed& b);
		static Fixed	min(const Fixed& a, const Fixed& b);
		static Fixed	max(Fixed& a, Fixed& b);
		static Fixed	min(Fixed& a, Fixed& b);
};

std::ostream &operator << (std::ostream &out, Fixed const &fixed);

# endif


