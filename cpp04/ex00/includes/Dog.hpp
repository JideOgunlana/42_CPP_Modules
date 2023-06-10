/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:44:11 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:36 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		Dog& operator =(Dog const &rhs);
		virtual ~Dog();

		void makeSound(void) const;
};
