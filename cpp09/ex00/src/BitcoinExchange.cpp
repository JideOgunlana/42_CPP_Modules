/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:18:04 by codespace         #+#    #+#             */
/*   Updated: 2023/05/28 18:32:02 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/* 
 * Reference to static member attribute bitcoin_data
 */
std::map<std::string, std::string> BitcoinExchange::bitcoin_data;

/* 
 * public function ExchangeValue used from main
 */
void BitcoinExchange::ExchangeValue(const char *data_input, const char *csv_file) {
   BitcoinExchange::testData(data_input, csv_file);
}

/* 
 * isLeapYear checks the year passed is a leap
 */
bool BitcoinExchange::isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
        }
        else {
            return true;
        }
    }
    return false;
}

/* 
 * Checks if the value entered in the input.txt file is a valid bitcoin value
 */
int BitcoinExchange::parseBitcoinInputValue(std::string str) {
    
    bool point = false;

    for (size_t i = 0; i < str.length(); i++) {
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

/* 
 * Checks if the date entered in the input.txt file is a valid date
 */
int BitcoinExchange::parseDate(std::string str) {

    int dash_cout = 0;

    if (str[0] == '0')
        return 1;
    for (size_t i  = 0; i < str.length(); i++) {
        if (str[i] == '-') {
            if (str[i + 1] == '0' && str[i + 2] == '0') {
                return 1;
            }
            if (str[i + 1] != '0' && isdigit(str[i + 1]) && (str[i + 2] == '-' || str[i + 2] == '\0')) {
                return 1;
            }
            dash_cout++;
        }
        if (!isdigit(str[i]) && str[i] != '-') {
            return 1;
        }
    }
    if (dash_cout != 2)
        return 1;
    return 0;
}


/* 
 * Returns the date closest to date entered in the input.txt file when this date is not available in the csv file
 */
std::string BitcoinExchange::adjustDate(std::string date, std::string first_date) {

    size_t delimiter_pos = date.find("-");
    size_t first_delimiter_pos = first_date.find("-");

    if (delimiter_pos != std::string::npos) {
        std::string year = date.substr(0, delimiter_pos);
        std::string first_year = first_date.substr(0, first_delimiter_pos);

        std::string split_date = date.substr(delimiter_pos + 1);
        std::string split_first_date = first_date.substr(first_delimiter_pos + 1);

        delimiter_pos = split_date.find("-");
        first_delimiter_pos = split_first_date.find("-");

        if (delimiter_pos != std::string::npos) {
            std::string month = split_date.substr(0, delimiter_pos);
            std::string day = split_date.substr(delimiter_pos + 1);

            std::string first_month = split_first_date.substr(0, first_delimiter_pos);
            std::string first_day = split_first_date.substr(first_delimiter_pos + 1);
        

            int year_as_int = static_cast<int>(atoi(year.c_str()));
            int month_as_int = static_cast<int>(atoi(month.c_str()));
            int day_as_int = static_cast<int>(atoi(day.c_str()));

            int first_year_as_int = static_cast<int>(atoi(first_year.c_str()));
            int first_month_as_int = static_cast<int>(atoi(first_month.c_str()));
            int first_day_as_int = static_cast<int>(atoi(first_day.c_str()));

            std::string tmp_day = "";
            std::string tmp_month = "";
            std::string tmp_year = "";

            if (month_as_int < 1 || month_as_int > 12 || day_as_int < 1 || day_as_int > 31 || \
                year_as_int < first_year_as_int || (day_as_int < first_day_as_int && month_as_int == first_month_as_int &&  year_as_int == first_year_as_int) || \
                (month_as_int < first_month_as_int && year_as_int == first_month_as_int) || \
                (month_as_int == 2 && isLeapYear(year_as_int) && day_as_int > 29) || \
                (month_as_int == 2 && !isLeapYear(year_as_int) && day_as_int > 28) ||
                ((month_as_int == 1 || month_as_int == 3 || month_as_int == 5 || month_as_int == 7 || month_as_int == 8 || month_as_int == 10 || month_as_int == 12) && day_as_int > 31) || \
                ((month_as_int == 4 || month_as_int == 6 || month_as_int == 9 || month_as_int == 11) && day_as_int > 30) 
            ){
                std::cout << "Error in Date: " << date << std::endl;
                return "error";
            }

            day_as_int--;
            if (day_as_int == 0) {
                month_as_int--;
                if (month_as_int < 1)
                    month_as_int = 12;
            }
            if (month_as_int == 12 && day_as_int == 0) {
                year_as_int--;
            }
            if (month_as_int == 2 && day_as_int == 0) {
                if (isLeapYear(year_as_int)) {
                    day_as_int = 29;
                }
                else
                    day_as_int = 28;
            }
            if ( (month_as_int == 1 || month_as_int == 3 || \
                month_as_int == 5 || month_as_int == 7 || \
                month_as_int == 8 || month_as_int == 10 || \
                month_as_int == 12 ) && day_as_int == 0
                ) {
                day_as_int = 31;
            }
            else if ( (month_as_int == 4 || month_as_int == 6 || \
             month_as_int == 9 || month_as_int == 11 ) && day_as_int == 0
            ) {
                day_as_int = 30;
            }

            std::stringstream ss;
            ss << day_as_int;
            if (day_as_int < 10)
                tmp_day = "0" + ss.str();
            else
                tmp_day = ss.str();

            ss.str("");
            ss << month_as_int;
            if (month_as_int < 10)
                tmp_month = "0" + ss.str();
            else
                tmp_month = ss.str();

            ss.str("");
            ss << year_as_int;
            tmp_year = ss.str();

            date = tmp_year + "-" + tmp_month + "-" + tmp_day;
        }
    }

    return date;
}

/* 
 * Checks for a valid date and bitcoin value, and outputs corresponding exchange
 */
void BitcoinExchange::testData(const char *input_data, const char *csv_file) {

    std::string line;
    std::ifstream input;
    std::string first_date = "";
    bool csv_is_valid = false;
    bool first_date_set = false;

    input.open(csv_file);
    if (!input) {
        input.close();
        return;
    }

    while (!input.eof()) {
        std::getline(input, line);
        size_t delimter_pos = line.find(",");
        if (delimter_pos != std::string::npos) {
            csv_is_valid = true;
            std::string csv_date = line.substr(0, delimter_pos);
            std::string csv_exchange_rate = line.substr(delimter_pos + 1);
            if (csv_date != "date" || csv_exchange_rate != "exchange_rate") {
                if (first_date_set == false) {
                    first_date = csv_date;
                    first_date_set = true;
                }
                bitcoin_data.insert(std::make_pair(csv_date, csv_exchange_rate));
            }
        }
        else if (!csv_is_valid) {
            std::cout << "Error in csv file" << std::endl;
            input.close();
            return;
        }
    }
    input.close();

    input.open(input_data);
    if (!input) {
        std::cout << "Error!\nCould not open file: " << input_data << std::endl; 
        return ;
    }
    while (!input.eof()) {
        std::getline(input, line);
        size_t delimeter_pos = line.find("|");
        if (delimeter_pos != std::string::npos) {
            std::string input_txt_date = line.substr(0, delimeter_pos - 1);
            std::string input_value = line.substr(delimeter_pos + 2);
            if (input_txt_date != "date") {
                if (parseDate(input_txt_date) != 0) {
                    std::cout << "Error! Invalid Date: " << input_txt_date << std::endl;
                }
                else {
                    char *bc_input;
                    float bitcoin_value = static_cast<float>(strtof(input_value.c_str(), &bc_input));
                    if (bitcoin_value < 0 || bitcoin_value > 1000) {
                        std::cout << "Error! Invalid bitcoin value: " << input_value << std::endl;
                    }
                    else if (input_value.length() == 0 || parseBitcoinInputValue(input_value) != 0) {
                        std::cout << "Error! invalid bitcoin value: " << input_value << std::endl;
                    }
                    else if (bitcoin_data.count(input_txt_date)) {
                        const char *str = bitcoin_data[input_txt_date].c_str();
                        char *end;
                        float curr_bitcoin_rate = static_cast<float>(strtof(str, &end));
                        std::cout << input_txt_date << " => " << input_value << " = " << curr_bitcoin_rate * bitcoin_value << std::endl;
                    }
                    else {
                        std::string actual_date = input_txt_date;
                        input_txt_date = adjustDate(input_txt_date, first_date);
                        while (input_txt_date != "error") {
                            if (bitcoin_data.count(input_txt_date)) {
                                const char *str = bitcoin_data[input_txt_date].c_str();
                                char *end;
                                float curr_bitcoin_rate = static_cast<float>(strtof(str, &end));
                                std::cout << actual_date << " => " << input_value << " = " << curr_bitcoin_rate * bitcoin_value << std::endl;
                                break ;
                            }
                            input_txt_date = adjustDate(input_txt_date, first_date);
                        }
                    }
                }
            }
        }
        else {
            std::cout << "Error! Not valid: " << line << std::endl;
        }
    }
    input.close();
}
