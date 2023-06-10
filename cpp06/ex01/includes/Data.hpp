/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:48:03 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/04 04:54:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

class Node {
    private:

    public:
        std::string data;
        Node *next;
        Node(std::string str) : data(str), next(NULL) {};
};

class Data {
    private:
        Node *_head;
    public:
        Data();
        ~Data();
        void insert(std::string value);
        void display();
};

#endif
