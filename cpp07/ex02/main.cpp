/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:29:41 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 21:13:18 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Array.hpp"


#include "./includes/Array.hpp"

int main( void )
{
	Array<int> a(10);
	const Array<int> b(4);

	// modifying a non contant array
	a[9] = 10;
	for (int i = 0; i < 10; i++)
		std::cout << a[i] << std::endl;

	try {
		std::cout << "Value at index 9: " << a[9] << std::endl;
		a[12] = 5;
		std::cout << "Value at index 12" << a[12] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "Size of array a: " <<  a.size() << std::endl;
	std::cout << std::endl;
	std::cout << "Size of array b: " <<  b.size() << std::endl;

	// Reading from a constant
	// b[0] = 1;
	for (int i = 0; i < 4; ++i)
		std::cout << b[0] << std::endl;
};
