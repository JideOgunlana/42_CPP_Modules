/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:31:55 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:46:10 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Zombie.hpp"

int	main() {
	Zombie	*horde_of_zombies;
	int		total_zombies = 4;

	horde_of_zombies = zombieHorde(total_zombies, "Villain");
	for (int i = 0; i < total_zombies; i++) {
		std::cout << "zombie name: " << horde_of_zombies[i].getZombieName() << std::endl;
		horde_of_zombies[i].announce();
	}
	delete [] horde_of_zombies;
	return 0;
}
