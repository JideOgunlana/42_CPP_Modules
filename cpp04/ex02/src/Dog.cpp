/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:15:57 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:33:49 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	return ;
}

Dog::Dog(Dog const &src) : AAnimal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog& Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void Dog::makeSound() const {
	std::cout << "Dog says woof!" << std::endl;
	return ;
}
