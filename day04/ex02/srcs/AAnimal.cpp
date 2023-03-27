/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:27:47 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 14:45:48 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout
        << BLUE
        << "[AAnimal] Default constructor called"
        << NORMAL << std::endl;
    _type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout
        << BLUE
        << "[AAnimal] Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal &copy)
{
    std::cout
        << BLUE
        << "[AAnimal] Copy assignment constructor called"
        << NORMAL << std::endl;
    _type = copy.getType();
    return (*this);
}

AAnimal::~AAnimal()
{
std::cout
        << BLUE
        << "[AAnimal] Destructor called"
        << NORMAL << std::endl;
}

std::string AAnimal::getType() const { return this->_type; }
