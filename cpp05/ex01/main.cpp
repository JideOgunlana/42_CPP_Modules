/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:57:14 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 10:18:15 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"


int main() {
	Bureaucrat *secretary = NULL;
	try {
		std::cout << "\t \033[1;34m --- Bureaucrats Initialization --- \e[0m" << std::endl;
		secretary = new Bureaucrat("Secretary", 100);
		Bureaucrat foreign_affairs_specialist = Bureaucrat("Foreign affairs specialist", 20);
		std::cout << std::endl;

		std:: cout << "\t \033[0;33m --- Print Bureaucrats --- \e[0m" << std::endl;
		std::cout << *secretary << std::endl;
		std::cout << foreign_affairs_specialist << std::endl;
		std::cout << std::endl;

		std::cout << "\t \033[1;34m --- Forms Initialization --- \e[0m" << std::endl;
		Form first = Form("Approval form", 100, 30);
		Form second = Form();
		std::cout << std::endl;

		std::cout << " \t \033[1;34m --- Checking possibility to sign form --- \e[0m" << std::endl;
		first.beSigned(*secretary);
		second.beSigned(foreign_affairs_specialist);
		std::cout << std::endl;

		std::cout << "\t \033[0;33m --- Signing of forms --- \e[0m" << std::endl;
		secretary->signForm(first);
		foreign_affairs_specialist.signForm(second);
		std::cout << std::endl;

		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary;
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary;
	}
	catch(Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary;
	}
	catch(Form::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary;
	}
	catch(Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary;
	}
	
	return 0;
}
