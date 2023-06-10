/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:38:39 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 14:16:40 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc - 1; i++)
		{
			for (int j = 0; j < (int) strlen(argv[i]); j++) {
				std::cout << (char) toupper(argv[i][j]);
				std::cout << " ";
			}
		}
		for (int j = 0; j < (int) strlen(argv[argc - 1]); j++)
			std::cout << (char) toupper(argv[argc - 1][j]);
	}
	std::cout << std::endl;
	return (0);
}
