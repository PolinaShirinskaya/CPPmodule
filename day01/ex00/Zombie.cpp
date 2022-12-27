/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:07:40 by adian             #+#    #+#             */
/*   Updated: 2022/12/27 13:35:24 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout
        << _name
        << " is Born"
        << std::endl;
}

Zombie::~Zombie()
{
    std::cout
        << _name
        <<": "
        << "I'm dead...again n again"
        << std::endl;
}

void Zombie::announce()
{
    std::cout
        << _name
        << ": BrainzzzzzZ..."
        << std::endl;
    return;
}
