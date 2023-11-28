#include "Zombie.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ==============================[ CONSTRUCTOR ]============================= //

Zombie::Zombie(void) : _name("") {
	std::cout << color::GREEN << color::DIM
			  << '[' << this->_name << ']'
			  << " was created" 
			  << color::RESET << std::endl;
}

Zombie::Zombie(const std::string& name) : _name(name) {
	std::cout << color::GREEN << color::DIM
			  << '[' << this->_name << ']'
			  << " was created"
			  << color::RESET << std::endl;
}

Zombie::Zombie(Zombie& other) {
	this->_name = other._name;

	std::cout << color::YELLOW << color::DIM
			  << '[' << this->_name << ']'
			  << " was copied"
			  << color::RESET << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << color::RED << color::DIM
			  << '[' << this->_name << ']'
			  << " spent too long sun-tanning"
			  << color::RESET << std::endl;
}

// ===============================[ OPERATORS ]============================== //

Zombie&	Zombie::operator=(Zombie& other) {
	this->_name = other._name;
	return (*this);
}

// ===============================[ ACCESSORS ]============================== //

std::string	Zombie::getName(void) const {
	return (this->_name);
}

void		Zombie::setName(const std::string& name) {
	this->_name = name;
}

// ===============================[ FUNCTIONS ]============================== //

void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
