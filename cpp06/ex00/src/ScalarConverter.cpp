/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:53:48 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/25 21:54:26 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int ScalarConverter::parseStringAsInt(std::string str) {

    bool has_minus = false;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[0] == '-' && !has_minus) {
            has_minus = true;
            continue;
        }
        if (!isdigit(str[i])) {
            return 1;
        }
    }
    return 0;
}

int ScalarConverter::parseStringAsFloat(std::string str) {
    
    bool point = false;
    bool has_minus = false;

    if (str[str.length() - 1] != 'f')
        return 1;
    for (size_t i = 0; i < str.length() - 1; i++) {
        if (str[0] == '-' && !has_minus) {
            has_minus = true;
            continue;
        }
        if (str[i] == '.') {
            if (point == true) 
                return 1;
            point = true;
        }
        if (!isdigit(str[i]) && str[i] != '.') {
            return 1;
        }
    }
    return 0;
}

int ScalarConverter::parseStringAsDouble(std::string str) {
    bool point = false;
    bool has_minus = false;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[0] == '-' && !has_minus) {
            has_minus = true;
            continue;
        }
        if (str[i] == '.') {
            if (point == true) 
                return 1;
            point = true;
        }
        if (!isdigit(str[i]) && str[i] != '.') {
            return 1;
        }
    }
    return 0;
}

void ScalarConverter::converter(std::string literal) {
    if (literal.empty()) {
        throw std::exception();
        return ;   
    }
	if (literal.length() == 1 && isprint(literal.at(0)))
		converter(literal.at(0));
	else if (literal.compare("nanf") == 0)
		converter(std::numeric_limits<float>::quiet_NaN());
	else if (literal.compare("nan") == 0)
		converter(std::numeric_limits<double>::quiet_NaN());
	else if (literal.compare("inff") == 0 || literal.compare("+inff") == 0)
		converter(std::numeric_limits<float>::infinity());
	else if (literal.compare("inf") == 0 || literal.compare("+inf") == 0)
		converter(std::numeric_limits<double>::infinity());
	else if (literal.compare("-inff") == 0)
		converter(-std::numeric_limits<float>::infinity());
	else if (literal.compare("-inf") == 0)
		converter(-std::numeric_limits<double>::infinity());
	else
	{
		ScalarConverter::_type = INT;

		for (std::string::iterator input = literal.begin(); input != literal.end(); input++)
		{
			if (input == literal.begin() && *input == '-')
				continue ;
			else if (isdigit(*input))
				continue ;
			else if (*input == '.' && isdigit(*(input + 1)) && ScalarConverter::_type == INT)
				ScalarConverter::_type = DOUBLE;
			else if (*input == 'f' && input == literal.end() - 1 && ScalarConverter::_type == DOUBLE)
				ScalarConverter::_type = FLOAT;
			else if (ScalarConverter::_type == FLOAT)
				break ;
		}
		if (ScalarConverter::_type == INT) {
            if (parseStringAsInt(literal)) {
                std::cout << "Error!" << std::endl;
                std::cout << "Wrong input" << std::endl;
                return ;
            }
			converter(atoi(literal.c_str()));
        }
		else if (ScalarConverter::_type == FLOAT) 
		{
            if (parseStringAsFloat(literal)) {
                std::cout << "Error!" << std::endl;
                std::cout << "Wrong input" << std::endl;
                return ;
            }
			const char *str = literal.c_str();
			char *end;
			converter(strtof(str, &end));
		}
		else if (ScalarConverter::_type == DOUBLE) {
            if (parseStringAsDouble(literal)) {
                std::cout << "Error!" << std::endl;
                std::cout << "Wrong input" << std::endl;
                return ;
            }
			converter(atof(literal.c_str()));
        }
	}
}

void ScalarConverter::converter(char c) {
	std::cout << "\e[33a\033[0;33mConverting character\e[0m" << std::endl;

    std::cout << "char:\t\t" << c << std::endl;
	std::cout << "int:\t\t" << static_cast<int>(c) << std::endl;
	std::cout << "float:\t\t" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double:\t\t" << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::converter(int i) {
	std::cout << "\e[33a\033[0;33mConverting interger\e[0m" << std::endl;

    if (i >= 0 && i <= 127 && isprint(i))
		std::cout << "char:\t\t" << static_cast<char>(i) << std::endl;
	else if (i >= 0 && i <= 127)
		std::cout << "char:\t\t" << "Non displayable" << std::endl;
	else
		std::cout << "char:\t\t" << "impossible" << std::endl;
	std::cout << "int:\t\t" << i << std::endl;
	std::cout << "float:\t\t" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double:\t\t" << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::converter(float f) {
     std::cout << "\e[33a\033[0;33mConverting float\e[0m" << std::endl;

    if (std::isfinite(f) && f >= 0 && f <= 127 && isprint(f)) {
        std::cout << "char:\t\t" << static_cast<char>(f) << std::endl;
    } else if (f >= 0 && f <= 127) {
        std::cout << "char:\t\tNon displayable" << std::endl;
    } else {
        std::cout << "char:\t\timpossible" << std::endl;
    }

    if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min()) {
        std::cout << "int:\t\t" << static_cast<int>(f) << std::endl;
    } else {
        std::cout << "int:\t\timpossible" << std::endl;
    }

    float testf = f - static_cast<int>(f);
    if (testf == 0.0f) {
        std::cout << "float:\t\t" << f << ".0f" << std::endl;
        std::cout << "double:\t\t" << static_cast<double>(f) << ".0" << std::endl;
    } else {
        std::cout << "float:\t\t" << f << "f" << std::endl;
        std::cout << "double:\t\t" << static_cast<double>(f) << std::endl;
    }
}

void ScalarConverter::converter(double d) {
     std::cout << "\e[33a\033[0;33mConverting double\e[0m" << std::endl;

    if (std::isprint(static_cast<char>(d))) {
        std::cout << "char:\t\t" << static_cast<char>(d) << std::endl;
    } else if (d >= 0 && d <= 127) {
        std::cout << "char:\t\tNon displayable" << std::endl;
    } else {
        std::cout << "char:\t\timpossible" << std::endl;
    }

    if (d <= static_cast<double>(std::numeric_limits<int>::max()) && d >= static_cast<double>(std::numeric_limits<int>::min())) {
        std::cout << "int:\t\t" << static_cast<int>(d) << std::endl;
    } else {
        std::cout << "int:\t\timpossible" << std::endl;
    }

    double testd = d - static_cast<long long>(d);
    if (testd == 0.0) {
        std::cout << "float:\t\t" << static_cast<float>(d) << ".0f" << std::endl;
        std::cout << "double:\t\t" << d << ".0" << std::endl;
    } else {
        std::cout << "float:\t\t" << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double:\t\t" << d << std::endl;
    }
}

t_type ScalarConverter::_type = UNDEFINED;
