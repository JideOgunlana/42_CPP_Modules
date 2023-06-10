/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:35:50 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:53:20 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	// std::cout << "Human B constructor called" << std::endl;
	return ;
}

HumanB::~HumanB() {
	// std::cout << "Human B destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &type) {
	this->_b_weapon = &type;
	return ;
}

void	HumanB::attack() const {
	std::cout << this->_name << " attacks with their weapon " << this->_b_weapon->getType() << std::endl;
}
