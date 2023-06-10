/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:32:40 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/13 06:00:36 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <climits>

class ClapTrap {
	protected:                             // access only to instances of this class and objects derived from this class
		std::string _name;
		int	_hit_points;
		int	_energy_points;
		int	_attack_damage;
	public:
		ClapTrap();												// default constructor
		ClapTrap(std::string const name);						// parametric constructor
		ClapTrap(ClapTrap const &src);							// copy constructor
		ClapTrap & operator =(ClapTrap const &rhs);				// copy assignment operator
		virtual ~ClapTrap();											// destructor
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int	getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		void	setName(std::string const name);
		void	setHitPoints(int amount);
		void	setEnergyPoints(int amount);
		void	setAttackDamage(int amount);
};

#endif