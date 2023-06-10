/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:09:58 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/26 14:20:46 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/easyfind.hpp"

#include <list>

int main() {
    //  extended initializer lists can not be used in C++98, only from C++11
    // std::list<int> myList {0, 1};

    std::list<int> myList;
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    
    std::list<int>::const_iterator x = easyfind(myList, 1);
    std::list<int>::const_iterator y = easyfind(myList, 2);
    std::list<int>::const_iterator z = easyfind(myList, 5);

    
    if (x != myList.end())
        std::cout << "Found: " << *x << std::endl;
    if (y != myList.end())
        std::cout << "Found: " << *y << std::endl;
    if (z != myList.end())
        std::cout << "Found: " << *z << std::endl;

    return 0;
}
