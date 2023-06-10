/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:36:06 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:53:55 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) { // default weapon upon creating first instance of that weapon
	// std::cout << "Weapon Constructor called" << std::endl;
	return ;
}

Weapon::~Weapon() {
	// std::cout << "Weapon Destructor called" << std::endl;
	return ;
}

std::string	const& Weapon::getType() const { // return a constant reference to type
	return this->_type;
}

void	Weapon::setType(std::string new_type) { // sets weapon type using the new type passed
	this->_type = new_type;
	return ;
}
