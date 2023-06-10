/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:25 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/27 15:35:52 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP


# include <stack>
# include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
    private:
        std::stack<int> _tmp;
    public:
        MutantStack() {};
        MutantStack(std::stack<int> &src) : std::stack<int>(src) { // explicit initialization of base class
        };
        MutantStack(MutantStack const  &src) : std::stack<int>(src) { };
        MutantStack & operator=(MutantStack const &rhs) {
             if (this != &rhs) {
                std::stack<int>::operator=(rhs);
            }
            return *this;
        };
        ~MutantStack() {};
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        // Iterator functions
        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }
};


#endif