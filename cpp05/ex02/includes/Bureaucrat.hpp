/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:41:35 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/03 18:18:51 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "./AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		std::string	const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat& operator =(Bureaucrat const &rhs);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &src) const;
		void executeForm(AForm const & form);
};

std::ostream & operator <<(std::ostream &o, Bureaucrat const &rhs);


#endif
