/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:27:18 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 13:32:17 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>

class Fixed {
	private:
		int	_fixed_value;
		static int const _fractional_bit;
	public:
		Fixed(void);
		Fixed(int const n_int);
		Fixed(float const n_float);
		Fixed(Fixed const &instance);
		Fixed& operator =(Fixed const &rhs);
		Fixed operator +(Fixed const &rhs) const;
		Fixed operator -(Fixed const &rhs) const;
		Fixed operator *(Fixed const &rhs) const;
		Fixed operator /(Fixed const &rhs) const;
		Fixed operator <(Fixed const &rhs) const;
		Fixed operator >(Fixed const &rhs) const;
		Fixed operator <=(Fixed const &rhs) const;
		Fixed operator >=(Fixed const &rhs) const;
		Fixed operator ==(Fixed const &rhs) const;
		Fixed operator !=(Fixed const &rhs) const;
		Fixed operator ++();
		Fixed operator ++(int);
		Fixed operator --();
		Fixed operator --(int);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static const Fixed& min(Fixed &num1, Fixed &num2);
		static const Fixed& min(Fixed const &num1, Fixed const &num2);
		static const Fixed& max(Fixed &num1, Fixed &num2);
		static const Fixed& max(Fixed const &num1, Fixed const &num2);
};

std::ostream& operator <<(std::ostream &o, Fixed const &rhs);

#endif