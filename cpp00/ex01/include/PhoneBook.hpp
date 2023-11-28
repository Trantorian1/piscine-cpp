/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:32:18 by marvin            #+#    #+#             */
/*   Updated: 2023/11/28 15:14:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <cstddef>
# include <ostream>
#include <string>
# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	PhoneBook(const PhoneBook& other);
	~PhoneBook();
	PhoneBook&	operator=(const PhoneBook& other);

	const Contact&	operator[](std::size_t index) const;

	void			addContact(Contact& newContact);
	bool			isempty(void) const;
	unsigned short	getSize(void) const;

	static const short 	CAPACITY = 8;

private:
	Contact			_contacts[PhoneBook::CAPACITY];
	unsigned short	_size;
	unsigned short	_oldestContact;
};

std::ostream&	operator<<(std::ostream& os, const PhoneBook& phoneBook);

#endif
