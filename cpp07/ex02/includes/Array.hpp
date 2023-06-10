/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:30:20 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 21:11:45 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdlib.h>
# include <stdexcept>

template <typename T>
class Array {
    private:
        T* _arr;
        unsigned int _arr_size;
    public:
        Array() : _arr_size(0) {
            _arr = new T[0];
        }
        Array(unsigned int n) : _arr_size(n) {
            _arr = new T[n];
            for (unsigned int i = 0; i < _arr_size; ++i) {
                _arr[i] = T();
            }
        }
        Array(Array const &src) {
            Array();
           *this = src;
        }
        Array & operator=(Array const &rhs) {

            if (this != &rhs) {
                    delete [] _arr;
                _arr_size = rhs._arr_size;
                _arr = new T[_arr_size];
                for (unsigned int i = 0; i < _arr_size; i++) {
                    _arr[i] = rhs[i];
                }
            }
            return *this;
        }
        ~Array() {
            delete [] _arr;
        }

        // overloaded operator[] for type 'const Array<T>'
        T const & operator[](unsigned int i) const
		{
			if (i >= _arr_size)
				throw std::invalid_argument( "Index out of bounds" );
			return _arr[i];
		}

        // overloaded operator[] for non-const Array<T>
        T & operator[](unsigned int i)
		{
			if (i >= _arr_size)
				throw std::invalid_argument( "Index out of bounds" );
			return _arr[i];
		}

    
        unsigned int size() const {
            return _arr_size;
        }
};

#endif
