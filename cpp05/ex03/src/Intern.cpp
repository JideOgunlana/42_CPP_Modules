/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:27:20 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 10:24:59 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern:: operator =(Intern const &rhs) {
	(void) rhs;
	return *this;
}

const char * Intern::FormNotValidException::what() const throw() {
	return "Intern: FormNotValidException";
}

AForm * Intern::makeForm(std::string const &form_name, std::string const &target) const {
	AForm *tmp_form;

	try {
		std::string forms[4] = {
			"robotomy request",
			"presidential pardon",
			"shrubbery creation"
		};
		int i = 0;
		for (; i < 3; i++) {
			if (forms[i] == form_name) {
				break ;
			}
		}
		switch(i) {
			case 0:
				tmp_form = new RobotomyRequestForm(target);
				break ;
			case 1:
				tmp_form = new PresidentialPardonForm(target);
				break;
			case 2:
				tmp_form = new ShrubberyCreationForm(target);
				break;
			default:
				throw FormNotValidException();
		}
	}
	catch(Intern::FormNotValidException & e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "Form is not valid" << std::endl;
		return NULL;
	}
	std::cout << "Intern \033[0;34mcreates\e[0m " << form_name << std::endl;
	return tmp_form;
}
