#include "Character.hpp"
#include "libmini/array.hpp"
#include <cstddef>
#include <iostream>

// ==============================[ CONSTRUCTOR ]============================= //

Character::Character(const std::string& name) : _name(name), _size(0) {}

Character::Character(const Character& other) : _name(other._name) {
	for (unsigned char index = 0; index < other._size; index++) {
		this->_inventory[index] = other._inventory[index]->clone();
	}

	this->_size = other._size;
}

Character::~Character(void) {
	for (unsigned char index = 0; index < this->_size; index++) {
		delete (this->_inventory[index]);
	}
}

// ===============================[ OPERATORS ]============================== //

std::ostream&	operator<<(std::ostream& os, const Character& character) {
	os << "{name=\"" << character.getName() << "\"}" ;
	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const std::string&	Character::getName(void) const {
	return (this->_name);
}

unsigned char		Character::getSize(void) const {
	return (this->_size);
}

// ===============================[ FUNCTIONS ]============================== //

void	Character::equip(const AMateria *materia) {
	if (hasSpaceLeft() == false || materia == NULL)
		return;

	for (unsigned char index = 0; index < this->_size; index++) {
		if (this->_inventory[index] == materia)
			return;
	}

	this->_inventory[this->_size++] = materia;
}

void	Character::unequip(int index) {
	if (index < 0 || index >= this->_size)
		return;

	for (; index < this->_size - 1; index++) {
		this->_inventory[index] = this->_inventory[index + 1];
	}
	this->_size--;
}

void	Character::use(int index, const ICharacter& target) const {
	if (index < 0 || index >= this->_size)
		return;

	this->_inventory[index]->use(target);
}

bool	Character::hasSpaceLeft(void) const {
	return (this->_size < Character::CAPACITY);
}
