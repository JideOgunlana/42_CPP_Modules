/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:23:38 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:41:11 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	// std::cout << "Constructor called" << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << this->_name +  " destructor called" << std::endl;
	return ;
}

void	Zombie::announce() {
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
