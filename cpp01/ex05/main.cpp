/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:38:07 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/25 01:24:18 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Harl.hpp"

int	main() {
	Harl	harl;

	std::cout << "DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << "WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "INFO" << std::endl;
	harl.complain("INFO");
	std::cout << "ERROR" << std::endl;
	harl.complain("INFO");
	return 0;
}