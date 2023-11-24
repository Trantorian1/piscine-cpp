/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:36:48 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 15:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>

#include "FormatError.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "constants.hpp"

namespace {
# ifdef DEBUG
	void	tester(void) {
		PhoneBook	pb;

		Contact		trantorian(
			"0683421345",
			"Magnifico",
			"Grandissimo",
			"The Mule",
			"Is a mutant"
		);

		Contact hariSeldon(
			"0123456789",
			"Hari", 
			"Seldon",
			"Psychohistorian",
			"Founder of Psychohistory"
		);

		Contact salvorHardin(
			"0234567891",
			"Salvor",
			"Hardin",
			"Mayor",
			"First Mayor of Terminus"
		);

		Contact hoberMallow(
			"0345678912",
			"Hober",
			"Mallow",
			"Trader",
			"First of the Merchant Princes"
		);

		Contact gaalDornick(
			"0456789123",
			"Gaal",
			"Dornick",
			"Mathematician",
			"Psychohistory Researcher"
		);

		Contact eblingMis(
			"0567891234",
			"Ebling",
			"Mis",
			"Historian",
			"Last great Scientist of the Foundation"
		);

		Contact baytaDarell(
			"0678912345",
			"Bayta",
			"Darell",
			"Heroine",
			"Stopped the Mule"
		);

		Contact toranDarell(
			"0789123456",
			"Toran",
			"Darell",
			"Soldier",
			"Fought against the Mule"
		);

		Contact arcadiaDarell(
			"0891234567",
			"Arcadia",
			"Darell",
			"Politician",
			"Key figure in Second Foundation"
		);

		Contact preemPalver(
			"0912345678",
			"Preem",
			"Palver",
			"First Speaker",
			"Leader of the Second Foundation"
		);

		pb.addContact(trantorian);
		pb.addContact(hariSeldon);
		pb.addContact(salvorHardin);
		pb.addContact(hoberMallow);
		pb.addContact(gaalDornick);
		pb.addContact(eblingMis);
		pb.addContact(baytaDarell);
		pb.addContact(toranDarell);
		pb.addContact(arcadiaDarell);
		pb.addContact(preemPalver);

		std::cout << pb << std::endl;
	}
#endif

	bool	validateNonEmpty(std::string string) {
		for (std::size_t index = 0; index < string.size(); index++) {
			if (std::isspace(string[index]) == false)
				return (true);
		}
		return (false);
	}

	bool	validatePhone(std::string phoneNumber) {
		if (validateNonEmpty(phoneNumber) == false)
			return (false);

		for (std::size_t index = 0; index < phoneNumber.size(); index++) {
			if (std::isdigit(phoneNumber[index]) == false)
				return (false);
		}
		return (true);
	}

	std::string	collect(std::string field, bool (*validator)(std::string)) {
		std::string	userInput;

		std::cout << field;
		std::getline(std::cin, userInput);

		if (validator(userInput) == false)
			throw (FormatError(field));
		else
			return (userInput);
	}

	void	handleUserAdd(PhoneBook& pb) {
		std::string firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;
		Contact		contact;

		try {
			firstName = collect(constant::prompt::FIRST_NAME, validateNonEmpty);
			lastName = collect(constant::prompt::LAST_NAME, validateNonEmpty);
			nickName = collect(constant::prompt::NICKNAME, validateNonEmpty);
			phoneNumber = collect(constant::prompt::PHONE_NUMBER, validatePhone);
			secret = collect(constant::prompt::DARKEST_SECRET, validateNonEmpty);

			contact = Contact(
				firstName,
				lastName,
				nickName,
				phoneNumber,
				secret
			);

			pb.addContact(contact);
		} catch (FormatError& e) {
			std::cout << constant::error::INPUT << std::endl;
		}
	}

	void	handleUserSearch(PhoneBook& pb) {
		unsigned short	index;
		
		if (pb.isempty())
		{
			std::cout << constant::error::EMPTY_PHONEBOOK << std::endl;
			return;
		}

		std::cout << pb << '\n'
				  << "index: ";
		std::cin >> index;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		} else if(index >= PhoneBook::CAPACITY) {
			std::cout << constant::error::INPUT << std::endl;
		}

		std::cout << pb[index] << std::endl;
	}
}

int	main(void) {
	PhoneBook	pb;
	std::string	userInput;

	Contact		trantorian(
		"0683421345",
		"Magnifico",
		"Grandissimo",
		"The Mule",
		"Is a mutant"
	);
	pb.addContact(trantorian);

	while (true) {
		std::cout << constant::prompt::BASE_PROMPT;
		std::getline(std::cin, userInput);

		if (std::cin.eof())
			return (EXIT_FAILURE);
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (userInput == constant::ADD) {
			handleUserAdd(pb);
		} else if (userInput == constant::SEARCH) {
			handleUserSearch(pb);
		} else if (userInput == constant::EXIT) {
			break ;
		} 	
	}

	return (EXIT_SUCCESS);
}
