/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:08:11 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 07:30:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Data.hpp"

Data::Data() : _head(NULL) {
    
};

Data::~Data() {
    Node *head  = this->_head;

    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void Data::insert(std::string value) {
    Node* newNode = new Node(value);
    if (this->_head == NULL) {
        this->_head = newNode;
    }
    else {
        Node *curr = this->_head;
        while (curr) {
            if (!curr->next) {
                break ;
            }
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void Data::display() {
    Node *head = this->_head;

    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
