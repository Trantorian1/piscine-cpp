#include "Fixed.hpp"

#include <iostream>
#include <cstdlib>

int main(void) {
	Fixed	a(12);
	Fixed	b(1.3f);
	Fixed	c(1.7f);
	Fixed	d(-1.7f);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << b.toInt() << std::endl;
	std::cout << static_cast<int>(b) << std::endl;
	std::cout << static_cast<float>(b) << std::endl;
	std::cout << c << std::endl;
	std::cout << c.toInt() << std::endl;
	std::cout << static_cast<int>(c) << std::endl;
	std::cout << static_cast<float>(c) << std::endl;
	std::cout << d << std::endl;

	return (EXIT_SUCCESS);
}
