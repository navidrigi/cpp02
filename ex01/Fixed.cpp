#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	float	temp;

	temp = value * (1 << fractionalBits_);
	if (roundf(temp) < temp)
		temp = roundf(temp) + 1;
	else
		temp = roundf(temp);
	temp /= (1 << fractionalBits_);
	floatFixedValue_ = temp;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		floatFixedValue_ = other.toFloat();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	return floatFixedValue_;
}

void	Fixed::setRawBits( int const raw )
{
	floatFixedValue_ = raw;
}

float	Fixed::toFloat( void ) const
{
	return floatFixedValue_;
}

int		Fixed::toInt( void ) const
{
	return (roundf(floatFixedValue_));
}

std::ostream& operator<<(std::ostream& output, const Fixed &obj)
{
    output << obj.toFloat();
    return output;
}
