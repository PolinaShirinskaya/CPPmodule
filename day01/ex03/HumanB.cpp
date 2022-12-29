/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:13:23 by adian             #+#    #+#             */
/*   Updated: 2022/12/29 14:15:53 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//Always take a name

HumanB::HumanB(std::string name) : _weapon(NULL)
{
    _name = name;
    std::cout
        << "HumanB "
        << name
        << " created without weapon" << std::endl;
}

HumanB::~HumanB()
{
    std::cout
        << "HumanB "
        << _name
        << " deleted" << std::endl;
}

void HumanB::attack(void)
{
    std::cout
        << _name
        << " attacks with his "
        << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
