/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:05:09 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/04 05:22:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base() {
    
}

Base * generate() {
    std::srand(std::time(0));
    
    Base *instance = NULL;
    int randNumber = std::rand() % 5;
    
    try {
        switch (randNumber) {
            case 0:
                instance = new A();
                std::cout << "Derived class A generated" << std::endl;
                break;
            case 1:
                instance = new B();
                std::cout << "Derived class B generated" << std::endl;
                break;
            case 2:
                instance = new C();
                std::cout << "Derived class C generated" << std::endl;
                break;
            case 3:
                instance = new Base();
                std::cout << "Base class generated" << std::endl;
                break;
            default:
                std::cout << "* Nothing generated *" << std::endl;
                throw std::exception();
        }   
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        std::cout << "Error generating" << std::endl;
    }
    return instance;
}


void identify(Base *p) {
    try {
        if (p == NULL)
            throw std::exception();
        else if (dynamic_cast<A *>(p)) {
            std::cout << "Derived class identified as A" << std::endl;
        }
        else if (dynamic_cast<B *>(p)) {
            std::cout << "Derived class identified as B" << std::endl; 
        }
        else if (dynamic_cast<C *>(p)) {
            std::cout << "Derived class identified as C" << std::endl;
        }
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
        std::cout << "Error Identifying" << std::endl;
    }
}

void identify(Base &p) {

    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Derived class identified as A" << std::endl;
    }
    catch(std::exception & e) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Derived class identified as B" << std::endl;
        }
        catch(std::exception &e) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Derived class identified as C" << std::endl;
            }
            catch(std::exception &e) {
                std::cout << e.what() << std::endl;
                std::cout << "Error Identifying" << std::endl;
            }
        }
    }
}
