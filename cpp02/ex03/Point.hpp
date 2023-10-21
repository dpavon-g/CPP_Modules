#ifndef POINT_H
# define POINT_H

# include <iostream>
# include <math.h>
# include "fixed.hpp"

class Point
{
	private:
                Fixed const x;
                Fixed const y;
	public:
                Fixed   getx() const;
                Fixed   gety() const;
                Point();
                Point(const Point &copy);
                Point(const Fixed &n1, const Fixed &n2);
                Point &operator=(const Point &copy);
                // Point   getPoint() const;
                ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

# endif