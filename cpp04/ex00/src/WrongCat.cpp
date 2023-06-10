/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:42:09 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:33:19 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "WrongCat default constructor called" << std::endl;
	setType("Cat");
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Cat says meow" << std::endl;
	return ;
}