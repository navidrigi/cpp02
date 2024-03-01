#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;
	Point const a(0,0);
	Point const b(0,4);
	Point const c(4,0);
	Point const p(1,10);
	std::cout << Point::bsp(a,b,c,p) << std::endl;

	return 0;
}
