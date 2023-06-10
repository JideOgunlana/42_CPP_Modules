/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:13:59 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:47:12 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"

class Cat : public AAnimal {
	public:
		Cat();
		Cat(Cat const &src);
		Cat & operator=(Cat const &rhs);
		virtual ~Cat();
		void makeSound(void) const;
};
