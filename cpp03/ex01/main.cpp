/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:35:24 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/13 06:02:01 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ScavTrap.hpp"

int main() {
	ClapTrap trappy("Biz");
	ScavTrap x;
	ScavTrap scavvy("scavvy");

	std::cout << std::endl;
	std::cout << "ClapTrap name: " << trappy.getName() << std::endl;
	std::cout << "ScavTrap name: " << scavvy.getName() << std::endl;
	std::cout << "ScavTrap name: " << x.getName() << std::endl;
	std::cout << std::endl;

	std::cout << "ClapTrap " << trappy.getName() << " energy points: " << trappy.getEnergyPoints() << std::endl;
	std:: cout << "ScavTrap " << scavvy.getName() << " energy points: " << scavvy.getEnergyPoints() << std::endl;
	std:: cout << "ScavTrap " << x.getName() << " energy points: " << scavvy.getEnergyPoints() << std::endl;
	std::cout << std::endl;


	scavvy.attack(trappy.getName());
	trappy.takeDamage(5);
	trappy.attack(scavvy.getName());
	trappy.takeDamage(4);
	trappy.attack(scavvy.getName());
	scavvy.takeDamage(5);
	std::cout << std::endl;

	std::cout << "ClapTrap " << trappy.getName() << " hit points: " << trappy.getHitPoints() << std::endl;
	std::cout << "ScavTrap " << scavvy.getName() << " hit points: " << scavvy.getHitPoints() << std::endl;
	std::cout << "ScavTrap " << x.getName() << " hit points: " << x.getHitPoints() << std::endl;
	std::cout << std::endl;


	scavvy.attack(x.getName());
	trappy.attack(x.getName());
	x.beRepaired(4);
	std::cout << std::endl;

	std::cout << "ClapTrap " << trappy.getName() << " energy points: " << trappy.getEnergyPoints() << std::endl;
	std::cout << "Scavrap " << scavvy.getName() << " energy points: " << scavvy.getEnergyPoints() << std::endl;
	std::cout << "ScavTrap " << x.getName() << " energy points: " << x.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "ClapTrap " << trappy.getName() << " hit points: " << trappy.getHitPoints() << std::endl;
	std::cout << "ScavTrap " << scavvy.getName() << " hit points: " << scavvy.getHitPoints() << std::endl;
	std::cout << "ScavTrap " << x.getName() << " hit points: " << x.getHitPoints() << std::endl;
	std::cout << std::endl;

	x.guardGate();
	std::cout << std::endl;

	return 0;
}