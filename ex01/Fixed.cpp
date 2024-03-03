#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value * (1 << fractionalBits_))
{
	std::cout << "Int constructor called" << std::endl;
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
	setRawBits(temp);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
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
	return value_;
}

void	Fixed::setRawBits( int const raw )
{
	value_ = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(value_) / (1 << fractionalBits_));
}

int		Fixed::toInt( void ) const
{
	return (value_ / (1 << fractionalBits_));
}

std::ostream& operator<<(std::ostream& output, const Fixed &obj)
{
    output << obj.toFloat();
    return output;
}
