/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:16:41 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/02 07:32:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Animal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"

#include "./includes/WrongAnimal.hpp"
#include "./includes/WrongCat.hpp"

int main() {
	Animal *a = new Animal();
	const Dog *b = new Dog();

	std::cout << "Animal type: "<< a->getType() << std::endl;
	a->makeSound();
	std::cout << "Animal type: " << b->getType() << std::endl;
	b->makeSound();
	delete a;
	delete b;

	std::cout << "\n---WrongAnimal test----" << std::endl;
	const WrongAnimal *c = new WrongCat();

	std::cout << "Animal type: "<< c->getType() << std::endl;
	c->makeSound();

	delete c;

	return 0;
}
