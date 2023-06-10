/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:29:11 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:37:22 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	this->_cat_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_cat_brain = new Brain(*src._cat_brain);
	*this = src;
}

Cat& Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		*(this->_cat_brain) = *(rhs._cat_brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_cat_brain;
}

void Cat::makeSound() const {
	std::cout << "Cat says meow!" << std::endl;
	return ;
}

void Cat::setIdea(std::string idea) {
	this->_cat_brain->setIdea(idea);
	return ;
}

void Cat::getIdea(int idea_index) const {
	this->_cat_brain->getIdea(idea_index);
	return ;
}
