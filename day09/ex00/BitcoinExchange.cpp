/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:32:46 by adian             #+#    #+#             */
/*   Updated: 2023/05/22 21:08:30 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void parceInput(std::string inputFile) {
    
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << "Error: Fail open " << inputFile << " file." << std::endl;
        exit (1);
    }

    //check first line, it must be in 'data | value' format
    std::string firstLine;
    std::getline(file, firstLine);
    std::cout << "FirstLine: " << firstLine << std::endl;
    if (firstLine != "date | value") {
        std::cerr << "Error: First line of " << inputFile << " isn't in the 'date | value' format." << std::endl;
        exit (1);
    }

    //check other lines of input.txt
    std::string nextLine;
    while (std::getline(file, nextLine)) {
        std::cout << "NextLine: " << nextLine << std::endl;
        std::istringstream ss(nextLine);

        long yearValue = std::stol(nextLine.substr(0, 4));
        long monthValue = std::stol(nextLine.substr(5, 2));
        long dayValue = std::stol(nextLine.substr(8, 2));
        long valueValue = std::stol(nextLine.substr(13, (nextLine.size() - 13)));

        std::cout << "Year: " << yearValue << std::endl;
        std::cout << "Month: " << monthValue << std::endl;
        std::cout << "Day: " << dayValue << std::endl;
        std::cout << "Value: " << valueValue << std::endl;

    }
}

/*std::map<std::string, double> readData() 
{
    std::map<std::string, double> data;

    std::ifstream file("data.csv");
    if (!file) {
        std::cerr << "Error: Fail open data.csv file." << std::endl;
        exit (1);
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);

        std::string date, rate;
        if (std::getline(ss, date, ',') && std::getline(ss, rate)) {
            data[date] = std::stod(rate);
        }
    }

    std::map<std::string, double>::iterator it = data.begin();
    // Iterate through the map and print the elements
    //while (it != data.end())
    int i = 0;
    while (i <= 5)
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
        i++;
    }
    return data;
}

void parceData(std::string file, std::map<std::string, double> data) {
    
    std::ifstream inputFile(file);
    if (!inputFile) {
        std::cerr << "Error: Fail open " << file << " file." << std::endl;
        exit (1);
    }

    //check first line, it must be in 'data | value' format
    std::string firstLine;
    std::getline(inputFile, firstLine);
    std::cout << "FirstLine: " << firstLine << std::endl;
    if (firstLine != "date | value") {
        std::cerr << "Error: First line of " << file << " isn't in the 'date | value' format." << std::endl;
        exit (1);
    }

    //check other lines of input.txt
    std::string nextLine;
    while (std::getline(inputFile, nextLine)) {
        std::cout << "NextLine: " << nextLine << std::endl;
        std::istringstream ss(nextLine);

        std::string key = data.begin()->first;

        long yearValue = std::stol(key.substr(0, 4));
        long monthValue = std::stol(key.substr(5, 2));
        long dayValue = std::stol(key.substr(8, 2));

        std::cout << "Year: " << yearValue << std::endl;
        std::cout << "Month: " << monthValue << std::endl;
        std::cout << "Day: " << dayValue << std::endl;


    }
    inputFile.close();
}*/
