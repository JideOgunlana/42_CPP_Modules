/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:18:33 by bogunlan         #+#    #+#             */
/*   Updated: 2023/05/26 14:13:39 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Span.hpp"
#include <iomanip>


int main() {
    
    Span a = Span(5);
    Span b(10);
    Span c = b;

    a.addNumber(INT_MAX);
    a.addNumber(0);
    a.addNumber(INT_MIN);


    std::list<int> x;
    // filling x with odd numbers
    for (int i = 1; i <= 18; i+= 2) {
        x.push_back(i);
    }
    std::list<int>::const_iterator it = x.begin();
    std::list<int>::const_iterator ite = x.end();

    // std::advance(it, 1);
    // std::advance(ite, 1);
    c.addManyNumbers(it, ite);
    std::cout << "Numbers in span c: ";
    c.displayNumbers();

    std::cout << "Numbers in span a: ";
    a.displayNumbers();

    std::cout << std::endl;

    std::cout << "Shortest span for a: " << std::fixed << std::setprecision(0) << a.shortestSpan() << std::endl;

    // std::cout << std::endl;

    std::cout << "Longest span for a: " << std::fixed << std::setprecision(0) << a.longestSpan() << std::endl;

    // std::cout << std::endl;

    std::cout << "*****" << std::endl;
    try {
        c.addNumber(-1212);
        // c.addNumber(-1);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Numbers in span c: ";
    c.displayNumbers();
    std::cout << "Numbers in span b: ";
    b.displayNumbers();

    return 0;
}
