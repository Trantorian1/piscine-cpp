#include "Brain.hpp"
#include "libmini/color.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>

// ==============================[ CONSTRUCTOR ]============================= //

Brain::Brain(void) : _size(0) {
	std::cout << color::DIM << color::WHITE
		      << "Brain"
			  << color::GREEN
			  << " constructor called"
			  << color::RESET << std::endl;
}

Brain::Brain(const Brain& other) {
	*this = other;

	std::cout << color::DIM << color::WHITE
		      << "Brain"
			  << color::GREEN
			  << " copy constructor called"
			  << color::RESET << std::endl;
}

Brain::~Brain(void) {
	std::cout << color::DIM << color::WHITE
		      << "Brain"
			  << color::RED
			  << " destructor called"
			  << color::RESET << std::endl;
}

// ===============================[ OPERATORS ]============================== //

Brain&			Brain::operator=(const Brain& other) {
	for (std::size_t index = 0; index < other._size; index++) {
		this->_ideas[index] = other._ideas[index];
	}
	this->_size = other._size;

	return (*this);
}

const std::string&	Brain::operator[](std::size_t index) const {
	if (index >= this->_size)
		throw (std::invalid_argument("index out of range"));

	return (this->_ideas[index]);
}

std::ostream&	operator<<(std::ostream& os, const Brain& brain) {
	if (brain.isEmpty() == true)
		return (os << "{ideas=[]}");

	os << "{ideas=[";
	for (std::size_t index = 0; index < brain.getSize() - 1; index++)
		os << '"' << brain[index] << "\",";
	if (brain.isEmpty() == false)
		os << '"' << brain[brain.getSize() - 1] << "\"]}";

	return (os);
}

// ===============================[ ACCESSORS ]============================== //

std::size_t	Brain::getSize(void) const {
	return (this->_size);
}

// ===============================[ FUNCTIONS ]============================== //

void	Brain::addIdea(const std::string& newIdea) {
	if (this->_size >= Brain::CAPACITY)
		throw (std::invalid_argument("no space left"));

	this->_ideas[this->_size++] = newIdea;
}

bool	Brain::isEmpty(void) const {
	return (this->_size == 0);
}

bool	Brain::hasSpaceLeft(void) const {
	return (this->_size < Brain::CAPACITY);
}
