#include "AMateria.hpp"

// ==============================[ CONSTRUCTOR ]============================= //

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria::~AMateria(void) {}

// ===============================[ OPERATORS ]============================== //

std::ostream&	operator<<(std::ostream& os, const AMateria& materia) {
	os << "{type=\"" << materia.getType() << "\"}";
	return (os);
}

// ===============================[ ACCESSORS ]============================== //

const std::string&	AMateria::getType(void) const {
	return (this->_type);
}
