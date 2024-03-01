#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x_;
		const Fixed y_;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();
		static bool		bsp( Point const a, Point const b, Point const c, Point const point);
		static float	calculateArea( Point const a, Point const b, Point const c );
};
