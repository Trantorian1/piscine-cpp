#include "Cat.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const std::string	Cat::TYPE = "Cat";

// ==============================[ CONSTRUCTOR ]============================= //

Cat::Cat(void) : AAnimal(Cat::TYPE), _brain(new Brain()) {
	std::cout << color::DIM << color::WHITE
		      << "Cat "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << color::DIM << color::WHITE
		      << "Cat "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

Cat::~Cat(void) {
	delete (this->_brain);
	std::cout << color::DIM << color::WHITE
		      << "Cat "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

// ===============================[ ACCESSORS ]============================== //

const Brain&	Cat::getBrain(void) const {
	return (*this->_brain);
}

// ===============================[ FUNCTIONS ]============================== //

void	Cat::makeSound(void) const {
	std::cout << "*meow*" << std::endl;
}
