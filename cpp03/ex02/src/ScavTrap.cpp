#include "ScavTrap.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const unsigned int	ScavTrap::BASE_HP = 100;
const unsigned int	ScavTrap::BASE_EP = 50;
const unsigned int	ScavTrap::BASE_AD = 20;

// ==============================[ CONSTRUCTOR ]============================== //

ScavTrap::ScavTrap(void) {}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	init(
		ScavTrap::BASE_HP,
		ScavTrap::BASE_EP,
		ScavTrap::BASE_AD
	);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}

void	ScavTrap::init(
	unsigned int hitPoints,
	unsigned int energyPoints,
	unsigned int attackDamage
) {	
	this->_hitPoints = hitPoints;
	this->_energyPoints = energyPoints;
	this->_attackDamage = attackDamage;

	std::cout << color::DIM << color::GREEN
		      << '[' << this->getName() << ']'
			  << color::WHITE
			  << " ScavTrap "
			  << color::GREEN
			  << "construcor called"
			  << color::RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << color::DIM << color::RED
		      << '[' << this->getName() << ']'
			  << color::WHITE
			  << " ScavTrap "
			  << color::RED
			  << "destructor called"
			  << color::RESET << std::endl;
}

// ===============================[ FUNCTIONS ]============================== //

void	ScavTrap::attack(const std::string& target) {
	if (this->tryAct() == false)
		return;

	std::cout << color::RED
		      << "⚔️ " 
			  << color::WHITE
			  << " ScavTrap "
			  << color::RED
			  << this->getName()
		      << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage"
			  << color::RESET << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (this->tryAct() == false)
		return;

	std::cout << color::MAGENTA
		      << "🥅"
			  << color::WHITE
			  << " ScavTrap "
			  << color::MAGENTA
			  << this->getName()
			  << " is guarding the gate"
			  << color::RESET << std::endl;
}
