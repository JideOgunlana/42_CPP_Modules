/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:18:28 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/26 14:20:11 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <climits>


class Span {
    private:
        unsigned int _span_size;
        unsigned int _current_span_size;
        std::list<int> _int_span;
        
        static void display(int num);
        static int max(std::list<int> list);
        static int min(std::list<int> list);
        
        Span();
    public:
        Span(unsigned int N);
        Span(Span const &src);
        Span & operator =(Span const &rhs);

        //methods
        void addNumber(int const &num);
        double shortestSpan() const;
        double longestSpan() const;
        void displayNumbers() const;

        template<typename InputIterator>
        void addManyNumbers(InputIterator first, InputIterator last) {

            std::list<int>::const_iterator tmp_first = first;
            std::list<int>::const_iterator tmp_last = last;
        
            while( tmp_first != tmp_last ) {
                    this->_current_span_size += 1;
                tmp_first++;   
            }

            if (this->_current_span_size > this->_span_size)
                throw Span::SpanFullException();
            else
                this->_int_span.insert(this->_int_span.end(), first, last);
        }
        
        class SpanFullException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "Span object is FULL!";
                }
        };

        class NotEnoughNumbers : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "Not enough numbers in span object!";
                }    
        };      
};
