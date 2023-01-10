/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:46:18 by adian             #+#    #+#             */
/*   Updated: 2023/01/10 12:24:12 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//Always take a name and reference to the weapon

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
    _name = name;
    std::cout
        << "HumanA "
        << name
        << " created with "
        << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout
        << "HumanA "
        << _name
        << " deleted" << std::endl;
}

void HumanA::attack(void)
{
    std::cout
        << _name
        << " attacks with his "
        << _weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
    _weapon = weapon;
}
