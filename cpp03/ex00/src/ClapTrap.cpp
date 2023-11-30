#include "ClapTrap.hpp"
#include "libmini/color.hpp"
#include <iostream>

// ===============================[ CONSTANTS ]============================== //

const std::string	ClapTrap::BASE_NAME = "defaultClapTrap";
const unsigned int	ClapTrap::BASE_HP = 10;
const unsigned int	ClapTrap::BASE_EP = 10;
const unsigned int	ClapTrap::BASE_AD = 0;

// ==============================[ CONSTRUCTOR ]============================== //

ClapTrap::ClapTrap(void) :
	_name(ClapTrap::BASE_NAME),
	_hitPoints(ClapTrap::BASE_HP),
	_energyPoints(ClapTrap::BASE_EP),
	_attackDamage(ClapTrap::BASE_AD)
{}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
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
	if (this->canAct() == false)
		return;

	this->_energyPoints--;
	std::cout << color::RED
		      << "Claptrap " << this->_name
		      << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= (amount > this->_hitPoints) ? this->_hitPoints : amount;
	std::cout << color::YELLOW
		      << "Claptrap " << this->_name
			  << " takes " << amount
			  << " points of damage";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->canAct() == false)
		return;

	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << color::GREEN
		      << "Claptrap " << this->_name
			  << " heals for " << amount
			  << " hit point";
}

bool	ClapTrap::canAct(void) const {
	return (this->_hitPoints > 0 && this->_energyPoints > 0);
}
