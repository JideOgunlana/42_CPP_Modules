/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:40:14 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:32:50 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("unknown Wronganimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "Cats don't bark" << std::endl;
	return ;
}

void WrongAnimal::setType(std::string const type) {
	this->_type = type;
	return ;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}
