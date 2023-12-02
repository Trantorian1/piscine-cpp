#include "WrongCat.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const std::string	WrongCat::TYPE = "WrongCat";

// ==============================[ CONSTRUCTOR ]============================= //

WrongCat::WrongCat(void) : WrongAnimal(WrongCat::TYPE) {
	std::cout << color::DIM << color::WHITE
		      << "WrongCat "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << color::DIM << color::WHITE
		      << "WrongCat "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << color::DIM << color::WHITE
		      << "WrongCat "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

// ===============================[ FUNCTIONS ]============================== //

void	WrongCat::makeSound(void) const {
	std::cout << "*meow*" << std::endl;
}
