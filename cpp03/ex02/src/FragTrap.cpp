#include "FragTrap.hpp"
#include "libmini/color.hpp"

#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const unsigned int	FragTrap::BASE_HP = 100;
const unsigned int	FragTrap::BASE_EP = 100;
const unsigned int	FragTrap::BASE_AD = 30;

// ==============================[ CONSTRUCTOR ]============================== //

FragTrap::FragTrap(void) {}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	init(
		FragTrap::BASE_HP,
		FragTrap::BASE_EP,
		FragTrap::BASE_AD
	);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {}

void	FragTrap::init(
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
			  << " FragTrap "
			  << color::GREEN
			  << "construcor called"
			  << color::RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << color::DIM << color::RED
		      << '[' << this->getName() << ']'
			  << color::WHITE
			  << " FragTrap "
			  << color::RED
			  << "destructor called"
			  << color::RESET << std::endl;
}

// ===============================[ FUNCTIONS ]============================== //

void	FragTrap::attack(const std::string& target) {
	if (this->tryAct() == false)
		return;

	std::cout << color::RED
		      << "⚔️ " 
			  << color::WHITE
			  << " FragTrap "
			  << color::RED
			  << this->getName()
		      << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage"
			  << color::RESET << std::endl;
}

void	FragTrap::highFiveGuys(void) {
	if (this->tryAct() == false)
		return;

	std::cout << color::CYAN
		      << "🙌"
			  << color::WHITE
			  << " FragTrap "
			  << color::CYAN
			  << this->getName()
			  << " make a cool high five"
			  << color::RESET << std::endl;
}
