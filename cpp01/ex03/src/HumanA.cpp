#include "HumanA.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ==============================[ CONTRUCTOR ]============================== //

HumanA::HumanA(const std::string& name, Weapon& weapon) :
	_name(name),
	_weapon(weapon) 
{}

HumanA::HumanA(const HumanA& other) :
	_name(other._name),
	_weapon(other._weapon)
{}

HumanA::~HumanA(void) {}

// ===============================[ OPERATORS ]============================== //

HumanA&		HumanA::operator=(const HumanA& other) {
	this->_name = other._name;
	this->_weapon = other._weapon;

	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const HumanA& humanA) {
	os << "[name:\"" << humanA.getName() << '"'
	   << ",weapon:" << humanA.getWeapon()
	   << ']';
	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const Weapon&		HumanA::getWeapon(void) const {
	return (this->_weapon);
}

const std::string&	HumanA::getName(void) const {
	return (this->_name);
}

void				HumanA::setWeapon(Weapon& newWeapon) {
	this->_weapon = newWeapon;
}

// ===============================[ FUNCTIONS ]============================== //

void	HumanA::attack(void) const {
	std::cout << color::WHITE
		      << this->_name
			  << color::RED
			  << " attacks with their "
			  << color::DIM << color::WHITE
			  << this->_weapon.getType()
			  << color::RESET
			  << std::endl;
}
