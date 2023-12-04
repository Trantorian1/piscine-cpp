#include "MateriaSource.hpp"
#include "materia.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "libmini/array.hpp"

#include <cstddef>

// ==============================[ CONSTRUCTOR ]============================= //

MateriaSource::MateriaSource(void) : _size(0) {}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (unsigned char index = 0; index < other._size; index++) {
		this->_learned[index] = other._learned[index];
	}
	this->_size = other._size;
}

MateriaSource::~MateriaSource(void) {}

// ===============================[ ACCESSORS ]============================== //

unsigned char	MateriaSource::getSize(void) const {
	return (this->_size);
}

// ===============================[ FUNCTIONS ]============================== //

void		MateriaSource::learnMateria(const AMateria* materia) {
	if (hasSpaceLeft() == false || materia == NULL)
		return;
	this->_learned[this->_size++] = materia->getType();
}

AMateria*	MateriaSource::createMateria(const std::string type) const {
	static const std::string	g_types[] = {
		materia::ICE,
		materia::CURE
	};
	unsigned char	index;
	
	for (index = 0; index < this->_size; index++) {
		if (type == g_types[index])
			break;
	}

	switch (index) {
		case 0:
			return (new Ice());
		case 1:
			return (new Cure());
		default:
			return (NULL);
	}
}

bool		MateriaSource::hasSpaceLeft(void) const {
	return (this->_size < MateriaSource::CAPACITY);
}

bool		MateriaSource::knows(const AMateria* materia) const {
	std::string	type;

	if (materia == NULL)
		return (false);

	type = materia->getType();
	for (unsigned char index = 0; index < this->_size; index++) {
		if (type == this->_learned[index])
			return (true);
	}
	return (false);
}
