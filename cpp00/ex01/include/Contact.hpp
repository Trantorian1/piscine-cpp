/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:33:26 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 13:39:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

class Contact {
public:
	Contact();
	Contact(
		std::string firstName,
		std::string lastName,
		std::string nickName,
		std::string	phoneNumber,
		std::string darkestSecret
	);
	Contact(const Contact& other);
	~Contact();
	Contact&	operator=(const Contact& other);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
	
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

std::ostream&	operator<<(std::ostream& os, const Contact& contact);

#endif
