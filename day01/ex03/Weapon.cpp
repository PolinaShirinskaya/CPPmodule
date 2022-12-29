/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:22:56 by adian             #+#    #+#             */
/*   Updated: 2022/12/29 12:32:30 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    _type = type;
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

const std::string& Weapon::getType(void)
{
    const std::string& type = _type;
    return (type);
}

void Weapon::setType(std::string type)
{
    _type = type;
    return ;
}
