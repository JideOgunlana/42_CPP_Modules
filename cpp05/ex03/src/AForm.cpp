	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:53:13 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/29 15:35:29 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("Default form"), _sign_state(false), _sign_grade(140), _exec_grade(70) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_state(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	std::cout << "AForm parametric constructor called" << std::endl;
}

AForm::AForm(AForm const &src) : _name(src._name), _sign_state(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm() {
	std::cout << _name << ", Aform destructor called" << std::endl;
}

AForm& AForm::operator=(AForm const &rhs) {
	if (this != &rhs) {
		this->_sign_state = rhs._sign_state;
	}
	return *this;
}

std::string AForm::getFormName() const {
	return this->_name;
}

int AForm::getSignState() const {
	return this->_sign_state;
}

int AForm::getSignGrade() const {
	return this->_sign_grade;
}

int AForm::getExecGrade() const {
	return this->_exec_grade;
}

const char * AForm::GradeTooLowException::what() const throw() {
	return ("A form sign grade/exec grade is too low");
}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("A form sign grade/exec grade is too high");
}

const char * AForm::FormUnsignedException::what() const throw() {
	return ("AForm: Form is not signed");
}

void AForm::beSigned(Bureaucrat &src) {
	try {
		if (src.getGrade() > this->_sign_grade) {
			throw AForm::GradeTooLowException();
		}
		else {
			this->_sign_state = true;
			std::cout << this->getFormName() << " 🖋 \t(✅)" << std::endl;
		}
	}
	catch(AForm::GradeTooLowException & e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << src << " cannot sign " << this->getFormName() << " sign grade " << this->getSignGrade() << std::endl;
	}
}
