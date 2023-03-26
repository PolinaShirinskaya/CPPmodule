/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:05:32 by adian             #+#    #+#             */
/*   Updated: 2023/03/26 19:06:28 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout
        << CYAN
        << "[WrongAnimal] Default constructor called"
        << NORMAL << std::endl;
    _type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout
        << CYAN
        << "[WrongAnimal] Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout
        << CYAN
        << "[WrongAnimal] Copy assignment constructor called"
        << NORMAL << std::endl;
    _type = copy.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
std::cout
        << CYAN
        << "[WrongAnimal] Destructor called"
        << NORMAL << std::endl;
}

std::string WrongAnimal::getType() const { return this->_type; }

void    WrongAnimal::makeSound() const
{
    std::cout
        << "BOOP BOOP"
        << std::endl;
}