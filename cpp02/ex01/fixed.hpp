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
};

std::ostream &operator << (std::ostream &out, Fixed const &fixed);

# endif


