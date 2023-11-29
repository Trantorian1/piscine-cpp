#include "Weapon.hpp"

// ==============================[ CONTRUCTOR ]============================== //

Weapon::Weapon(void) : _type("none") {}

Weapon::Weapon(const std::string& type): _type(type) {}

Weapon::Weapon(const Weapon& other) {
	*this = other;
}

Weapon::~Weapon(void) {}

// ===============================[ ACCESSORS ]============================== //

const std::string&	Weapon::getType(void) const {
	return (this->_type);
}

void		Weapon::setType(const std::string& newType) {
	this->_type = newType;
}

// ===============================[ OPERATORS ]============================== //

Weapon&	Weapon::operator=(const Weapon& other) {
	this->_type = other._type;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Weapon& weapon) {
	os << "[type:" << weapon.getType() << ']';
	return (os);
}
