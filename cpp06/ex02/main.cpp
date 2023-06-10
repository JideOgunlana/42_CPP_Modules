/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:04:31 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 07:39:11 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Base.hpp"

int main(void) {
    Base *some_instance = generate();
    Base &some_instance_ref = *some_instance;

    
    identify(some_instance);
    if (some_instance != NULL)
        identify(some_instance_ref);

    delete some_instance;

    return 0;
}
