/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:20:45 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 14:20:48 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_oldest_index = 0; // initializing with the naive method
	return ;
}

PhoneBook::~PhoneBook() {
	return ;
}

std::string	PhoneBook::removeSpaces(std::string text)
{
	std::string	result;

	result	= "";
	for (int i = 0; i < (int) text.length(); i++)
	{
		if (!isspace(text[i]))
			result += text[i];
	}
	return (result);
}

std::string	PhoneBook::truncateString(std::string text)
{
	std::string	result;
	int		start;
	int		length;

	start = 0;
	length = 9;
	result = text.substr(start, length);
	result += ".";
	return (result);
}

void	PhoneBook::addContact(Contact new_contact) {
	int	i;

	i = 0 ;
	while (i < MAX_CONTACTS)
	{
		if (_contacts[i].getFirstName() == "")
			break ;
		i++;
	}
	if (i == MAX_CONTACTS) // TO replace oldest contact
	{
		_contacts[_oldest_index] = new_contact;
		_oldest_index = (_oldest_index + 1) % MAX_CONTACTS;
	}
	else
		_contacts[i] = new_contact; 
}

void	PhoneBook::printContacts() {
	std::string	contactName, contact_last_name, contact_nickname;

	std::cout << "----------|----------|----------|----------|" << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|" << \
	std::setw(10) << std::right << "First Name" << "|"<< \
	std::setw(10) <<  std::right << "Last Name" << "|" << \
	std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << "----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contactName = _contacts[i].getFirstName();
		if (contactName.length() == 0)
			break ;
		contact_last_name = _contacts[i].getLastName();
		contact_nickname = _contacts[i].getNickName();
		std::cout << std::setw(10) << std::right << i + 1;
		std::cout << "|";
		if (contactName.length() > 10)
			contactName = truncateString(contactName);
		std::cout << std::setw(10) << std::right << contactName;
		std::cout << "|";
		if (contact_last_name.length() > 10)
			contact_last_name = truncateString(contact_last_name);
		std::cout << std::setw(10) << std::right << contact_last_name;
		std::cout << "|";
		if (contact_nickname.length() > 10)
			contact_nickname = truncateString(contact_nickname);
		std::cout << std::setw(10) << std::right << contact_nickname;
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::printContactInfo(std::string contact_index) {
	int	index;

	index = atoi(contact_index.c_str()) - 1;
	if (index < 0 || index > (MAX_CONTACTS - 1))
	{
		std::cout << RED << "Error!: " << RESET << "Invalid contact index entered" << std::endl;
		std::cout << "min: 1, max: " << MAX_CONTACTS << std::endl;
		std::cout << std::endl;
	}
	else
	{
		if (_contacts[index].getFirstName() == "")
			std::cout << YELLOW "Attention!: " << RESET << "Contact does not exist" RESET << std::endl;
		else
		{
			std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
			std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
			std::cout << "Nick Name: " << _contacts[index].getNickName() << std::endl;
			std::cout << "Phone: " << _contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << _contacts[index].getSecret() << std::endl;
			std::cout << std::endl;
		}
	}
}

int	PhoneBook::totalContacts()
{
	int	total;

	total = 0;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (_contacts[i].getFirstName().length() > 0)
			total++;
		else
			break ;
	}
	return total;
}
