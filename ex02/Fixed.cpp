#include "Fixed.hpp"

Fixed::Fixed() : value_(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value * (1 << fractionalBits_))
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
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
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value_ = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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
	return (float)value_ / (1 << fractionalBits_);
}

int		Fixed::toInt( void ) const
{
	return value_ / (1 << fractionalBits_);
}

std::ostream& operator<<(std::ostream& output, const Fixed &obj)
{
    output << obj.toFloat();
    return output;
}

bool	Fixed::operator>(const Fixed &other)
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other)
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->getRawBits() != other.getRawBits());
}

float	Fixed::operator+(const Fixed &other)
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed &other)
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed &other)
{
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed &other)
{
	return (this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++() // ++a
{
	(this->value_)++;
	this->toFloat();
	return *this;
}

Fixed	Fixed::operator++(int) // a++
{
	Fixed old = *this;
	operator++();
	return old;
}

Fixed	&Fixed::operator--() // --a
{
	(this->value_)--;
	this->toFloat();
	return *this;
}

Fixed	Fixed::operator--(int) // a--
{
	Fixed old = *this;
	operator--();
	return old;
}

Fixed	Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return ((obj1 < obj2 ? obj1 : obj2));
}

float	Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return ((obj1.toFloat() < obj2.toFloat() ? obj1.toFloat() : obj2.toFloat()));
}

Fixed	Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return ((obj1 > obj2 ? obj1 : obj2));
}

float	Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return ((obj1.toFloat() > obj2.toFloat() ? obj1.toFloat() : obj2.toFloat()));
}
