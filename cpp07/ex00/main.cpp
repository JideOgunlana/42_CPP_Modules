/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:23:03 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 16:31:44 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/whatever.hpp"


int main() {
    std::string a = "1";
    std::string b = "0.4";

    std::cout << "a = " << a << ", b = " << b << std::endl;

    //~~~~~~~~~~~~~~ min ~~~~~~~~~~~~~~~~~
    std::cout << "min: ";
    std:: cout << ::min(a, b) << std::endl;

    //~~~~~~~~~~~~~~ max ~~~~~~~~~~~~~~~~~
    std::cout << "max: ";
    std::cout << ::max(a, b) << std::endl;


    //~~~~~~~~~~~~~~ swap ~~~~~~~~~~~~~~~~~
    ::swap(a, b);
    std::cout << "swap: ";
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
} 



/* 
int main( void ) {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
} 
*/
