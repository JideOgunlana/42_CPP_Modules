/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:45:45 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/04 05:14:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Serializer.hpp"
#include "./includes/Data.hpp"

int main(void) {
    Data linked_list;

    
    linked_list.insert("a");
    linked_list.insert("b");
    linked_list.insert("c");
    linked_list.insert("d");
    linked_list.insert("e");
    linked_list.insert("f");
    linked_list.insert("g");


    uintptr_t raw = Serializer::serialize(&linked_list);
    std::cout << "Serialized data: ";
    std::cout << raw << std::endl;

    
    Data *desrialized_data = Serializer::deserialize(raw);
    std::cout << "Deserialized data: ";
    desrialized_data->display();

    return 0;
}