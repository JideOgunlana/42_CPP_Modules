/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:31:47 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 16:31:49 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie *horde_of_zombies;

	horde_of_zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde_of_zombies[i].setZombieName(name);
	}
	return horde_of_zombies;
}
