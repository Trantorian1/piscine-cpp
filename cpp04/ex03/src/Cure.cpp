#include "Cure.hpp"
#include "materia.hpp"

#include <iostream>

// ==============================[ CONSTRUCTOR ]============================= //

Cure::Cure(void) : AMateria(materia::CURE) {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure::~Cure(void) {}

// ===============================[ FUNCTIONS ]============================== //

Cure*	Cure::clone(void) const {
	return (new Cure());
}

void	Cure::use(const ICharacter& target) const {
	std::cout << "* heals " << target.getName() << "'s wounds *"
		      << std::endl;
}
