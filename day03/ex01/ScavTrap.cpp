/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:21:31 by adian             #+#    #+#             */
/*   Updated: 2023/03/23 17:17:31 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("NoName")
{
    std::cout
        << VIOLET
        << " NoName"
        << " ScavTrap DEFAULT constructor called "
        << NORMAL << std::endl;

    setName("NoName");
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout
        << VIOLET
        << name
        << " ScavTrap constructor called "
        << NORMAL << std::endl;

    setName(name);
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout
        << VIOLET
        << copy.getName()
        << " ScavTrap copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout 
        << VIOLET
        << " ScavTrap copy assignment called" 
        << NORMAL << std::endl;
	if (this == &copy)
		return (*this);
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout 
        << VIOLET
        << " ScavTrap destructor called" 
        << NORMAL << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
    if (this->getHitPoints() <= 0)
    {
        std::cout 
            << RED << "ClapTrap "
            << this->getName()
            << " has no HitPoints. R.I.P. Can't attack!"
            << NORMAL << std::endl;
            return ;
    }
    if (this->getEnergyPoints() <= 0)
    {
        std::cout 
            << RED << "ClapTrap "
            << this->getName()
            << " has no EnregyPoints. It's tired. Can't attack!"
            << NORMAL << std::endl;
            return ;
    }
    
    std::cout 
        << GREEN << "ClapTrap "
        << this->getName() << " attacks " << target
        << " , causing " << this->getAttackDamage() << " points of damage!"
        << NORMAL << std::endl;
    this->_energy_points -= 1;
    return ;
	
}

void	ScavTrap::guardGate()
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << RED
		    << "ScavTrap " << this->getName() 
            << " has no Hit Points. R.I.P. No Gate keeper mode!!!"
		    << NORMAL << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << RED
		    << "ScavTrap " << this->getName() 
            << " has no Energy Points. It's tired. No Gate keeper mode!!!"
		    << NORMAL << std::endl;
		return ;
	}
	std::cout 
        << GREEN 
        << "ScavTrap " << this->_name 
        << " is in Gate keeper mode." 
        << NORMAL << std::endl;
	this->_energy_points -= 1;
	return ;
}

std::ostream& operator<<(std::ostream &out, ScavTrap const &scavtrap)
{
	out << "ScavTrap: " << scavtrap.getName();
	out << "\nHit Points: " << scavtrap.getHitPoints();
	out << "\nEnergy Points: " << scavtrap.getEnergyPoints();
	out << "\nAttack Damage: " << scavtrap.getAttackDamage();
	return (out);
}

