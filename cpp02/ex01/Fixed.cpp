/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:26:36 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:09:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_value(0) {
	std::cout << "Fixed default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const n_int) {
	std::cout << "Fixed int parametric constructor called" << std::endl;
	this->_fixed_value = n_int << _fractional_bit;
}

Fixed::Fixed(float const n_float) {
	std::cout << "Fixed float parametric constructor called" << std::endl;
	this->_fixed_value = (int) roundf(n_float * (1 << _fractional_bit));
}

Fixed::Fixed(Fixed const &instance) {
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = instance;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Fixed destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=(Fixed const &rhs) {
	std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed_value = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawbits member functon called" << std::endl;
	return this->_fixed_value;
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawbits member functon called" << std::endl;
	this->_fixed_value = raw;
}

int	Fixed::toInt() const {
	// std::cout << "toInt member function called" << std::endl;
	return (this->_fixed_value / (1 << _fractional_bit));
	// return this->_fixed_value >> _fractional_bit;
}

float	Fixed::toFloat() const {
	// std::cout << "toFloat member function called" << std::endl;
	return (float)(this->_fixed_value) / (1 << _fractional_bit);
}

std::ostream& operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return o;
}

int const Fixed:: _fractional_bit = 8;
