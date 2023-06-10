/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:52:46 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:46:04 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include <string>

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "?";
	}
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain& Brain::operator=(Brain const &rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(std::string idea) {
	for (int i = 0; i < 100; i++) {
		if (this->_ideas[i].compare("?") == 0) {
			this->_ideas[i] = idea;
			break ;
		}
	}
	return ;
}

void Brain::getIdea(int idea_index) const {
	if (idea_index >= 0 && idea_index < 100)
		std::cout << this->_ideas[idea_index] << std::endl;
	else
		std::cout << "Out of Brain capacity!" << std::endl;
	return ;
}