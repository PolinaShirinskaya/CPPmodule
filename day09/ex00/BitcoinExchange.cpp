/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:32:46 by adian             #+#    #+#             */
/*   Updated: 2023/05/24 17:35:09 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidDateFormat(const std::string &date) {
    if (date.length() != 11)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;

        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    return true;
}

double findRate(std::string date, std::map<std::string, double> data) {
    std::map<std::string, double>::iterator it = data.lower_bound(date);
    if (date != it->first) {
        --it;
    }
    return it->second;
}

void processInput(std::string file, std::map<std::string, double> data) {
    
    std::ifstream inputFile(file);
    if (!inputFile) {
        std::cerr << "Error: Fail open " << file << " file." << std::endl;
        exit (1);
    }

    std::string line;

    //check first line, it must be in 'data | value' format
    std::getline(inputFile, line);
    if (line != "date | value") {
        std::cerr << "Error: First line of " << file << " isn't in the 'date | value' format." << std::endl;
        exit (1);
    }

    //check other lines of input.txt
    while (std::getline(inputFile, line)) {
        size_t separartorPos = line.find('|');
        if (separartorPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << " (missing separator)" <<std::endl;
            continue ;
        }

        std::string date = line.substr(0, separartorPos);
        std::string value = line.substr(separartorPos + 1);

        //check valid of DATE
        if (!isValidDateFormat(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }

        //check valid of VALUE
        double numValue = std::stod(value);
		if (numValue < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (numValue > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

        //process with valid lines
        if (numValue < 1000 && numValue > 0) {
            double res = numValue * findRate(date, data);
            std::cout << date << " => " << value << " = " << res << std::endl;
        }
    }
    inputFile.close();
}

std::map<std::string, double> processData() 
{
    std::map<std::string, double> data;

    std::ifstream file("data.csv");
    if (!file) {
        std::cerr << "Error: Fail open data.csv file." << std::endl;
        exit (1);
    }

    //making map from file
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);

        std::string date, rate;
        if (std::getline(ss, date, ',') && std::getline(ss, rate)) {
            data[date] = std::stod(rate);
        }
    }
    return data;
}
