/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:57:14 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 10:15:40 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/Intern.hpp"


void test() {
	std::cout << "\t \033[1;34m --- Interns Initialization --- \e[0m" << std::endl;
	Intern someRandomIntern;
	std::cout << std::endl;

	std::cout << "\t \033[1;34m --- Bureaucrats Initialization --- \e[0m" << std::endl;
	Bureaucrat official = Bureaucrat("President", 1);
	std::cout << std::endl;

	std::cout << "\t \033[1;34m --- Forms Initialization by the Interns --- \e[0m" << std::endl;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy reest", "Bender");
	AForm* scf = someRandomIntern.makeForm("shrubbery creatn", "Kany");
	AForm *pdf = someRandomIntern.makeForm("presidential pardon", "Tilek");
	std::cout << std::endl;

	if (!rrf || !scf || !pdf) {
		if (rrf)
			delete rrf;
		if (scf)
			delete scf;
		if (pdf)
			delete pdf;
		return ;
	}

	rrf->beSigned(official);
	scf->beSigned(official);
	pdf->beSigned(official);

	delete rrf;
	delete scf;
	delete pdf;
}

int main() {
	try {
		test();
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;

	}
	catch(AForm::GradeTooHighException & e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;

	}
	catch(AForm::GradeTooLowException & e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
