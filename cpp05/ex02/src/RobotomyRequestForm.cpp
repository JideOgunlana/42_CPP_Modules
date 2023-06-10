/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:02:29 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/03 10:48:08 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :  AForm("default_robotomy", 72, 45), _target("default_robotomy"){
	std::cout << "RobotomyRequest default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45), _target(name) {
	std::cout << this->getFormName() <<  ", RobotomyRequestForm parametric constructor called" << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :  AForm(src._name, 72, 45) {
	this->_target = src.getTarget();
	std::cout << this->getFormName() << ", RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << this->getFormName() << ", RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	this->_target = rhs.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

const char * RobotomyRequestForm::RobotomyException::what() const throw() {
	return "Robotomy: RobotomyException"; 
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		if (this->getSignState() == false)
			throw AForm::FormUnsignedException();
		if (executor.getGrade() > this->getExecGrade()) {
			throw AForm::GradeTooLowException();
		}
		else {
			std::srand(std::time(0));
			int isRobotomized = std::rand() % 2;
			std::cout << "VVVVVVVVvvvvvvvvvvvvvvvvvv!!!!!!!!!!" << std::endl;
			try {
				if (isRobotomized == 1) {
					std::cout << this->getTarget() << " has been robotomized successfully 50% of the time" << std::endl;
				}
				else {
					throw RobotomyException();
				}
			}
			catch(RobotomyException & e) {
				std::cout << "\033[0;31mError! \e[0m" << std::endl;
				std::cout << e.what() << std::endl;
				std::cout << "Target failed to be robotomized" << std::endl;
			}
		}
	}
	catch(AForm::FormUnsignedException & e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << executor << " cannot execute unsigned form " << this->getFormName() << this->getExecGrade() << std::endl;
	}
	catch(AForm::GradeTooLowException & e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << executor << " cannot execute " << this->getFormName() << ", execution grade " << this->getExecGrade() << std::endl;
	}
}
