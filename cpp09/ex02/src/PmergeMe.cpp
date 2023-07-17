/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:25:49 by codespace         #+#    #+#             */
/*   Updated: 2023/07/17 11:41:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
std::vector<int> PmergeMe::_vector;
std::deque<int>  PmergeMe::_deque;


bool PmergeMe::isNumberValid(const char *str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!isdigit(str[i]))
			return false;
	}

	int num  = atoi(str);
	if (num < 1)
		return false;
	return true ;
}

void PmergeMe::mergeInsertionSortVector(int argc, char **argv) {

	for (int i = 1; i < argc; ++i) {
		_vector.push_back(atoi(argv[i]));
	}

	std::clock_t start = std::clock();
	std::vector<int>v_result = mergeInsertionSortContainer(_vector);
	std::clock_t end = std::clock();

	std::vector<int>::iterator vector_it = v_result.begin();

	std::cout << "After:\nVECTOR container => ";
	size_t limit_size = 100;
	if (v_result.size() > limit_size) {
		for (size_t i = 0; i < limit_size; ++i) {
			std::cout << *vector_it << " ";
			vector_it++;
		}
		std::cout << "...." << std::endl;
	}
	else {
		while (vector_it != v_result.end()) {
			std::cout << *vector_it << " ";
			vector_it++;
		}
	}
	std::cout << std::endl;
	double timediff = (end - start)  *  1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << v_result.size() << " elements with " << "std::vector: " << timediff << "µs" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::mergeInsertionSortDeque(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_deque.push_back(atoi(argv[i]));
	}
	
	std::clock_t start = std::clock();
	std::deque<int>d_result = mergeInsertionSortContainer(_deque);
	std::clock_t end = std::clock();

	std::deque<int>::iterator deque_it = d_result.begin();

	std::cout << "After:\nDEQUE container => ";
	size_t limit_size = 100;
	if (d_result.size() > limit_size) {
		for (size_t i = 0; i < limit_size; ++i) {
			std::cout << *deque_it << " ";
			deque_it++;
		}
		std::cout << "...." << std::endl;
	}
	else {
		while (deque_it != d_result.end()) {
			std::cout << *deque_it << " ";
			deque_it++;
		}
	}
	std::cout << std::endl;
	double timediff = (end - start)  *  1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << d_result.size() << " elements with " << "std::deque: " << timediff << "µs" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::mergeInsertionSort(int argc, char **argv) {
	bool error = false;

	for (int i = 1; i < argc; ++i) {
		if (isNumberValid(argv[i]) == false) {
			error = true;
		break ;
		}
	}
	if (error) {
		std::cerr << "Error!" << std::endl;
		return ;
	}
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	mergeInsertionSortDeque(argc, argv);
	mergeInsertionSortVector(argc, argv);
}
