/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:47:32 by adian             #+#    #+#             */
/*   Updated: 2023/03/26 17:41:03 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
    std::cout
        << CYAN
        << "[Cat] Default constructor called"
        << NORMAL << std::endl;
    this->_type = "Cat";
}

Cat::Cat(const Cat &copy)
{
    std::cout
        << CYAN
        << "[Cat] Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat &copy)
{
    std::cout
        << CYAN
        << "[Cat] Copy assignment constructor called"
        << NORMAL << std::endl;
    _type = copy.getType();
    return (*this);
}

Cat::~Cat()
{
std::cout
        << CYAN
        << "[Cat] Destructor called"
        << NORMAL << std::endl;
}

void    Cat::makeSound() const  
{
    std::cout
        << "MEOW MEOW"
        << std::endl;
}