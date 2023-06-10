/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:35:38 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:52:57 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : _name(name) , _a_weapon(type){
	// std::cout << "Human A constructor called" << std::endl;
	return ;
}

HumanA::~HumanA() {
	// std::cout << "Human A destructor called" << std::endl;
	return ;
}

void	HumanA::attack() const {
	std::cout << this->_name << " attacks with their weapon " << this->_a_weapon.getType() << std::endl;
}
