/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:12:24 by codespace         #+#    #+#             */
/*   Updated: 2023/05/27 21:09:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <cctype>
# include <cstdio>
# include <sstream>

class RPN {
    private:
        RPN();
        RPN(const RPN &src);
        ~RPN();
        RPN & operator =(const RPN &rhs);

        static std::stack<float> _rpnStack;
        static bool isWhiteSpace(char c);
        static std::string trimString(const std::string &str);
        static bool expressionIsValid(const std::string &str);
    public:
        static float RPNCalculator(char *str);
};


#endif
