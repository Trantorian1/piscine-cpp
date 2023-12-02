#include "Dog.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const std::string	Dog::TYPE = "Dog";

// ==============================[ CONSTRUCTOR ]============================= //

Dog::Dog(void) : Animal(Dog::TYPE) {
	std::cout << color::DIM << color::WHITE
		      << "Dog "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << color::DIM << color::WHITE
		      << "Dog "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

Dog::~Dog(void) {
	std::cout << color::DIM << color::WHITE
		      << "Dog "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

// ===============================[ FUNCTIONS ]============================== //

void	Dog::makeSound(void) const {
	std::cout << "*bark*" << std::endl;
}
