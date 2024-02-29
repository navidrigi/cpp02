#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
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
	private:
		static const int	fractionalBits_ = 8;
		// float				floatFixedValue_;
		int					value_;
};

std::ostream& operator<<(std::ostream& output, const Fixed &obj);