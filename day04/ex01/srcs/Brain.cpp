/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:22:10 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 13:41:02 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout
        << CYAN
        << "[Brain] default costructor called"
        << NORMAL << std::endl;

    this->_ideas = new std::string[100];

    for(int i = 0; i < 100; i++)
        _ideas[i] = "some cat's thoughts";
}

Brain::Brain(const Brain &copy)
{
    std::cout
        << CYAN
        << "[Brain] copy costructor called"
        << NORMAL << std::endl;

    this->_ideas = new std::string[100];
    *this = copy;
    /*for (int i = 0; i < 100; i++)
        (this->_ideas[i]) = (copy._ideas[i]); */
}

Brain&  Brain::operator=(const Brain &copy)
{
    std::cout
        << CYAN
        << "[Brain] Copy assignment constructor called"
        << NORMAL << std::endl;

    if (this == &copy)
        return *this;

    delete [] this->_ideas;

    if (this != &copy)
    {
        this->_ideas = new std::string[100];
        for (int i = 0; i < 100; i++)
            (this->_ideas[i]) = (copy._ideas[i]);
    }
    return (*this);

}

Brain::~Brain()
{
    std::cout   
        << CYAN
        << "[Brain] Destructor called"
        << NORMAL << std::endl;
    delete [] this->_ideas;
}

std::string const	&Brain::getIdeaByIndex(unsigned int const index) const
{
	if (index < 100)
		return (this->_ideas[index]);
	else
		return (this->_ideas[0]);
}

void	Brain::setIdeaByIndex(std::string idea, unsigned int index)
{
	if (index < 100)
		this->_ideas[index] = idea;
	return ;
}
