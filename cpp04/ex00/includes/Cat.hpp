/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:20:40 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:29 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		Cat & operator=(Cat const &rhs);
		virtual ~Cat();
		void makeSound(void) const;
};
