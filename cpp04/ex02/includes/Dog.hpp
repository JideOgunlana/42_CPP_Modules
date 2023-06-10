/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:14:24 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:47:17 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"

class Dog : public AAnimal {
	public:
		Dog();
		Dog(Dog const &src);
		Dog& operator =(Dog const &rhs);
		virtual ~Dog();

		void makeSound(void) const;

};
