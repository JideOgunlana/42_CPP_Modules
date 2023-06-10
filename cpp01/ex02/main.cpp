/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:33:46 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/24 16:50:19 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "str: " << &str << std::endl;
	std::cout << "strPtr: " << stringPTR << std::endl;
	std::cout << "strRef: " << &stringREF << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "strPtr: " << *stringPTR << std::endl;
	std::cout << "strRef: " << stringREF << std::endl;

	return 0;
}
