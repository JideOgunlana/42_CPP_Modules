/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:13:53 by codespace         #+#    #+#             */
/*   Updated: 2023/05/28 16:43:33 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

std::stack<float> RPN::_rpnStack;

bool RPN::isWhiteSpace(char c) {
    return std::isspace(static_cast<unsigned char>(c));
}

bool RPN::expressionIsValid(const std::string &str) {

    size_t in_space = 1;

    if (!isdigit(str[0])) {
        return false;
    }
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        char ch = *it;

        if (in_space % 2 == 0 && ch != ' ')
            return false;
        else if (in_space % 2 != 0 && ch == ' ')
            return false;
        // Check if the character is a digit, operator, or space
        if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != ' ') {
            return false;
        }
        in_space++;
    }

    return true;
}

std::string RPN::trimString(const std::string &str) {
    std::string trimmedString = str;

    std::string::iterator firstNonSpace = std::find_if(trimmedString.begin(), trimmedString.end(), std::not1(std::ptr_fun(RPN::isWhiteSpace)));
    std::string::iterator lastNonSpace = std::find_if(trimmedString.rbegin(), trimmedString.rend(), std::not1(std::ptr_fun(RPN::isWhiteSpace))).base();

    // Erase white space characters
    if (*lastNonSpace != 0 && *firstNonSpace != 0)
        return "";
    return trimmedString;
}

float RPN::RPNCalculator(char *str) {

    int expression_error = false;

    if (!str) {
        return 1;
    }
    std::string expression = str;
    expression = RPN::trimString(expression);
    if ( expression.length() < 1 ) {
        return 1;
    }

    if ( RPN::expressionIsValid(expression) == false ) {
        return 1;
    }

    for (size_t i = 0; i < expression.length(); i++ ) {
        if (!isdigit(expression[i]) && expression[i] != ' ') {
            if (_rpnStack.size() > 1) {
                float second_operand = _rpnStack.top();
                _rpnStack.pop();
                float first_operand = _rpnStack.top();
                _rpnStack.pop();
                float result;
                switch (expression[i])
                {
                    case '-':
                        result = first_operand - second_operand;
                        break;
                    case '+':
                        result = first_operand + second_operand;
                        break;
                    case '*':
                        result = first_operand * second_operand;
                        break;
                    case '/':
                        result = first_operand / second_operand;
                        break;
                }
                _rpnStack.push(result);
            }
            else {
                expression_error = true;
                break ;
            }
        }
        if (isdigit(expression[i]))
            _rpnStack.push(expression[i] - '0');
    }
    if (_rpnStack.size() != 1 || expression_error)
        return 1;
    std::cout << _rpnStack.top() << std::endl;

    return 0;
}
