#include "Point.hpp"

float	Point::calculateArea( Point const a, Point const b, Point const c )
{
	float	d1;
	float	d2;
	float	d3;

	d1 = a.x_.getRawBits() * (b.y_.getRawBits() - c.y_.getRawBits());
	d2 = b.x_.getRawBits() * (c.y_.getRawBits() - a.y_.getRawBits());
	d3 = c.x_.getRawBits() * (a.y_.getRawBits() - b.y_.getRawBits());
	if (d1 + d2 + d3 < 0)
		return -(d1 + d2 + d3) / 2.0;
	return (d1 + d2 + d3) / 2.0;
}

bool	Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	totalArea = calculateArea(a,b,c);
	float	pointArea = calculateArea(a,b,point) + calculateArea(a,c,point) + calculateArea(b,c,point);
	float	tolerance = 1e-6;

	if (std::abs(totalArea - pointArea) < tolerance)
		return true;
	return false;
}
// does not work