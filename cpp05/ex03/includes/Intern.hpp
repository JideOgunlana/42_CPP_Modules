/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:14:42 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/24 10:11:59 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern {
	private:
		Intern(Intern const &src);
		Intern & operator=(Intern const &rhs);
	public:
		Intern();
		~Intern();
		AForm *makeForm(std::string const &form_name, std::string const &target) const;

		class FormNotValidException : public std::exception {
				public:
					virtual const char * what() const throw();
		};
};

#endif