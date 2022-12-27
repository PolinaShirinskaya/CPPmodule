/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:51:23 by adian             #+#    #+#             */
/*   Updated: 2022/12/27 14:34:50 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout
        <<_name
        << " is born for brainZeat"
        << std::endl;
}

Zombie::Zombie()
{
    _name = "Undefined Zombie";
    std::cout
        << _name
        << " is born for brainZeat"
        << std::endl;
}

Zombie::~Zombie()
{
    std::cout
        << _name
        <<" #" << _id
        <<": "
        <<"I'm dead... again n again"
        << std::endl;
}

void    Zombie::announce()
{
    std::cout
        << _name
        << " #" << _id
        << ": brainzzzzZ"
        << std::endl;
}

void    Zombie::setName(std::string name)
{
    _name = name;
    return ;
}

int     Zombie::setGetId(int id)
{
    if (id == -3)
        return (_id);
    else
        _id = id;
    return (0);
}
