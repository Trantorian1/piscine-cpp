#include "Animal.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ==============================[ CONSTRUCTOR ]============================= //

Animal::Animal(const std::string& type) : _type(type) {
	std::cout << color::DIM  << color::WHITE
		      << "Animal "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << color::DIM  << color::WHITE
		      << "Animal "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

Animal::~Animal(void) {
	std::cout << color::DIM << color::WHITE
		      << "Animal "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

// ===============================[ OPERATORS ]============================== //

std::ostream&	operator<<(std::ostream& os, const Animal& animal) {
	os << "{type:\"" << animal.getType()  << "\"}";
	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const std::string&	Animal::getType(void) const {
	return (this->_type);
}

// ===============================[ FUNCTIONS ]============================== //

void	Animal::makeSound(void) const {
	std::cout << "REEEEE" << std::endl;
}
