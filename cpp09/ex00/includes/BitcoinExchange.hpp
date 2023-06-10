/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:34:10 by codespace         #+#    #+#             */
/*   Updated: 2023/05/22 18:19:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>

class BitcoinExchange {
  private:
    static std::map<std::string, std::string> bitcoin_data;

    static void testData(const char *input_data, const char *csv_file);
    static bool isLeapYear(int year);
    static int parseBitcoinInputValue(std::string str);
    static std::string adjustDate(std::string date, std::string first_date);
    static int parseDate(std::string str);
    
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange & operator =(const BitcoinExchange &rhs);
    ~BitcoinExchange();
  public:
    static void ExchangeValue(const char *input_data, const char *csv_file);
};

#endif
