/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:57:14 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 09:53:52 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"

void	test1() {
		std::cout << "\t \033[1;34m --- Bureaucrats Initialization --- \e[0m" << std::endl;
		Bureaucrat secretary = Bureaucrat("Secretary", 140);
		Bureaucrat foreign_affairs_specialist = Bureaucrat("Foreign affairs specialist", 20);
		std::cout << std::endl;

		std::cout << "\t \033[0;33m--- Forms Initializaton \e[0m---" << std::endl;
		ShrubberyCreationForm first = ShrubberyCreationForm("job application");
		ShrubberyCreationForm second = ShrubberyCreationForm();
		std::cout << std::endl;

		std::cout << " \t \033[1;34m --- Checking possibility to sign form --- \e[0m" << std::endl;
		first.beSigned(secretary);
		second.beSigned(foreign_affairs_specialist);
		std::cout << std::endl;

		std::cout << "\t \033[0;33m --- Signing of forms --- \e[0m" << std::endl;
		secretary.signForm(first);
		foreign_affairs_specialist.signForm(second);
		std::cout << std::endl;

		std:: cout << "\t \033[1;34m --- Print Bureaucrats --- \e[0m" << std::endl;
		std::cout << secretary << std::endl;
		std::cout << foreign_affairs_specialist << std::endl;
		std::cout << std::endl;

		std::cout << "\t \033[0;33m --- Checking possiblity to execute form --- \e[0m" << std::endl;
		secretary.executeForm(first);
		std::cout << std::endl;
		
		std::cout << "\t \033[1;34m --- Executing forms --- \e[0m" << std::endl;
		first.execute(secretary);
		std::cout << std::endl;

		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
}

void test2() {
	std::cout << "\t \033[1;34m --- Bureaucrats Initialization --- \e[0m" << std::endl;
	Bureaucrat secretary = Bureaucrat("Secretary", 70);
	Bureaucrat foreign_affairs_specialist = Bureaucrat("Foreign affairs specialist", 20);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m--- Forms Initializaton \e[0m---" << std::endl;
	RobotomyRequestForm first = RobotomyRequestForm("job application");
	RobotomyRequestForm second = RobotomyRequestForm();
	std::cout << std::endl;

	std::cout << " \t \033[1;34m --- Checking possibility to sign form --- \e[0m" << std::endl;
	first.beSigned(secretary);
	second.beSigned(foreign_affairs_specialist);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m --- Signing of forms --- \e[0m" << std::endl;
	secretary.signForm(first);
	foreign_affairs_specialist.signForm(second);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m --- Checking possiblity to execute form --- \e[0m" << std::endl;
	secretary.executeForm(first);
	foreign_affairs_specialist.executeForm(first);
	std::cout << std::endl;

	std::cout << "\t \033[1;34m --- Executing forms --- \e[0m" << std::endl;
	first.execute(secretary);
	first.execute(foreign_affairs_specialist);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;

}


void test3() {
	std::cout << "\t \033[1;34m --- Bureaucrats Initialization --- \e[0m" << std::endl;
	Bureaucrat secretary = Bureaucrat("Secretary", 70);
	Bureaucrat foreign_affairs_specialist = Bureaucrat("Foreign affairs specialist", 20);
	Bureaucrat chief_officer = Bureaucrat("Chief Officer", 5);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m--- Forms Initializaton \e[0m---" << std::endl;
	PresidentialPardonForm first = PresidentialPardonForm("job application");
	PresidentialPardonForm second = PresidentialPardonForm();
	std::cout << std::endl;

	std::cout << " \t \033[1;34m --- Checking possibility to sign form --- \e[0m" << std::endl;
	first.beSigned(secretary);
	second.beSigned(foreign_affairs_specialist);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m --- Signing of forms --- \e[0m" << std::endl;
	secretary.signForm(first);
	foreign_affairs_specialist.signForm(second);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m --- Checking possiblity to execute form --- \e[0m" << std::endl;
	secretary.executeForm(first);
	foreign_affairs_specialist.executeForm(first);
	std::cout << std::endl;

	std::cout << "\t \033[1;34m --- Executing forms --- \e[0m" << std::endl;
	first.execute(secretary);
	second.execute(foreign_affairs_specialist);
	second.execute(chief_officer);
	std::cout << std::endl;

	std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;

}

int main() {
	try {
		// test1();
		// test2();
		test3();
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
