/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormatError.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:04:18 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 14:11:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATERROR_H
# define FORMATERROR_H

#include <stdexcept>

class FormatError : public std::runtime_error {
public:
	explicit FormatError(const std::string& msg);
};

#endif
