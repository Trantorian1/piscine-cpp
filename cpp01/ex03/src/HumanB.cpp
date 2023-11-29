#include "HumanB.hpp"

#include "libmini/color.hpp"

#include <cstddef>
#include <iostream>

// ==============================[ CONTRUCTOR ]============================== //

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

HumanB::HumanB(const HumanB& other) {
	*this = other;
}

HumanB::~HumanB(void) {}

// ===============================[ OPERATORS ]============================== //

HumanB&	HumanB::operator=(const HumanB& other) {
	this->_name = other._name;
	this->_weapon = other._weapon;

	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const HumanB& humanB) {
	os << "[name:\"" << humanB.getName() << '"'
	   << ",weapon:" << humanB.getWeapon()
	   << ']';
	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const Weapon&		HumanB::getWeapon(void) const {
	return (*this->_weapon);
}

const std::string&	HumanB::getName(void) const {
	return (this->_name);
}

void				HumanB::setWeapon(Weapon& newWeapon) {
	this->_weapon = &newWeapon;
}

// ===============================[ FUNCTIONS ]============================== //

void	HumanB::attack(void) const {
	std::string	weaponType;

	if (this->_weapon == NULL)
		weaponType = "bare hands";
	else
		weaponType = this->_weapon->getType();

	std::cout << color::WHITE
		      << this->_name
			  << color::RED
			  << " attacks with their "
			  << color::DIM << color::WHITE
			  << weaponType
			  << color::RESET
			  << std::endl;
}
