/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:58:43 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 15:39:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/FragTrap.hpp"

int main() {
	FragTrap fraggy("Fraggy-zeus");
	FragTrap laggy("Laggy");
	FragTrap *almighty = new FragTrap("Almighty");
	FragTrap x;

	std::cout << std::endl;
	fraggy.highFivesGuys();
	fraggy.attack(laggy.getName());
	laggy.takeDamage(10);
	almighty->attack(fraggy.getName());
	std::cout << std::endl;

	std::cout << "FragTrap " << fraggy.getName() << " hit points: " << fraggy.getHitPoints() << std::endl;
	std:: cout << "FragTrap " << laggy.getName() << " hit points: " << laggy.getHitPoints() << std::endl;
	std:: cout << "FragTrap " << almighty->getName() << " hit points: " << almighty->getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "FragTrap " << fraggy.getName() << " energy points: " << fraggy.getEnergyPoints() << std::endl;
	std:: cout << "FragTrap " << laggy.getName() << " energy points: " << laggy.getEnergyPoints() << std::endl;
	std:: cout << "FragTrap " << almighty->getName() << " energy points: " << almighty->getEnergyPoints() << std::endl;
	std::cout << std::endl;

	x.highFivesGuys();
	std::cout << std::endl;

	delete almighty;
	return 0;
}