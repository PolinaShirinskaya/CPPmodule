/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:10:06 by adian             #+#    #+#             */
/*   Updated: 2023/03/26 19:10:32 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout
        << CYAN
        << "[WrongCat] Default constructor called"
        << NORMAL << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout
        << CYAN
        << "[WrongCat] Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
    std::cout
        << CYAN
        << "[WrongCat] Copy assignment constructor called"
        << NORMAL << std::endl;
    _type = copy.getType();
    return (*this);
}

WrongCat::~WrongCat()
{
std::cout
        << CYAN
        << "[WrongCat] Destructor called"
        << NORMAL << std::endl;
}

void    WrongCat::makeSound() const  
{
    std::cout
        << "MEOW MEOW"
        << std::endl;
}