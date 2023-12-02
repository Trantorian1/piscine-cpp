#include "Brain.hpp"
#include <stdexcept>

// ==============================[ CONSTRUCTOR ]============================= //

Brain::Brain(void) : _size(0) {}

Brain::Brain(const Brain& other) {
	*this = other;
}

Brain::~Brain(void) {}

// ===============================[ OPERATORS ]============================== //

Brain&			Brain::operator=(const Brain& other) {
	for (std::size_t index = 0; index < other._size; index++) {
		this->_ideas[index] = other._ideas[index];
	}
	this->_size = other._size;

	return (*this);
}

std::string&	Brain::operator[](std::size_t index) {
	if (index >= this->_size)
		throw (std::invalid_argument("index out of range"));

	return (this->_ideas[index]);
}

// ===============================[ ACCESSORS ]============================== //

std::size_t	Brain::getSize(void) const {
	return (this->_size);
}

// ===============================[ FUNCTIONS ]============================== //

void	Brain::addIdea(const std::string& newIdea) {
	if (this->_size >= Brain::IDEA_CAP)
		throw (std::invalid_argument("no space left"));

	this->_ideas[this->_size++] = newIdea;
}
