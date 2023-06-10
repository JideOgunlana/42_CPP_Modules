/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:23:29 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:41:22 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	return newZombie;
}


void	randomChump(std::string name) {
	Zombie	newZombie = Zombie(name);

	newZombie.announce();
}

int	main() {
	Zombie *a = newZombie("a");
	a->announce();
	Zombie *b = newZombie("b");
	b->announce();
	Zombie *c = newZombie("c");
	c->announce();

	randomChump("Z");
	randomChump("Y");
	delete(a);
	delete(b);
	delete(c);
	return 0;
}
