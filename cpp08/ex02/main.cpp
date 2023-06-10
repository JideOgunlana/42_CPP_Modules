/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:21 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/07 05:05:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/MutantStack.hpp"
# include <list>
# include <iostream>

// But why would we accept this injustice?

int main()
{
        MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << std::endl;
    std::cout << "Top of stack: " << mstack.top() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Item popped from stack" << std::endl;
    mstack.pop();
    
    std::cout << "Stack size: " << mstack.size() << std::endl;

    std::cout << "Adding four items to stack" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    std::cout << std::endl;

    std::cout << "Traversing through the stack items" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << std::endl;
    std::cout << "*******************" << std::endl;
    std::cout << std::endl;

    std::cout << s.size() << std::endl;
    
    // MutantStack<int> copy = mstack;
    MutantStack<int> copy(s);

    std::cout << "MutantStackcopy size: "<< copy.size() << std::endl;
    std::cout << "RealStack size: " << s.size() << std::endl;


    MutantStack<int>::iterator cp_it = copy.begin();
    std::cout << "Traversing through the stack items" << std::endl;
    while (cp_it != copy.end()) {
        std::cout << *cp_it << std::endl;
        cp_it++;
    }

    return 0;
}
