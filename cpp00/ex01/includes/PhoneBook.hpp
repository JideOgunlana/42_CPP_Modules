/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:13 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 14:19:45 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"


# define MAX_CONTACTS 8


class PhoneBook {
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_oldest_index;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(Contact new_contact);
		void	printContacts();
		void	printContactInfo(std::string contact_index);
		int		totalContacts();
		std::string	truncateString(std::string text);
		std::string	removeSpaces(std::string text);
};

#endif