#include "Cat.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const std::string	Cat::TYPE = "Cat";

// ==============================[ CONSTRUCTOR ]============================= //

Cat::Cat(void) : Animal(Cat::TYPE) {
	std::cout << color::DIM << color::WHITE
		      << "Cat "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << color::DIM << color::WHITE
		      << "Cat "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

Cat::~Cat(void) {
	std::cout << color::DIM << color::WHITE
		      << "Cat "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

// ===============================[ FUNCTIONS ]============================== //

void	Cat::makeSound(void) const {
	std::cout << "*meow*" << std::endl;
}
