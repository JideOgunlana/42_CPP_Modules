/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:31:26 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/08 19:33:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Animal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"
#include <cstdlib>

int main() {

	std::cout << "\t-----Array of animlas test-----" << std::endl;
	int		total = 6;
	Animal	*animals[total];

	for (int i = 0; i < total; i++) {
		(i < total / 2) ? animals[i] = new Dog() : animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < total; i++) {
		delete animals[i];
	}
	std::cout << "\t-----Array test complete-----" << std::endl;
	
	std::cout << "\n\t-----Deep copy test-----" << std::endl;
	Dog *a = new Dog();

	a->setIdea("Eat 🍖 🍗 🦴");
	a->setIdea("sleep for a long period");
	a->setIdea("Dig a deep hole at the park");
	a->setIdea("get a dog/b***h");

	Dog *b = new Dog(*a);

	std::cout << std::endl;
	std::cout << a->getType() << " idea is: ";
	a->getIdea(0);
	a->getIdea(1);
	a->getIdea(2);
	a->getIdea(3);
	delete a;
	std::cout << b->getType() << " made from Deep copy idea is: ";
	b->getIdea(3);
	b->getIdea(7);
	b->getIdea(101);
	delete b;
	std::cout << "\t-----Deep copy test complete-----" << std::endl;
	
	Cat *c = new Cat();

	c->makeSound();
	c->getIdea(0);
	c->setIdea("get a tomcat/queen");
	c->setIdea("climb the tree outside");
	std::cout << c->getType() << " idea is: ";
	c->getIdea(0);
	delete c;

	return 0;
}
