/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:12:25 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 17:10:56 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AAnimal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"

int main() {
	const AAnimal *a = new Dog();
	// const AAnimal *b = new AAnimal(); // cannot be instantiated because AAnimal is an abstract class
	const AAnimal *c = new Cat();
	std::cout << std::endl;

	std::cout << "Animal type: " << a->getType() << std::endl;
	a->makeSound();
	std::cout << "Animal type: " << c->getType() << std::endl;
	c->makeSound();
	std::cout << std::endl;

	delete a;
	delete c;

	return 0;
}
