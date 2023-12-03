#include "Dog.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const std::string	Dog::TYPE = "Dog";

// ==============================[ CONSTRUCTOR ]============================= //

Dog::Dog(void) : AAnimal(Dog::TYPE), _brain(new Brain()) {
	std::cout << color::DIM << color::WHITE
		      << "Dog "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << color::DIM << color::WHITE
		      << "Dog "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

Dog::~Dog(void) {
	delete (this->_brain);
	std::cout << color::DIM << color::WHITE
		      << "Dog "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

// ===============================[ ACCESSORS ]============================== //

const Brain&	Dog::getBrain(void) const {
	return (*this->_brain);
}

// ===============================[ FUNCTIONS ]============================== //

void	Dog::makeSound(void) const {
	std::cout << "*bark*" << std::endl;
}
