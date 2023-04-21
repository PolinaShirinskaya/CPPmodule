/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:39:00 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 12:55:06 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::_hasQuote = false;
inputType ScalarConverter::_inputType = normal;

ScalarConverter::ScalarConverter(void) {
    std::cout << "Default constructor is called" << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
    std::cout << "Destrutor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
    std::cout << "Copy constructor is called" << std::endl;
    *this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & copy) {
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)copy;
    return (*this);
}

bool    ScalarConverter::convertAll(const std::string &input) {
    try {
        ScalarConverter::parseProcess(input);
    } catch (std::exception & e) {}
    ScalarConverter::printChar(input);
    ScalarConverter::printInt(input);
    ScalarConverter::printFloat(input);
    ScalarConverter::printDouble(input);
   return (true);
}

bool    ScalarConverter::parseProcess(const std::string &input) {
    ScalarConverter::checkInfinity(input);
    if (_inputType != normal)
        return true;

    size_t found = input.find_last_of("+-");
    if (found != std::string::npos && found != 0 && input[found - 1] != 'e')
        throw ScalarConverter::DataIsNotDigit();

    found = input.find('f');
    if (found != std::string::npos && found != input.length() - 1)
        throw ScalarConverter::DataIsNotDigit();

    ScalarConverter::checkQuote(input);
    ScalarConverter::checkExponent(input);

    found = input.find_first_not_of("0123456789eE.+-f");
    if (found != std::string::npos)
        throw ScalarConverter::DataIsNotDigit();

    return true;
}

//function try to find +/- INF or NAN
void    ScalarConverter::checkInfinity(const std::string &input) {
    const std::string inputTypes[2][3] = {{"-inf", "+inf", "nan"},
                                        {"-inff", "+inff", "nanf"}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (input == inputTypes[i][j])
                ScalarConverter::_inputType = static_cast<inputType>(j + 1);
        }
    }
}

bool    ScalarConverter::checkQuote(const std::string & input) {
    size_t foundFirst = input.find('\'');
    if (foundFirst == std::string::npos)
        return (ScalarConverter::_hasQuote);
    size_t foundSecond = input.find('\'', foundFirst + 1);
    
    if (foundFirst != 0 || foundSecond != input.length() - 1)
            throw ScalarConverter::OpenQuotes();
    return (ScalarConverter::_hasQuote);
}

bool    ScalarConverter::checkExponent(const std::string & input) {
    bool foundExponent = false;
    const std::string exponentVar = "eE";
    const std::string charVars = "0123456789+-";

    for (size_t i = 0; i < exponentVar.length(); i++) {
        size_t foundFirst = input.find_first_of(exponentVar[i]);
        size_t foundLast = input.find_last_of(exponentVar[i]);
        if (charVars.find(input[foundLast+ + 1]) == std::string::npos
                || foundFirst != foundLast)
            throw ScalarConverter::DataIsNotDigit();
        if (foundExponent == true && foundLast != std::string::npos)
            throw ScalarConverter::DataIsNotDigit();
        if (foundLast != std::string::npos)
            foundExponent = true;
    }
    return (true);
}


//function for convert and print CHAR
bool    ScalarConverter::printChar(const std::string & input) {
    try {
        std::cout << "char: ";
        char c = ScalarConverter::convertToChar(input);
        std::cout << "'" << c << "'" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

char    ScalarConverter::convertToChar(const std::string & input) {
    char ret;

    if (ScalarConverter::_inputType != normal)
        throw ScalarConverter::ImpossiblePrint();

    std::string cleanedInput = input; 
    if (ScalarConverter::_hasQuote) {
        cleanedInput = input.substr(1, input.length() - 2);
        if (cleanedInput.length() != 1)
            throw InvalidChar();
        return (cleanedInput[0]);
    }
        
    try {
        ret = static_cast<char>(ScalarConverter::convertToInt(cleanedInput));
    }
    catch (std::exception & e) {
        throw ScalarConverter::InvalidChar();
    }
    if (!std::isprint(ret))
        throw ScalarConverter::NonPrintableChar();
    return (ret);
}

//function for convert and print INT
bool    ScalarConverter::printInt(const std::string & input) {
    try {
        std::cout << "int: ";
        std::cout << ScalarConverter::convertToInt(input) << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

int     ScalarConverter::convertToInt(const std::string & input) {
    size_t      findDot;
    long        num;

    if (ScalarConverter::_inputType != normal)
        throw ScalarConverter::ImpossiblePrint();

    std::string cleanedInput = input; 
    if (ScalarConverter::_hasQuote)
        cleanedInput = input.substr(1, input.length() - 2);
        
    ScalarConverter::parseProcess(cleanedInput);

    findDot = cleanedInput.find(".");
    if (findDot == std::string::npos) {
        if (input.length() > 11)
            throw ScalarConverter::NumberOutsideRange();
    }
    else if (findDot > 11)
        throw ScalarConverter::NumberOutsideRange();

    num = atol(cleanedInput.c_str());
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        throw ScalarConverter::NumberOutsideRange();
    return (static_cast<int>(num));
}

//function for convert and print FLOAT
bool    ScalarConverter::printFloat(const std::string & input) {
    try {
        std::cout << "float: ";
        double num = ScalarConverter::convertToFloat(input);
        std::cout << num;
        if (num == static_cast<int>(num))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true); 
}

float   ScalarConverter::convertToFloat(const std::string & input) {
    double num = convertToDouble(input);
    if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
        throw ScalarConverter::NumberOutsideRange();
    return (static_cast<float>(num));
}

//function for convert and print DOUBLE

bool    ScalarConverter::printDouble(const std::string & input) {
    try {
        std::cout << "double: ";
        double num = ScalarConverter::convertToDouble(input);
        std::cout << num;
        if (num == static_cast<int>(num))
            std::cout << ".0";
        std::cout << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

double  ScalarConverter::convertToDouble(const std::string & input) {
    std::string cleanedInput = input; 
    if (ScalarConverter::_hasQuote)
        cleanedInput = input.substr(1, input.length() - 2);
        
    ScalarConverter::parseProcess(cleanedInput);
    errno = 0;
    double ret = std::strtod(input.c_str(), NULL);
    if (errno)
        throw ScalarConverter::NumberOutsideRange();

    return (ret);
}

const char * ScalarConverter::DataIsNotDigit::what( void ) const throw() {
    return ("Input Data isn't a digit");   
}

const char * ScalarConverter::ImpossiblePrint::what( void ) const throw() {
    return ("Impossible");   
}

const char * ScalarConverter::NonPrintableChar::what( void ) const throw() {
    return ("Non displayable");   
}

const char * ScalarConverter::OpenQuotes::what( void ) const throw() {
    return ("Input has open quotes");   
}

const char * ScalarConverter::InvalidChar::what( void ) const throw() {
    return ("Invalid character");   
}

const char * ScalarConverter::NumberOutsideRange::what( void ) const throw() {
    return ("Outside the range");   
}