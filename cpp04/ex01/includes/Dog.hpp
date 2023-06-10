/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:28:20 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:08 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_dog_brain;
	public:
		Dog();
		Dog(Dog const &src);
		Dog& operator =(Dog const &rhs);
		virtual ~Dog();

		void makeSound(void) const;
		void setIdea(std::string idea);
		void getIdea(int idea_index) const;
};
