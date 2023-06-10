/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:01:28 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:45:23 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <climits>

class ClapTrap {
	private:
		std::string _name;
		int	_hit_points;
		int	_energy_points;
		int	_attack_damage;
	public:
		ClapTrap();												// default constructor
		ClapTrap(std::string const name);						// parametric constructor
		ClapTrap(ClapTrap const &src);							// copy constructor
		ClapTrap & operator =(ClapTrap const &rhs);				// copy assignment operator
		~ClapTrap();											// destructor
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int	getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
};

#endif