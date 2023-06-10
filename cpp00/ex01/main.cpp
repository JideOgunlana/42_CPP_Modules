/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:22 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 14:17:33 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

void	userFirstName(PhoneBook *phone_book, t_user_input *user_input, t_validation *validate)
{
	std::string	modified_name;

	do {
		std::cout << "Enter Name: ";
		getline(std::cin, user_input->new_first_name);
		modified_name = phone_book->removeSpaces(user_input->new_first_name);
		(modified_name.length() == 0) ? (validate->valid_first_name) = false : (validate->valid_first_name) = true;
		if (!(validate->valid_first_name))
			std::cout << "! First name cannot be empty" << std::endl;
	}
	while (!(validate->valid_first_name));
}

void	userLasttName(PhoneBook *phone_book, t_user_input *user_input, t_validation *validate)
{
	std::string	modified_name;

	do {
		std::cout << "Enter Last Name: ";
		getline(std::cin, user_input->new_last_name);
		modified_name = phone_book->removeSpaces(user_input->new_last_name);
		(modified_name.length() == 0) ? (validate->valid_last_name) = false : (validate->valid_last_name) = true;
		if (!(validate->valid_last_name))
			std::cout << "! Last name cannot be empty" << std::endl;
	}
	while (!(validate->valid_last_name));
}

void	userNickName(PhoneBook *phone_book, t_user_input *user_input, t_validation *validate)
{
	std::string	modified_name;

	do {
		std::cout << "Enter Nick Name: ";
		getline(std::cin, user_input->new_nick_name);
		modified_name = phone_book->removeSpaces(user_input->new_nick_name);
		(modified_name.length() == 0) ? (validate->valid_nick_name) = false : (validate->valid_nick_name) = true;
		if (!(validate->valid_nick_name))
			std::cout << "! Name field cannot be empty" << std::endl;
	}
	while (!(validate->valid_nick_name));
}

void	userPhone(PhoneBook *phone_book, t_user_input *user_input , t_validation *validate)
{
	do {
		std::cout << "Enter phone number: ";
		getline(std::cin, user_input->new_phone);
		user_input->new_phone = phone_book->removeSpaces(user_input->new_phone);
		((user_input->new_phone).length() == 0) ? (validate->valid_phone) = false : (validate->valid_phone) = true;
		if (!(validate->valid_phone))
			std::cout << "! Phone cannot be empty" << std::endl;
	}
	while (!(validate->valid_phone));
}

void	userSecret(PhoneBook *phone_book, t_user_input *user_input, t_validation *validate)
{
	std::string	modified_secret;

	do {
		std::cout << "Enter darkest secret: ";
		getline(std::cin, user_input->new_secret);
		modified_secret = phone_book->removeSpaces(user_input->new_secret);
		(modified_secret.length() == 0) ? (validate->valid_secret) = false : (validate->valid_secret) = true;
		if (!(validate->valid_secret))
			std::cout << "! darkest secret entry cannot be empty" << std::endl;
	}
	while (!(validate->valid_secret));
}

void	addNewContact(PhoneBook *phone_book, t_user_input *user_input)
{
	Contact			new_contact;
	t_validation	validate;

	userFirstName(phone_book, user_input, &validate);
	userLasttName(phone_book, user_input, &validate);
	userNickName(phone_book, user_input, &validate);
	userPhone(phone_book, user_input, &validate);
	userSecret(phone_book, user_input, &validate);

	if (validate.valid_first_name && validate.valid_phone && \
		validate.valid_last_name && validate.valid_nick_name && \
		validate.valid_secret
	)
	{
		new_contact.setFirstName(user_input->new_first_name);
		new_contact.setPhoneNumber(user_input->new_phone);
		new_contact.setLastName(user_input->new_last_name);
		new_contact.setNickName(user_input->new_nick_name);
		new_contact.setSecret(user_input->new_secret);
		phone_book->addContact(new_contact);
		std::cout << std::endl;
	}
}

int main(void) {
	PhoneBook		phone_book;
	std::string			option;
	t_user_input	user_input;
	int				exit_main;

	exit_main = 0;
	std::cout << U_LINE << "Phonebook" RESET << std::endl;
	while (exit_main != 1)
	{
		std::cout << BLUE << "Enter one of these options:" << RESET << std::endl;
		std::cout << BOLD << "ADD, SEARCH or EXIT" << RESET << std::endl;
		getline(std::cin, option);
		option = phone_book.removeSpaces(option);
		if (option == "ADD")
			addNewContact(&phone_book, &user_input);
		else if (option == "SEARCH")
		{
			if (phone_book.totalContacts() == 0)
				std::cout << YELLOW << "Attention! "<< RESET << "Phone book is empty, add a contact" << std::endl;
			else
			{
				phone_book.printContacts();
				std::cout << BLUE << "\nGet contact full information" << RESET << std::endl;
				std::cout << "Enter a contact's index to display the contact's information: ";
				getline(std::cin, user_input.contact_index);
				std::cout << std::endl;
				phone_book.printContactInfo(user_input.contact_index);
			}
		}
		else if (option == "EXIT")
			exit_main = 1;
	}
	// system("leaks a.out");
	return 0;
}
