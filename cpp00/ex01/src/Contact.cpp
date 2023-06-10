/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:20:28 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 14:20:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Contact.hpp"

Contact::Contact() {
	return ;
}

Contact::~Contact() {
	return ;
}

//	setters
void	Contact::setFirstName(std::string new_name) 
{
	_first_name = new_name; 
}

void	Contact::setPhoneNumber(std::string new_number)
{
	_phone_number = new_number;
}

void	Contact::setLastName(std::string new_last_name)
{
	_last_name = new_last_name;
}

void	Contact::setNickName(std::string new_nick_name)
{
	_nick_name = new_nick_name;
}

void	Contact::setSecret(std::string new_secret)
{
	_secret = new_secret;
}

//	getters
std::string	Contact::getFirstName()
{
	return _first_name;
}

std::string	Contact::getPhoneNumber()
{
	return _phone_number;
}

std::string	Contact::getLastName()
{
	return _last_name;
}

std::string	Contact::getNickName()
{
	return _nick_name;
}

std::string Contact::getSecret()
{
	return _secret;
}
