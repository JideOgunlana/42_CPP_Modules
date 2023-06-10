/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:26:18 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 14:03:36 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int	_fixed_value;
		static int const _fractional_bit;
	public:
		Fixed(void);
		Fixed(Fixed const &instance);
		Fixed& operator=(Fixed const &rhs);
		~Fixed(void);

		int  getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif