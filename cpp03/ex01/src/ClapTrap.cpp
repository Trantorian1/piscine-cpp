#include "ClapTrap.hpp"
#include "libmini/color.hpp"
#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const unsigned int	ClapTrap::BASE_HP = 10;
const unsigned int	ClapTrap::BASE_EP = 10;
const unsigned int	ClapTrap::BASE_AD = 0;

// ==============================[ CONSTRUCTOR ]============================== //

ClapTrap::ClapTrap(void) {}

ClapTrap::ClapTrap(const std::string& name) {
	init(
		name,
		ClapTrap::BASE_HP,
		ClapTrap::BASE_EP,
		ClapTrap::BASE_AD
	);
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	init(
		other._name,
		other._hitPoints,
		other._energyPoints,
		other._attackDamage
	);
}

void	ClapTrap::init(
	const std::string& name,
	unsigned int hitPoints,
	unsigned int energypoints,
	unsigned int attackDamage
) {
	this->_name = name;
	this->_hitPoints = hitPoints;
	this->_energyPoints = energypoints;
	this->_attackDamage = attackDamage;

	std::cout << color::DIM << color::GREEN
		      << '[' << this->_name << ']'
			  << " construcor called"
			  << color::RESET << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << color::DIM << color::RED
		      << '[' << this->_name << ']'
			  << " destructor called"
			  << color::RESET << std::endl;
}

// ===============================[ OPERATORS ]============================== //

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ClapTrap& clapTrap) {
	os << "{name:\"" << clapTrap.getName() << '"'
	   << ",hitPoints:" << clapTrap.getHitPoints()
	   << ",energyPoints:" << clapTrap.getEnergyPoints()
	   << ",attackDamage:" << clapTrap.getAttackDamage()
	   << '}';

	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const std::string&	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int		ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

unsigned int		ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

unsigned int		ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void				ClapTrap::setName(const std::string& newName) {
	if (newName.empty())
		return;
	this->_name = newName;
}

void				ClapTrap::setHitPoints(unsigned int newHitPoints) {
	this->_hitPoints = newHitPoints;
}

void				ClapTrap::setEnergyPoints(unsigned int newEnergyPoints) {
	this->_energyPoints = newEnergyPoints;
}

void				ClapTrap::setAttackDamage(unsigned int newAttackDamage) {
	this->_attackDamage = newAttackDamage;
}

// ===============================[ FUNCTIONS ]============================== //

void	ClapTrap::attack(const std::string& target) {
	if (this->tryAct() == false)
		return;

	std::cout << color::RED
		      << "⚔️  " << this->_name
		      << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage"
			  << color::RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= (amount > this->_hitPoints) ? this->_hitPoints : amount;
	std::cout << color::YELLOW
		      << "💥 " << this->_name
			  << " takes " << amount
			  << " points of damage"
			  << color::RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->tryAct() == false)
		return;

	this->_hitPoints += amount;
	std::cout << color::GREEN
		      << "🔧 " << this->_name
			  << " repairs for " << amount
			  << " hit point"
			  << color::RESET << std::endl;
}

bool	ClapTrap::tryAct(void) {
	bool	canAct;

	canAct = this->_hitPoints > 0 && this->_energyPoints > 0;
	if (canAct == true) {
		this->_energyPoints--;
	} else {
		std::cout << color::DIM << color::WHITE
			      << "🚧 " << this->_name 
			      << " cannot take actions"
				  << color::RESET << std::endl;
	}

	return (canAct);
}
