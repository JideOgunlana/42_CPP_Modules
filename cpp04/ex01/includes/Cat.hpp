/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:27:58 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:02 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_cat_brain;
	public:
		Cat();
		Cat(Cat const &src);
		Cat & operator=(Cat const &rhs);
		virtual ~Cat();
		void makeSound(void) const;
		void setIdea(std::string idea);
		void getIdea(int idea_index) const;
};
