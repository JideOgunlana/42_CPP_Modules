/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:15:34 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:33:25 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	return ;
}

Cat::Cat(Cat const &src) : AAnimal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat& Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void Cat::makeSound() const {
	std::cout << "Cat says meow!" << std::endl;
	return ;
}
