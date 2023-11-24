/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:31:59 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 14:30:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

#include <string>

namespace constant {
	static const std::string ADD = "ADD";
	static const std::string SEARCH = "SEARCH";
	static const std::string EXIT = "EXIT";	

	namespace prompt {
		static const std::string FIRST_NAME = "first name: ";
		static const std::string LAST_NAME = "last name : ";
		static const std::string NICKNAME = "nickname  : ";
	   	static const std::string PHONE_NUMBER = "phone     : ";
	   	static const std::string DARKEST_SECRET = "secret    : ";
		static const std::string BASE_PROMPT = "phonebook: ";
	}

	namespace error {
		static const std::string INPUT = "invalid input";
		static const std::string EMPTY_PHONEBOOK = "phonebook is empty";
	}
}

#endif
