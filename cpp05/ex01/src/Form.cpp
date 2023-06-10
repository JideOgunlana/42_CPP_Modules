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

#include "../includes/Form.hpp"

Form::Form() : _name("Default form"), _sign_state(false), _sign_grade(140), _exec_grade(70) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_state(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	std::cout << "Form parametric constructor called" << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _sign_state(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::~Form() {
	std::cout << _name << ", form destructor called" << std::endl;
}

Form& Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		this->_sign_state = rhs._sign_state;
	}
	return *this;
}

std::string Form::getFormName() const {
	return this->_name;
}

int Form::getSignState() const {
	return this->_sign_state;
}

int Form::getSignGrade() const {
	return this->_sign_grade;
}

int Form::getExecGrade() const {
	return this->_exec_grade;
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("A form sign grade/exec grade is too low");
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("A form sign grade/exec grade is too high");
}

void Form::beSigned(Bureaucrat &src) {
	try {
		if (src.getGrade() > this->_sign_grade) {
			throw GradeTooLowException();
		}
		else {
			this->_sign_state = true;
			std::cout << this->getFormName() << " 🖋 \t(✅)" << std::endl;
		}
	}
	catch(Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
}
