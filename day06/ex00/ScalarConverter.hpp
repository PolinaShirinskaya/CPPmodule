/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:09:13 by adian             #+#    #+#             */
/*   Updated: 2023/04/18 19:04:06 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

enum e_type {
    NOTYPE,
    INT,
    FLOAT, 
    DOUBLE,
    CHAR,
    LITERALS
};

class ScalarConverter
{
    private:
        char        _char;
        int         _int;
        float       _float;
        double      _double;

        bool        _invalid;
        
        std::string _input;
        e_type      _type;


    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &copy);
        ScalarConverter &operator=(ScalarConverter const &copy);
        ~ScalarConverter();

        //Main method for our exercise
        void    convert();

        //GETters and SETters
        char    getChar() const;
        void    setChar(char c);

        int     getInt() const;
        void    setInt(int n);

        float   getFloat() const;
        void    setFloat(float f);

        double  getDouble() const;
        void    setDouble(double d);

        std::string     getInput() const;
        void            setInput( std::string input );

        e_type   getType() const;
        void     setType();

        //Methods for Define Type of Input String
        bool    isInt() const;
        bool    isChar() const;
        bool    isFloat() const;
        bool    isDouble() const;
        bool    isLiterals() const;

        bool    isInvalid();

        //Exceptions
        class ConverterException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class InvalidAmountInputArgs : public std::exception
        {
            virtual const char *what() const throw();
        };


        //Methods for printintig output infornation
        void    printChar() const;
        void    printInt() const;
        void    printFloat() const;
        void    printDouble() const;
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &output);

#endif