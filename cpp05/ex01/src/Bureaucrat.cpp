/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:41:37 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 01:16:40 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default bureaucrat"), _grade(150) {
	std::cout << "Bureaucrat default constructor called " << "{ name: " << _name << ", grade: " << _grade << " }" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat parametric constructor called " << "{ name: " << _name << ", grade: " << _grade << " }" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat copy constructor called " << "{ name: " << _name << ", grade: " << _grade << " }" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	std::cout  << _name << ", bureaucrat destructor called" << std::endl;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	// std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("A Bureaucrat's grade value is less than 1");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("A Bureaucrat's grade value is greater than 150");
}

std::ostream& operator <<(std::ostream &o, Bureaucrat const &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void Bureaucrat::incrementGrade() {
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	this->_grade += 1;
}

void Bureaucrat::signForm(Form &src) const{
	if (src.getSignState() == 1) {
		std::cout <<  "Bureaucrat "<< this->_name << " signed " << src.getFormName() << std::endl;
	}
	else {
		std::cout << "Bureacrat " << this->_name <<" couldn't sign " << src.getFormName() <<" because the grade required to sign the form is " << src.getSignGrade() << " but bureaucrat grade " << this->getGrade() << " is not high enough" << std::endl;
	}
}
