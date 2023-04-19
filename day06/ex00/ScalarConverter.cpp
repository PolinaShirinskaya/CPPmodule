
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:16:36 by adian             #+#    #+#             */
/*   Updated: 2023/04/18 14:32:33 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    _char   = '\0';
    _int    = 0;
    _float  = 0.0f;
    _double = 0.0;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) { *this = copy; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
    if (this == &copy)
        return *this;
    _char   = copy.getChar();
    _int    = copy.getInt();
    _float  = copy.getFloat();
    _double = copy.getDouble(); 
    return *this;
}

ScalarConverter::~ScalarConverter() {return ; }

//First step of convertion process
void    ScalarConverter::setInput( std::string input ){
    this->_input = input;
    this->setType();
    if (getType() == NOTYPE) {
        throw ScalarConverter::ConverterException();
    }
}

//Main function "CONVERT"
void    ScalarConverter::convert() {
    if (isInvalid())
        return ;
    switch (_type) {
        case CHAR:
            _char = _input[0];
            _int = static_cast< int >( _char );
            _float = static_cast< float >( _char );
            _double = static_cast< double >( _char );
            break;
        case INT:
            _int = std::stoi( _input );
            _float = static_cast< float >( _int );
            _double = static_cast< double >( _int );
            _char = static_cast< char >( _int );
            break;
        case FLOAT:
            _float = std::stof( _input );
            _int = static_cast< int >( _float );
            _double = static_cast< double >( _float );
            _char = static_cast< char >( _float );
            break;
        case DOUBLE:
            _double = std::stod( _input );
            _int = static_cast< int >( _double );
            _float = static_cast< float >( _double );
            _char = static_cast< char >( _double );
            break;
        default:
            break;
    }
}

//Methods for Define Type of Input String
void    ScalarConverter::setType() {
    if ( isChar() )
        _type = CHAR;
    else if ( isInt() )
        _type = INT;
    else if ( isFloat() )
        _type = FLOAT;
    else if ( isDouble() )
        _type = DOUBLE;
    else if ( isLiterals() )
        _type = LITERALS;
    else
        _type = NOTYPE;
}

e_type  ScalarConverter::getType() const {
    return this->_type;
}

bool    ScalarConverter::isChar() const {
    if (_input.length() == 1 &&
        std::isalpha(_input[0]) &&
        std::isprint(_input[0]))
        return true;
    else
        return false;
}

bool    ScalarConverter::isInt() const {
    int j = 0;
    if (_input[j] == '-' || _input[j] == '+')
        j++;
    for (int i(j); i < (int)_input.length(); i++) {
        if (!std::isdigit(_input[i]))
            return false;
    }
    return true;
}

bool    ScalarConverter::isFloat() const {
    if(_input.find('.') == std::string::npos ||
        _input.back() != 'f' ||
        _input.find('.') == 0 ||
        _input.find('.') == _input.length() - 2)
        return false;

    int found = 0;
    int j = 0;
    if (_input[j] == '-' || _input[j] == '+')
        j++;
    for (int i(j); i < (int)_input.length() - 1; i++) {
        if (_input[i] == '.')
            found++;
        if ((!std::isdigit(_input[i]) && _input[i] != '.')
            || found > 1)
            return false;
    }

    return true;
}

bool    ScalarConverter::isDouble() const {
    if (_input.find('.') == std::string::npos ||
        _input.find('.') == 0 ||
        _input.find('.') == _input.length() - 1)
        return false;

    int found = 0;
    int j = 0;
    if (_input[j] == '-' || _input[j] == '+')
        j++;
    for (int i(j); i < (int)_input.length(); i++) {
        if (_input[i] == '.')
            found++;
        if ((!std::isdigit(_input[i]) && _input[i] != '.')
            || found > 1)
            return false;
    }

    return true;
}

bool    ScalarConverter::isLiterals() const {
    if ((_invalid) || (_input.compare("nan") == 0) || (_input.compare("nanf") == 0)
    || ( _input.compare( "+inf" ) == 0 ) || ( _input.compare( "+inff" ) == 0 ) 
    || ( _input.compare( "-inf" ) == 0 ) || ( _input.compare( "-inff" ) == 0 ) 
    || ( _input.compare( "-inff" ) == 0 ) || ( _input.compare( "-inff" ) == 0 )  
    || ( _input.compare( "+inff" ) == 0 ) || ( _input.compare( "+inff" ) == 0 ) ) {
        return true;
    }
    return false;
}

bool    ScalarConverter::isInvalid() {
    try
    {
        if (_type == INT)
            _int = std::stoi(_input);
        else if (_type == FLOAT)
            _float = std::stof(_input);
        else if (_type == DOUBLE)
            _double = std::stod(_input);
    }
    catch(const std::exception& e)
    {
        _invalid = true;
        return true;
    }
    return false;
}

// Handlers of exceptions
char const *ScalarConverter::ConverterException::what() const throw() { return ("Error: Unknown data type!"); }
char const *ScalarConverter::InvalidAmountInputArgs::what() const throw() { return ("Usage: ./convert your_number"); }

//GETters and SETters
char    ScalarConverter::getChar() const { return this->_char; }
void    ScalarConverter::setChar(char c) { this->_char = c; }

int     ScalarConverter::getInt() const { return this->_int; }
void    ScalarConverter::setInt(int n) { this->_int = n; }

float   ScalarConverter::getFloat() const { return this->_float; }
void    ScalarConverter::setFloat(float f) { this->_float = f; }

double  ScalarConverter::getDouble() const { return this->_double; }
void    ScalarConverter::setDouble(double d) { this->_double = d; }


//Utils and methods for printing 
std::ostream    &operator<<( std::ostream &out, const ScalarConverter &output ) {
    out << "char: "; output.printChar();
    out << "int: "; output.printInt();
    out << "float: "; output.printFloat();
    out << "double: "; output.printDouble();
    return out;
}

void    ScalarConverter::printInt() const {
    if (this->isLiterals() || 
        (_int >= INT_MAX) || (_int <= INT_MIN))
            std::cout << "impossible";
    else
        std::cout << getInt();
    std::cout << std::endl;
}

void    ScalarConverter::printChar() const {
    if (this->isLiterals() || 
        ( !std::isprint(_int) && (_int >= 127))) {
            std::cout << " impossible";
    } else if ( !std::isprint(_int)) {
        std::cout << " none displayable";
    } else {
        std::cout << "'" << getChar() << "'";
    }
    std::cout << std::endl;
}

void    ScalarConverter::printFloat() const {
    if ( _input.compare( "nan" ) == 0 || _input.compare( "nanf" ) == 0 ) {
        std::cout << " nanf";
    } else if ( _input.compare( "+inff" ) == 0 || _input.compare( "+inf" ) == 0 ) {
        std::cout << " +inff";
    } else if ( _input.compare( "-inff" ) == 0 || _input.compare( "-inf" ) == 0 ) {
        std::cout << " -inff";
    } else if ( _invalid ) {
        std::cout << " impossible";
    } else {
        if ( _float - static_cast< int > ( _float ) == 0 ) {
            std::cout << _float << ".0f";
        } else {
            std::cout << getFloat() << "f";
        }
    }
    std::cout << std::endl;
}

void    ScalarConverter::printDouble() const {
    if ( _input.compare( "nan" ) == 0 || _input.compare( "nanf" ) == 0 ) {
        std::cout << " nan";
    } else if ( _input.compare( "+inff" ) == 0 || _input.compare( "+inf" ) == 0 ) {
        std::cout << " +inf";
    } else if ( _input.compare( "-inff" ) == 0 || _input.compare( "-inf" ) == 0 ) {
        std::cout << " -inf";
    } else if ( _invalid ) {
        std::cout << " impossible";
    } else {
        if ( _double - static_cast< int > ( _double ) == 0 ) {
            std::cout << _double << ".0";
        } else {
            std::cout << getDouble() << "f";
        }
    }
    std::cout << std::endl;
}