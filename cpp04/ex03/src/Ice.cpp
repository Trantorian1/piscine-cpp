#include "Ice.hpp"
#include "materia.hpp"

#include <iostream>

// ==============================[ CONSTRUCTOR ]============================= //

Ice::Ice(void) : AMateria(materia::ICE) {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice::~Ice(void) {}

// ===============================[ FUNCTIONS ]============================== //

Ice*	Ice::clone(void) const {
	return (new Ice());
}

void	Ice::use(const ICharacter& target) const {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		      << std::endl;
}
