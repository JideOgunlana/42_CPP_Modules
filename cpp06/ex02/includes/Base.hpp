/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:04:49 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 07:40:48 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base {
    private:

    public:
        virtual ~Base();
};

/*
* Randomly instanciates A, B or C and returns the instance as a Base pointer. 
*/
Base * generate(void);

/*
* Prints the actual type of the object pointed to by p: "A", "B" or "C".
*/
void identify(Base* p);

/*
* Prints the actual type of the object pointed to by p: "A", "B" or "C".
* Using a pointer inside this function is forbidden.
*/
void identify(Base& p);

#endif
