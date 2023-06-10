/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:53:27 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/29 15:14:04 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const			_name;
		bool						_sign_state;
		int const					_sign_grade;
		int const					_exec_grade;

	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const &src);
		Form & operator =(Form const &rhs);
		~Form();

		std::string getFormName() const;
		int	getSignState() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &src);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
};

std::ostream& operator <<(std::ostream &o, const Form &rhs);

#endif
