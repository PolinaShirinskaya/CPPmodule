/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:59:14 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 15:45:34 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBit = 8;

Fixed::Fixed()
{
    std::cout
        <<"Default_constructor called"
        << std::endl;
    _fixPoint = 0;
    return ;
}

Fixed::Fixed(const int intNum)
{
    std::cout
        <<"INT_constructor called"
        << std::endl;
    this->_fixPoint = intNum * ( 1 << this->_fracBit);
    return ;
}

Fixed::Fixed(const float floatNum)
{
    std::cout
        <<"FLOAT_constructor called"
        << std::endl;
    this->_fixPoint = (int)(roundf(floatNum * ( 1 << this->_fracBit)));
    return ;
}

Fixed::~Fixed()
{
    std::cout
        << "Destructor called"
        << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout
        <<"Copy_constructor called"
        << std::endl;
    *this = copy;
    return ;
}

Fixed   &Fixed::operator=(const Fixed &copy)
{
    std::cout
        << "Copy_assignment operator called"
        << std::endl;
    setRawBits(copy.getRawBits());
    return (*this);
    
    
}

// output the Fixed Point Number on the stdout
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

// converts the fixed-point value to an integer value
float Fixed::toFloat(void) const
{
    return ((float)this->_fixPoint / (float)(1 << this->_fracBit));
}

// return only the int part of the fixed point number
int Fixed::toInt(void) const
{
    return (this->_fixPoint >> this->_fracBit);
}

// returns the raw value of the fixed-point value.
int     Fixed::getRawBits() const { return (this->_fixPoint); }

// sets the raw value of the fixed-point number
void    Fixed::setRawBits(const int raw) { this->_fixPoint = raw; }