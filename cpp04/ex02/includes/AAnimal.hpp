/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:13:15 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:40:19 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
	protected:
		std::string _type;
		void setType(std::string const type);
	public:
		AAnimal();
		AAnimal(AAnimal const &src);
		AAnimal & operator=(AAnimal const &rhs);
		virtual ~AAnimal(); // The keyword virtual allows the right destructor to be called
		virtual void makeSound(void) const = 0; // syntax for a pure virtual function
		std::string getType() const;
};

#endif