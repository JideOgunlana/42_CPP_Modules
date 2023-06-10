/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:57:14 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 07:46:47 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"


int main() {
	Bureaucrat *secretary_a = NULL;
	try {
		std::cout << "\t \033[1;34m --- Bureaucrats Initialization --- \e[0m" << std::endl;
		secretary_a = new Bureaucrat("Secretary", 149);
		Bureaucrat commissioner = Bureaucrat("Commisioner", 10);
		Bureaucrat secretary_b = *secretary_a;
		std::cout << std::endl;

		std:: cout << "\t \033[0;33m --- Print Bureaucrats --- \e[0m" << std::endl;
		std::cout << *secretary_a << std::endl;
		std::cout << commissioner << std::endl;
		std::cout << secretary_b << std::endl;
		std::cout << std::endl;

		std:: cout << "\t \033[1;34m --- Downgrade Bureaucrat grade --- \e[0m" << std::endl;
		secretary_a->decrementGrade();
		secretary_a->decrementGrade();
		std::cout << *secretary_a << std::endl;
		
		for (size_t i = 1; i <= 50; i++) {
			commissioner.decrementGrade();
		}
		std::cout << commissioner << std::endl;
		std::cout << std::endl;


		std:: cout << "\t \033[1;34m --- Upgrade Bureaucrat grade --- \e[0m" << std::endl;
		for (size_t i = 1; i <= 50; i++) {
			secretary_b.incrementGrade();
		}
		std::cout << secretary_b << std::endl;
		std::cout << std::endl;

		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary_a;
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;

		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary_a;
	}
	catch(Bureaucrat::GradeTooLowException &e) {
		std::cout << "\033[0;31mError! \e[0m" << std::endl;
		std::cout << e.what() << std::endl;

		std::cout << "\t \033[0;33m --- Destroy Objects --- \e[0m" << std::endl;
		delete secretary_a;
	}
	return 0;
}
