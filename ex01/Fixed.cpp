#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value_(0)
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
	int scaled = static_cast<int>(value * pow(2, fractional_));
	int integerPart = scaled >> fractional_;
	int floatPart = scaled & ((1 << fractional_) - 1);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	value_ = other.getRawBits();
}

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value_ = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value_;
}

void	Fixed::setRawBits( int const raw )
{
	value_ = raw;
}

float	Fixed::toFloat( void ) const;

int		Fixed::toInt( void ) const;
