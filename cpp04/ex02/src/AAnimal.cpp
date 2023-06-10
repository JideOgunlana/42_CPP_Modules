/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:14:59 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:33:00 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("unknown animal") {
	std::cout << "AAnimal default constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &src) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
	return;
}

AAnimal & AAnimal::operator=(AAnimal const &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

void AAnimal::setType(std::string const type) {
	this->_type = type;
	return ;
}

std::string AAnimal::getType() const {
	return this->_type;
}
