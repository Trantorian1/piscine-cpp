#include "Fixed.hpp"

// ==============================[ CONSTRUCTOR ]============================= //

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed(void) {}

// ===============================[ OPERATORS ]============================== //

Fixed&	Fixed::operator=(const Fixed& other) {
	this->_rawBits = other._rawBits;
	return (*this);
}

// ===============================[ ACCESSORS ]============================== //

int		Fixed::getRawBits(void) const {
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int newRawBits) {
	this->_rawBits = newRawBits;
}
