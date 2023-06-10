/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:11:22 by codespace         #+#    #+#             */
/*   Updated: 2023/05/28 16:21:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/RPN.hpp"


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error!\nUsage: ./RPN \"2 3 4 + -\"" << std::endl;
        return 1;
    }
    if (RPN::RPNCalculator(argv[1]) != 0) {
        std::cerr << "Error!" << std::endl;
    }
    return 0;
}