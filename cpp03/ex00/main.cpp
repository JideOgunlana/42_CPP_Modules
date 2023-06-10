/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:01:31 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/12 17:25:27 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ClapTrap.hpp"

int main() {
	ClapTrap trappy("trappy");
	ClapTrap trappy_the_2nd(trappy);
	ClapTrap x;

	std::cout << std::endl;
	std::cout << "ClapTrap name: " << x.getName() << std::endl;
	std::cout << "ClapTrap name: " <<  trappy.getName() << std::endl;
	std::cout << "ClapTrap name: " <<  trappy_the_2nd.getName() << std::endl;
	std::cout << std::endl;


	x.attack(trappy.getName());
	trappy.takeDamage(0);
	std::cout << "ClapTrap " << trappy.getName() << " hit points: " << trappy.getHitPoints() << std::endl;
	trappy.takeDamage(4);
	std::cout << "ClapTrap " << trappy.getName() << " hit points: " << trappy.getHitPoints() << std::endl;
	trappy.beRepaired(2);
	std::cout << "ClapTrap " << trappy.getName() << " hit points: " << trappy.getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "ClapTrap " << trappy.getName() << " energy points: " << trappy.getEnergyPoints() << std::endl;
	std::cout << "ClapTrap " << x.getName() << " energy points: " << x.getEnergyPoints() << std::endl;
	std::cout << "ClapTrap " << trappy_the_2nd.getName() << " energy points: " << trappy_the_2nd.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	return 0;
}
