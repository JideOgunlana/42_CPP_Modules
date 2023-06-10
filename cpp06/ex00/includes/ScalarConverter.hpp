/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:53:51 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 07:25:53 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <iostream>
# include <limits>
# include <iomanip>
# include <cmath>
# include <cstdio>


typedef enum e_type {
    UNDEFINED,
    INT,
    FLOAT,
    DOUBLE
}           t_type;

class ScalarConverter {
    private:
        static t_type    _type;
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter & operator =(ScalarConverter const &rhs);
        ~ScalarConverter();

        static void converter(char c);
        static void converter(int i);
        static void converter(float f);
        static void converter(double d);

        static int parseStringAsInt(std::string str);
        static int parseStringAsFloat(std::string str);
        static int parseStringAsDouble(std::string str);
    public:
        static void converter(std::string literal);
};


#endif