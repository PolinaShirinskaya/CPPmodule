/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:59:14 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 18:14:52 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBit = 8;

Fixed::Fixed() { _fixPoint = 0; }

Fixed::Fixed(const int intNum) { this->_fixPoint = intNum * ( 1 << this->_fracBit); }

Fixed::Fixed(const float floatNum) { this->_fixPoint = (int)(roundf(floatNum * ( 1 << this->_fracBit))); }

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
    return ;
}

Fixed&  Fixed::operator=(const Fixed &copy)
{
    setRawBits(copy.getRawBits());
    return (*this); 
}

/**
 ** Comparison Operations: > < >= <= == !=
 **/
bool	Fixed::operator==(const Fixed &fixed) const { return (this->_fixPoint == fixed.getRawBits()); }

bool	Fixed::operator!=(const Fixed &fixed) const { return (this->_fixPoint != fixed.getRawBits()); }

bool	Fixed::operator<=(const Fixed &fixed) const { return (this->_fixPoint <= fixed.getRawBits()); }

bool	Fixed::operator>=(const Fixed &fixed) const { return (this->_fixPoint >= fixed.getRawBits()); }

bool	Fixed::operator<(const Fixed &fixed) const { return (this->_fixPoint < fixed.getRawBits()); }

bool	Fixed::operator>(const Fixed &fixed) const { return (this->_fixPoint > fixed.getRawBits()); }



/**
 ** Arithmetic Operations: + - * /
 **/

Fixed	Fixed::operator + (Fixed const &fixed) const
{
	Fixed	res;

	res.setRawBits(this->_fixPoint + fixed.getRawBits());
	return (res);
}

Fixed	Fixed::operator - (Fixed const &fixed) const
{
	Fixed	res;

	res.setRawBits(this->_fixPoint - fixed.getRawBits());
	return (res);
}

Fixed	Fixed::operator * (Fixed const &fixed) const
{
	Fixed	res;

	res = Fixed(this->toFloat() * fixed.toFloat());
	return (res);
}

Fixed	Fixed::operator / (Fixed const &fixed) const
{
	Fixed	res;

	res = Fixed(this->toFloat() / fixed.toFloat());
	return (res);
}


/**
 ** Increment / Decrement operators: ++a a++ --a a++
 **/
Fixed	Fixed::operator ++ ()
{
	this->_fixPoint += 1;
	return (*this);
}

Fixed	Fixed::operator -- ()
{
	this->_fixPoint -= 1;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	prev(*this);

	this->_fixPoint += 1;
	return (prev);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	prev(*this);

	this->_fixPoint -= 1;
	return (prev);
}


/**
 ** Return the min/max fixed point of the given two
 **/
Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

Fixed const	&Fixed::min(Fixed const &f1, Fixed const &f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed const	&Fixed::max(Fixed const &f1, Fixed const &f2)
{
	return (f1 > f2 ? f1 : f2);
}



// overload STDOUT operator
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