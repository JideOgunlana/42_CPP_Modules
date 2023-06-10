/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:31:38 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:45:47 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie() {
	// std::cout << "constructor called" << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << this->_name + " destructor called" << std::endl;
	return ;
}

void	Zombie::announce() {
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setZombieName(std::string name) {
	this->_name = name;
	return ;
}

std::string	Zombie::getZombieName() const{
	return this->_name;
}