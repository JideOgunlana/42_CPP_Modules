/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:26:26 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 17:00:44 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/iter.hpp"

int main() {
    int arrInt[5] = {0, 1, 1, 2, 3};
    char message[5]  = {'H', 'E', 'L', 'L', 'O'};
    float floatingNum[5] = {1.2f, 2.4f, 3.6f, 4.8f, 6.0f};

    ::iter(arrInt, 5, &printArr);
    std::cout << std::endl;
    ::iter(message, 5 , printArr);
    std::cout << std::endl;
    ::iter(floatingNum, 5 , printArr);

    return 0;
}
