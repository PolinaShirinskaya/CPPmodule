/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:27:47 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 13:45:04 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
    std::cout
        << BLUE
        << "[Animal] Default constructor called"
        << NORMAL << std::endl;
    _type = "Animal";
}

Animal::Animal(const Animal &copy)
{
    std::cout
        << BLUE
        << "[Animal] Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal &copy)
{
    std::cout
        << BLUE
        << "[Animal] Copy assignment constructor called"
        << NORMAL << std::endl;
    _type = copy.getType();
    return (*this);
}

Animal::~Animal()
{
std::cout
        << BLUE
        << "[Animal] Destructor called"
        << NORMAL << std::endl;
}

std::string Animal::getType() const { return this->_type; }

void    Animal::makeSound() const
{
    std::cout
        << "BOOP BOOP"
        << std::endl;
}