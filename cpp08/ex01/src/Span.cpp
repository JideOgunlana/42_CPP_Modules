/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:18:45 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/26 14:20:13 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int N) : _span_size(N), _current_span_size(0) {
    
}

Span::Span(Span const &src) : _span_size(src._span_size), _current_span_size(0) {
    *this = src;
}

Span & Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        this->_int_span = rhs._int_span;
        this->_span_size = rhs._span_size;
    }
    return *this;
}


void Span::addNumber(int const &num) {
    this->_current_span_size += 1;
    if (this->_current_span_size > this->_span_size)
        throw Span::SpanFullException();
    else {
        this->_int_span.push_back(num);
    }
}

int Span::max(std::list<int> list) {
    std::list<int>::const_iterator i = list.begin();
    std::list<int>::const_iterator ie = list.end();

    int tmp = *i;
    while (i != ie) {
        if (tmp < *i)
            tmp = *i;
        i++;
    }
    return tmp;
}

int Span::min(std::list<int> list) {
    std::list<int>::const_iterator i = list.begin();
    std::list<int>::const_iterator ie = list.end();

    int tmp = *i;
    while (i != ie) {
        if (tmp > *i)
            tmp = *i;
        i++;
    }
    return tmp;
}

double Span::shortestSpan() const {

    double shortest_span = 0;
    if (this->_current_span_size < 2)
        throw Span::NotEnoughNumbers();
    double largest_val = Span::max(this->_int_span);
    double smallest_val = Span::min(this->_int_span);
    shortest_span = largest_val - smallest_val;
    std::list<int> numbers = this->_int_span;

    double prev = 0;
    bool prev_is_set = false;

    numbers.sort();
    std::list<double> doubleList;
    std::list<int>::const_iterator numbers_it = numbers.begin();
    while ( numbers_it != numbers.end() ) {
        double converted_num = static_cast<double>(*numbers_it);
        doubleList.push_back(converted_num);
        numbers_it++;
    }

    std::list<double>::const_iterator i = doubleList.begin();

    while (i != doubleList.end()) {
        if (*i - prev < shortest_span && prev_is_set) {
            shortest_span = *i - prev;
        }
        prev = *i;
        prev_is_set = true;
        i++;
    }

    return shortest_span;
}

double Span::longestSpan() const {

    if (this->_current_span_size < 2)
        throw Span::NotEnoughNumbers();

    double largest_val = Span::max(this->_int_span);
    double smallest_val = Span::min(this->_int_span);
    
    return (largest_val - smallest_val);
}

void Span::display(int num) {
    std::cout << num << " ";
}

void Span::displayNumbers() const {
    for_each(this->_int_span.begin(), this->_int_span.end(), display);
    std::cout << std::endl;
}