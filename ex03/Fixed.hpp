#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value_;
		static const int	fractionalBits_ = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator>(const Fixed &other);
		bool	operator<(const Fixed &other);
		bool	operator>=(const Fixed &other);
		bool	operator<=(const Fixed &other);
		bool	operator==(const Fixed &other);
		bool	operator!=(const Fixed &other);
		float	operator+(const Fixed &other);
		float	operator-(const Fixed &other);
		float	operator*(const Fixed &other);
		float	operator/(const Fixed &other);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		static Fixed	min(Fixed &obj1, Fixed &obj2);
		static float	min(const Fixed &obj1, const Fixed &obj2);
		static Fixed	max(Fixed &obj1, Fixed &obj2);
		static float	max(const Fixed &obj1, const Fixed &obj2);
};

std::ostream& operator<<(std::ostream& output, const Fixed &obj);
