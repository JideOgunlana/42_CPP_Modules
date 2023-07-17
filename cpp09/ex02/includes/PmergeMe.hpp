/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:25:43 by codespace         #+#    #+#             */
/*   Updated: 2023/07/17 09:02:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# include <algorithm>
# include <cstdio>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &rhs);

		// Private member attributes
		static std::vector<int> _vector;
		static std::deque<int>  _deque;

		// Private methods
		static bool isNumberValid(const char *str);
		static void mergeInsertionSortVector(int argc, char **argv);
		static void mergeInsertionSortDeque(int argc, char **argv);

		template<typename T>
		static T insertionSort(T &container) {
			for (size_t currIndex = 1; currIndex < container.size(); currIndex++) {
				int prevIndex = currIndex - 1;
				int currValue = container[currIndex];

				while (prevIndex >= 0 && container[prevIndex] > currValue) {
					container[prevIndex + 1] = container[prevIndex];
						prevIndex--;
					}
				container[prevIndex + 1] = currValue;
			}

			return container;
		}

		template<typename T>
		static T merge(T &left, T&right) {
			T container;
			size_t leftIndex = 0;
			size_t rightIndex = 0;

			while (leftIndex < left.size() && rightIndex < right.size()) {
				if (left[leftIndex] < right[rightIndex]) {
					container.push_back(left[leftIndex]);
					leftIndex++;
				}
				else {
					container.push_back(right[rightIndex]);
					rightIndex++;
				}
			}

			while (leftIndex < left.size()) {
				container.push_back(left[leftIndex]);
				leftIndex++;
			}

			while (rightIndex < right.size()) {
				container.push_back(right[rightIndex]);
				rightIndex++;
			}

			return container;
		}

		template<typename T>
		static T mergeInsertionSortContainer(T &container) {
			if (container.size() <= 3) {
				return insertionSort(container);
			}

			const int middle = container.size() / 2;
			T left;
			T right;

			int counter = 0;

			typename T::iterator container_it = container.begin();
			while (container_it != container.end()) {
				left.push_back(*container_it);
				container_it++;
				counter++;
				if (counter == middle) {
					break ;
				}
			}

			while (container_it != container.end()) {
				right.push_back(*container_it);
				container_it++;
			}

			T sortedLeft = mergeInsertionSortContainer(left);
			T sortedRight = mergeInsertionSortContainer(right);

			return merge(sortedLeft, sortedRight);
		}
	public:
		static void mergeInsertionSort(int argc, char **argv);
};
