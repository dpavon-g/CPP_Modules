#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int	point_number;
		static const int n_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

# endif