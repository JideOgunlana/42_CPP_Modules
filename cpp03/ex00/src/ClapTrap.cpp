/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:01:24 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/12 17:18:22 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unnamed"), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src; // shallow copy
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_hit_points = rhs.getHitPoints();
		this->_attack_damage = rhs.getAttackDamage();
		this->_energy_points = rhs.getEnergyPoints();
		this->_name = rhs.getName();
	}
	return *this;
}

std::string ClapTrap::getName() const{
	return this->_name;
}

int	ClapTrap::getHitPoints() const{
	return this->_hit_points;
}

int	ClapTrap::getEnergyPoints() const{
	return this->_energy_points;
}

int	ClapTrap::getAttackDamage() const{
	return this->_attack_damage;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0) {
		return ;
	}
	this->_energy_points -= 1;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= INT_MAX) {
		this->_hit_points = 0;
	}
	else if ((int)amount >= this->_hit_points) {
		this->_hit_points = 0;
	}
	else {
		this->_hit_points -= amount;
	}
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " amount of damage" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
		if ((int) amount <= 0) {
			std::cout << "\033[0;31mError:\e[0m Invalid int value passed to function beRpaired (min: 1, max: 2147483647)" << std::endl;
			return ;
		}
		if (this->_hit_points + amount > INT_MAX)
			this->_hit_points = INT_MAX;
		else
			this->_hit_points += amount;
		this->_energy_points -= 1;
		std::cout << "ClapTrap " << this->getName() << " repaired itself" << std::endl;
	}
	return ;
}
