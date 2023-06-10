/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:26:12 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:07:19 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_value(0) {
	std::cout << "Fixed Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &instance) {
	std::cout << "Fixed Copy Constructor called" << std::endl;
	*this = instance;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Fixed Destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=(Fixed const &rhs) {
	std::cout << "Fixed Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed_value = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawbits member functon called" << std::endl;
	return this->_fixed_value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawbits member functon called" << std::endl;
	this->_fixed_value = raw;
}

int const Fixed:: _fractional_bit = 8;
