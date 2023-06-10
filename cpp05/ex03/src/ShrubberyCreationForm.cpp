/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:49:31 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/03 10:21:55 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default_shrubbery", 145, 137), _target("default_shrubbery") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137), _target(name) {
	std::cout << this->getFormName() <<  " ShrubberyCreationForm parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src._name, 145, 137) {
	this->_target = src._target;
	std::cout << this->getFormName() << " ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << this->getFormName() << ", ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	this->_target = rhs.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		if (this->getSignState() == false)
			throw AForm::FormUnsignedException();
		if (executor.getGrade() > this->getExecGrade()) {
			throw AForm::GradeTooLowException();
		}
		else {
			std::string tree_art = 
	"			░░▄▀▀▀▄░▄▄\n"
	"			░░░▄▀▀▄█▄░▀▄\n"
	"			░░▀░░░░█░▀▄\n"
	"			░░░░░░.▐▌░░░░\n"
	"			▒▒▄██████▄";

			std::ofstream	ofs;
			std::string		target  = this->getTarget() + ".target";
			std::string		output = "";

			for (int i = 0; i < (int) target.length(); i++) {
				if (target[i] != ' ' && target[i] != '\t' && target[i] != '\n') {
					output += target[i];
				}
			}
			char dst[output.length() + 1];
			strcpy(dst, output.c_str());
			ofs.open(dst, std::ios::out);
			if (!ofs) {
				std::cerr << "Can't open file" << std::endl;
				return ;
			}
			ofs << tree_art << std::endl;
			ofs.close();
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
