/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:53:27 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/02 12:14:00 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		std::string const			_name;
		bool						_sign_state;
		int const					_sign_grade;
		int const					_exec_grade;

	public:
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(AForm const &src);
		AForm & operator =(AForm const &rhs);
		virtual ~AForm();

		std::string getFormName() const;
		int	getSignState() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &src);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class FormUnsignedException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
};

std::ostream& operator <<(std::ostream &o, const AForm &rhs);

#endif
