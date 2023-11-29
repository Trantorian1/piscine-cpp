#include "Fixed.hpp"

#include <iostream>
#include <cstdlib>

int main(void) {
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;
	a.setRawBits(12);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (EXIT_SUCCESS);
}
