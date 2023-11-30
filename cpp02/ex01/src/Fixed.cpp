#include "Fixed.hpp"

#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>

namespace {
	static std::size_t	WORD_LEN = 4;

	float	edit_exponent(float f, int edit) {
		unsigned int		rawIEE754;
		unsigned int		exponent;

		std::memcpy(&rawIEE754, &f, WORD_LEN);

		exponent = (rawIEE754 >> 23) & 0xFF;
		exponent = (exponent + edit) << 23;
		rawIEE754 = (rawIEE754 & ~(0xFF << 23)) | exponent;
		
		std::memcpy(&f, &rawIEE754, WORD_LEN);
		return (f);
	}
}

// ==============================[ CONSTRUCTOR ]============================= //

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const int n) {
	this->_rawBits = n << Fixed::FRACTIONAL_BITS;
}

Fixed::Fixed(const float f) {
	this->_rawBits = edit_exponent(f, Fixed::FRACTIONAL_BITS);
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed(void) {}

// ===============================[ OPERATORS ]============================== //

Fixed&	Fixed::operator=(const Fixed& other) {
	this->_rawBits = other._rawBits;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed::operator	float(void) const {
	return (this->toFloat());
}

Fixed::operator	int(void) const {
	return (this->toInt());
}

// ===============================[ ACCESSORS ]============================== //

int		Fixed::getRawBits(void) const {
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int newRawBits) {
	this->_rawBits = newRawBits;
}

// ===============================[ FUNCTIONS ]============================== //

float	Fixed::toFloat(void) const {
	float	f;

	f = static_cast<float>(this->_rawBits);
	return (edit_exponent(f, -Fixed::FRACTIONAL_BITS));
}

int		Fixed::toInt(void) const {
	return (roundf(this->toFloat()));
}
