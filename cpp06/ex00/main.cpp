/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:18:42 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 11:23:42 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ScalarConverter.hpp"

int main(int argc, char **argv) {

    try {
        if (argc != 2)
            throw std::exception();
        std::string s = argv[1];
        ScalarConverter::converter(s);
    }
    catch(std::exception & e) {
        std::cout << "Error!\nWrong number of arguments passed" << std::endl;
    }
}
