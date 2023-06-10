/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:38:01 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/25 01:23:27 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
	public:
		Harl();
		~Harl();
		void complain( std::string level );
};

#endif