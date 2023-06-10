/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:34:12 by codespace         #+#    #+#             */
/*   Updated: 2023/05/28 16:49:17 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "Error!\nPass an input file" << std::endl;
        return (1);
    }

    const char *csv_file = "data.csv";
    std::ifstream data_csv;
    data_csv.open(csv_file);

    if (!data_csv) {
        std::cout << "Error!\nPlace file: data.csv in the directory ex00" << std::endl;
        return 1;
    }
    data_csv.close();
    BitcoinExchange::ExchangeValue(argv[1], "data.csv");

    return 0;
}
