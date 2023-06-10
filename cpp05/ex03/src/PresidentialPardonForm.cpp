/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:49:17 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 10:22:45 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default_presidential", 25, 5), _target("default_presidential") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5), _target(name) {
	std::cout << this->getFormName() <<  " PresidentialPardonForm parametric constructor called" << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src._name, 25, 5) {
	this->_target = src.getTarget();
	std::cout << this->getFormName() << " PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << this->getFormName() << " PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator =(PresidentialPardonForm const &rhs) {
	this->_target = rhs.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		if (this->getSignState() == false)
			throw AForm::FormUnsignedException();
		if (executor.getGrade() > this->getExecGrade()) {
			throw AForm::GradeTooLowException();
		}
		else {
			std::cout << this->getTarget() << " has been \033[0;35mpardoned\e[0m by Zaphod Beeblebrox" << std::endl;
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
