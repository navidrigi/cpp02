#pragma once

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &other);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
	private:
		int					value_;
		static const int	fractional_ = 8;
};
