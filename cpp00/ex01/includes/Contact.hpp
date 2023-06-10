/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:01 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 14:18:50 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "validation.h"
# include "colors.h"

class Contact {
	private:
		std::string	_first_name,
					_last_name,
					_nick_name,
					_phone_number,
					_secret;
	public:
		Contact();
		~Contact();
		void	setFirstName(std::string new_name);
		void	setPhoneNumber(std::string new_number);
		void	setLastName(std::string last_name);
		void	setNickName(std::string nick_name);
		void	setSecret(std::string secret);
		std::string	getFirstName();
		std::string	getPhoneNumber();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getSecret();
		std::string	removeSpaces(std::string text);
};

#endif