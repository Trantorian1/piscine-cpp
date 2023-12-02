#include "WrongAnimal.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ==============================[ CONSTRUCTOR ]============================= //

WrongAnimal::WrongAnimal(void) {
	std::cout << color::DIM  << color::WHITE
		      << "WrongAnimal "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
	std::cout << color::DIM  << color::WHITE
		      << "WrongAnimal "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << color::DIM << color::WHITE
		      << "WrongAnimal "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void) {}

// ===============================[ OPERATORS ]============================== //

WrongAnimal	WrongAnimal::operator=(const WrongAnimal& other) const {
	return (WrongAnimal(other._type));
}

std::ostream&	operator<<(std::ostream& os, const WrongAnimal& animal) {
	os << "{type:\"" << animal.getType()  << "\"}";
	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const std::string&	WrongAnimal::getType(void) const {
	return (this->_type);
}

// ===============================[ FUNCTIONS ]============================== //

void	WrongAnimal::makeSound(void) const {
	std::cout << "REEEEE" << std::endl;
}
