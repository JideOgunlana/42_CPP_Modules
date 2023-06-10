/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:29:27 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:37:40 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	this->_dog_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_dog_brain = new Brain(*src._dog_brain);
	*this = src;
}

Dog& Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		*(this->_dog_brain) = *(rhs._dog_brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_dog_brain;
}

void Dog::makeSound() const {
	std::cout << "Dog says woof!" << std::endl;
	return ;
}

void Dog::setIdea(std::string idea) {
	this->_dog_brain->setIdea(idea);
	return ;
}

void Dog::getIdea(int idea_index) const {
	this->_dog_brain->getIdea(idea_index);
	return ;
}
