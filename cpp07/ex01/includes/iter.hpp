/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:25:40 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 17:00:03 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *arr, int arr_len, void (*f)(const T&)) {
    if (!arr || arr_len < 1)
        return ;
    int i = 0;
    while (i < arr_len)
    {
        f(arr[i]);
        i++;
    }
}

template <typename T>
void printArr(const T &x) {
    std::cout << x << std::endl;
}

#endif