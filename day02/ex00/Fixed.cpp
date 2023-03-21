/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:22:14 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 12:32:51 by adian            ###   ########.fr       */
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

// returns the raw value of the fixed-point value.
int     Fixed::getRawBits() const
{
    std::cout
        << "getRawBits member function called"
        << std::endl;
    return (this->_fixPoint);
}

// sets the raw value of the fixed-point number
void    Fixed::setRawBits(const int raw)
{
    this->_fixPoint = raw;
    return ;
}