/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:36:09 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:51:59 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string	const &getType() const;
		void	setType(std::string new_type);
};

#endif