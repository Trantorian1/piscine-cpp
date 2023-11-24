/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:43:34 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 14:09:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "constants.hpp"
#include <iomanip>
#include <ios>
#include <ostream>

// ==============================[ CONSTRUCTOR ]============================= //

Contact::Contact() {
	Contact("", "", "", "", "");
}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string darkestSecret
) : _firstName(firstName),
	_lastName(lastName),
	_nickName(nickName),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{}

Contact::Contact(const Contact& other) {
	*this = other;
}

Contact::~Contact() {}

// ===============================[ OPERATORS ]============================== //

Contact&	Contact::operator=(const Contact& other) {
	_firstName = other._firstName;
	_lastName = other._lastName;
	_nickName = other._nickName;
	_phoneNumber = other._phoneNumber;
	_darkestSecret = other._darkestSecret;

	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Contact& contact) {
	os << constant::prompt::FIRST_NAME     << contact.getFirstName() << '\n'
	   << constant::prompt::LAST_NAME      << contact.getLastName() << '\n'
	   << constant::prompt::NICKNAME       << contact.getNickName() << '\n'
	   << constant::prompt::PHONE_NUMBER   << contact.getPhoneNumber() << '\n'
	   << constant::prompt::DARKEST_SECRET << contact.getDarkestSecret();

	return (os);
}

// ================================[ GETTERS ]=============================== //

std::string	Contact::getPhoneNumber(void) const {
	return (_phoneNumber);
}

std::string	Contact::getFirstName(void) const {
	return (_firstName);
}

std::string	Contact::getLastName(void) const {
	return (_lastName);
}

std::string Contact::getNickName(void) const {
	return (_nickName);
}

std::string	Contact::getDarkestSecret(void) const {
	return (_darkestSecret);
}
