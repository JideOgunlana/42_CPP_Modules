/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:27:24 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/06 17:41:28 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    // Fixed b(12.6f);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c(12.6f);
    std::cout << std::endl;

    std::cout << "a: " <<  a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << (b == c) << " : b == c" << std::endl;
    std::cout << (b != c) << " : b != c: " << std::endl;
    std::cout << "min a,b: " << Fixed::min(a, b) << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a: " << ++a << std::endl;

    std::cout << "a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "max a, b" << Fixed::max( a, b ) << std::endl;
    std::cout << std::endl;
    std::cout << "c: " << c << std::endl;
    c = a--;
    std::cout << "a: " << a << std::endl;
    std::cout << "c: " << c << std::endl;
    c = --a;
    std::cout << "a: " << a << std::endl;
    std::cout << "c: " << c << std::endl;
    return 0;
}


// int main( void ) {

//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;

//     return 0;
// }