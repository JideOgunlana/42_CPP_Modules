/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:22:41 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/07 16:02:48 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name) {
	std::cout << "ScavTrap parametric constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_hit_points = rhs.getHitPoints();
		this->_attack_damage = rhs.getAttackDamage();
		this->_energy_points = rhs.getEnergyPoints();
		this->_name = rhs.getName();
	}
	return *this;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode" << std::endl;
	return;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0) {
		return ;
	}
	this->_energy_points -= 1;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	return ;
}
