/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:51:22 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 21:15:59 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout
        << "No name" << VIOLET
        << " ClapTrap DEFAULT constructor called" 
        << NORMAL << std::endl;
    _name = "NoName";
    _hit_points = 10;
    _energy_points = 10;
    _attack_damage = 0;    
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout
        << name << VIOLET
        << " ClapTrap constructor called"
        << NORMAL << std::endl;
    _name = name;
    _hit_points = 10;
    _energy_points = 10;
    _attack_damage = 0;    
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout
        << copy.getName() << VIOLET
        << " Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout
		<< _name << VIOLET
		<< " Destructor called"
		<< NORMAL << std::endl;
}

ClapTrap&	ClapTrap::operator = (ClapTrap const &copy)
{
	_name = copy.getName();
	_hit_points = copy.getHitPoints();
	_energy_points = copy.getEnergyPoints();
	_attack_damage = copy.getAttackDamage();
	std::cout
        << VIOLET
		<< " Copy assignment operator called"
		<< NORMAL << std::endl;
	return (*this);
}

std::string	ClapTrap::getName(void) const { return (_name); }

unsigned int	ClapTrap::getHitPoints(void) const { return (_hit_points); }

unsigned int	ClapTrap::getEnergyPoints(void) const { return (_energy_points); }

unsigned int	ClapTrap::getAttackDamage(void) const { return (_attack_damage); }

