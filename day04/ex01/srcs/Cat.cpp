/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:47:32 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 13:44:14 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
    std::cout
        << VIOLET
        << "[Cat] Default constructor called"
        << NORMAL << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal (copy)
{
    std::cout
        << VIOLET
        << "[Cat] Copy constructor called"
        << NORMAL << std::endl;
    this->_brain = NULL;
	*this = copy;
}

Cat& Cat::operator=(const Cat &copy)
{
    std::cout
        << VIOLET
        << "[Cat] Copy assignment constructor called"
        << NORMAL << std::endl;

    if (this == &copy)
		return (*this);
	this->_type = copy.getType();
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain();
	*this->_brain = *copy._brain;
	return (*this);
}

Cat::~Cat()
{
    std::cout
        << VIOLET
        << "[Cat] Destructor called"
        << NORMAL << std::endl;
    delete this->_brain;
}

void    Cat::makeSound() const  
{
    std::cout
        << "MEOW MEOW"
        << std::endl;
}

Brain	&Cat::getBrain() const
{
	return (*this->_brain);
}

void	Cat::showIdeaFrom(unsigned int index) const
{
	std::cout << "Animal: " << this->_type << " ==> FROM brain ";
	std::cout << index << ": " << this->_brain->getIdeaByIndex(index) << std::endl;
	return ;
}

void	Cat::setIdeaIn(std::string idea, unsigned int index)
{
	this->_brain->setIdeaByIndex(idea, index);
	return ;
}