/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:10:43 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/26 14:21:17 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

class NumNotFoundException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("Number not found");
        }
};

void displayContent(int num) {
    std::cout << num << " ";
}

template<typename T>
typename T::const_iterator const easyfind(T const &container, int num) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), num);
    try {
        if (it == container.end()) {
            throw NumNotFoundException();
        }
    }
    catch(NumNotFoundException & e) {
        std::cout << e.what() << std::endl;
        std::cout << "Number [" << num << "] searched for is not part of the array => ";
        for_each(container.begin(), container.end(), displayContent);
        std::cout << std::endl;
    }
    return it;
}
