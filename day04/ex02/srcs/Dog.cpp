/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:03:17 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 14:46:08 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
    std::cout
        << GREEN
        << "[Dog] Default constructor called"
        << NORMAL << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal (copy)
{
    std::cout
        << GREEN
        << "[Dog] Copy constructor called"
        << NORMAL << std::endl;
    this->_brain = NULL;
	*this = copy;
}

Dog& Dog::operator=(const Dog &copy)
{
    std::cout
        << GREEN
        << "[Dog] Copy assignment constructor called"
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

Dog::~Dog()
{
    std::cout
        << GREEN
        << "[Dog] Destructor called"
        << NORMAL << std::endl;
    delete this->_brain;
}

void    Dog::makeSound() const  
{
    std::cout
        << "MEOW MEOW"
        << std::endl;
}

Brain	&Dog::getBrain() const
{
	return (*this->_brain);
}

void	Dog::showIdeaFrom(unsigned int index) const
{
	std::cout << "Animal: " << this->_type << " ==> FROM brain ";
	std::cout << index << ": " << this->_brain->getIdeaByIndex(index) << std::endl;
	return ;
}

void	Dog::setIdeaIn(std::string idea, unsigned int index)
{
	this->_brain->setIdeaByIndex(idea, index);
	return ;
}