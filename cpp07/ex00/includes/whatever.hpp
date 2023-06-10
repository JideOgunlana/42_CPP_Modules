/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:13:07 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 16:31:55 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
};


template <typename T>
T const & min(T const &a, T const &b) {
    return (a < b) ? a : b;
};


template<typename T>
T const &max(T const &a, T const &b) {
    return (a > b) ? a : b;
};


#endif
