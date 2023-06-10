/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:28:56 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/05 16:03:10 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(Brain const &src);
		Brain& operator=(Brain const &rhs);
		~Brain();

		void setIdea(std::string idea);
		void getIdea(int idea_index) const;
};

#endif