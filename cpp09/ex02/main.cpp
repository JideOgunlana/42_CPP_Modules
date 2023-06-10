/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:35:54 by codespace         #+#    #+#             */
/*   Updated: 2023/05/28 16:29:33 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cout << "Error!\nUsage: ./PmergeMe 1 4 3 2 5" << std::endl;
        return 1;
    }
    try {
        PmergeMe::mergeInsertionSort(argc, argv);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
