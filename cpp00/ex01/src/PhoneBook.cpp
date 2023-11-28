/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:14:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/28 15:15:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

// ================================[ HELPER ]================================ //

namespace {
	std::string	truncate(std::string str) {
		std::ostringstream	stream;

		if (str.size() > 10)
			stream << str.substr(0, 9) << '.';
		else
			stream << str;
		return (stream.str());
	}

	std::string	buildContactLine(
		const PhoneBook& phoneBook,
		std::size_t index
	) {
		std::ostringstream	stream;
		Contact 			contact = phoneBook[index];

		stream << '|' << std::right << std::setw(10) << index << '|'
			   << std::right << std::setw(10) 
			   << truncate(contact.getFirstName()) << '|'
			   << std::right << std::setw(10) 
			   << truncate(contact.getLastName()) << '|'
			   << std::right << std::setw(10)
			   << truncate(contact.getNickName()) << '|';

		return (stream.str());
	}
}

// ==============================[ CONSTRUCTOR ]============================= //

PhoneBook::PhoneBook() : _size(0), _oldestContact(0) {}

PhoneBook::PhoneBook(const PhoneBook& other) {
	*this = other;
}

PhoneBook::~PhoneBook() {}

// ===============================[ OPERATORS ]============================== //

PhoneBook&		PhoneBook::operator=(const PhoneBook& other) {
	_size = other._size;
	_oldestContact = other._oldestContact;

	for (unsigned short index = 0; index < PhoneBook::CAPACITY; index++) {
		_contacts[index] = other._contacts[index];
	}

	return (*this);
}

const Contact&	PhoneBook::operator[](std::size_t index) const {
	if (index >= PhoneBook::CAPACITY)
		throw (std::invalid_argument("index"));

	return (_contacts[index]);
}

std::ostream&	operator<<(std::ostream& os, const PhoneBook& phoneBook) {
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n";

	for (unsigned short index = 0; index < PhoneBook::CAPACITY - 1; index++)
		std::cout << buildContactLine(phoneBook, index) << '\n';
	std::cout << buildContactLine(phoneBook, PhoneBook::CAPACITY - 1);

	return (os);
}

// ===============================[ FUNCTIONS ]============================== //

void	PhoneBook::addContact(Contact& newContact) {
	if (_size == PhoneBook::CAPACITY) {
		_size %= PhoneBook::CAPACITY;

		_contacts[_oldestContact] = newContact;

		_oldestContact++;
		_oldestContact %= PhoneBook::CAPACITY;
	} else {
		_contacts[_size] = newContact;
	}

	_size++;
}

bool	PhoneBook::isempty(void) const {
	return (_size == 0);
}

unsigned short	PhoneBook::getSize(void) const {
	return (_size);
}
