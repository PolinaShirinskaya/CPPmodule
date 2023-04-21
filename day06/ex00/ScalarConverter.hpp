/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:13 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 12:47:00 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>

enum inputType {
    normal, //int char float double
    negInf, //-inf -inff
    posInf, //+inf +inff
    nan     //nan
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter & copy);
        ~ScalarConverter();
        ScalarConverter & operator=(const ScalarConverter & copy);

        static  inputType       _inputType;
        static  bool            _hasQuote;

        static  void    checkInfinity(const std::string &input);
        static  bool    checkExponent(const std::string & input);
        static  bool    checkQuote(const std::string & input);
        static  bool    parseProcess(const std::string &input);

    public:
        static  char    convertToChar(const std::string & input);
        static  int     convertToInt(const std::string & input);
        static  float   convertToFloat(const std::string & input);
        static  double  convertToDouble(const std::string & input);

        static  bool    printChar(const std::string & input);
        static  bool    printInt(const std::string & input);
        static  bool    printFloat(const std::string & input);
        static  bool    printDouble(const std::string & input);
        static  bool    convertAll(const std::string & input);


        class  DataIsNotDigit: public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  ImpossiblePrint: public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  NonPrintableChar : public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  OpenQuotes : public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  InvalidChar: public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  NumberOutsideRange : public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };
};

#endif