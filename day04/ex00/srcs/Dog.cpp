/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:03:17 by adian             #+#    #+#             */
/*   Updated: 2023/03/26 17:21:48 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout
        << CYAN
        << "[Dog] Default constructor called"
        << NORMAL << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog &copy)
{
    std::cout
        << CYAN
        << "[Dog] Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog &copy)
{
    std::cout
        << CYAN
        << "[Dog] Copy assignment constructor called"
        << NORMAL << std::endl;
    _type = copy.getType();
    return (*this);
}

Dog::~Dog()
{
std::cout
        << CYAN
        << "[Dog] Destructor called"
        << NORMAL << std::endl;
}

void    Dog::makeSound() const  
{
    std::cout
        << "WOOF WOOF"
        << std::endl;
}