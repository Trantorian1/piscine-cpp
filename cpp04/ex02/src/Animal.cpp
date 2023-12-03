#include "Animal.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ==============================[ CONSTRUCTOR ]============================= //

AAnimal::AAnimal(void) {
	std::cout << color::DIM  << color::WHITE
		      << "Animal "
		      << color::GREEN
		      << "[" << std::hex << this << "] was created"
			  << color::RESET << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type) {
	std::cout << color::DIM  << color::WHITE
		      << "Animal "
		      << color::GREEN
		      << "[" << std::hex << this << "] was copied"
			  << color::RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << color::DIM << color::WHITE
		      << "Animal "
		      << color::RED
		      << "[" << std::hex << this << "] was destroyed"
			  << color::RESET << std::endl;
}

AAnimal::~AAnimal(void) {}

// ===============================[ OPERATORS ]============================== //

std::ostream&	operator<<(std::ostream& os, const AAnimal& animal) {
	os << "{type:\"" << animal.getType()  << "\"}";
	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const std::string&	AAnimal::getType(void) const {
	return (this->_type);
}
