/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:27:35 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:39:30 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string _type;
		void setType(std::string const type);
	public:
		Animal();
		Animal(Animal const &src);
		Animal & operator=(Animal const &rhs);
		virtual ~Animal(); // The virtual keyword allows the right destructor to be called
		virtual void makeSound(void) const;
		std::string getType() const;
};

#endif