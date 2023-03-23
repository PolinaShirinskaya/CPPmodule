/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:21:40 by adian             #+#    #+#             */
/*   Updated: 2023/03/23 19:10:52 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("NoName")
{
    std::cout
        << VIOLET
        << " NoName"
        << " FragTrap DEFAULT constructor called "
        << NORMAL << std::endl;

    setName("NoName");
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout
        << VIOLET
        << name
        << " FragTrap constructor called "
        << NORMAL << std::endl;

    setName(name);
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout
        << VIOLET
        << copy.getName()
        << " FragTrap copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(FragTrap const &copy)
{
	std::cout 
        << VIOLET
        << " FragTrap copy assignment called" 
        << NORMAL << std::endl;
	if (this == &copy)
		return (*this);
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout 
        << VIOLET
        << " FragTrap destructor called" 
        << NORMAL << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->getHitPoints() <= 0)
	{
		std::cout 
            << RED 
            << "FragTrap " 
            << this->getName() 
            << " has no Hit Points. It is dead. It can't high five!!!"
		    << NORMAL << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout 
            << RED 
            << "FragTrap " << this->getName() 
            << " has no Energy Points. It is discharged. It can't high five!!!"
            << NORMAL << std::endl;
		return ;
	}
	std::cout 
        << GREEN << "FragTrap " 
        << this->getName() 
        << ": Hey!!! Hive Five!!!" 
        << NORMAL << std::endl;
	this->_energy_points -= 1;
	return ;
}

void	FragTrap::attack(std::string const &target)
{
    if (this->getHitPoints() <= 0)
    {
        std::cout 
            << RED << "FragTrap "
            << this->getName()
            << " has no HitPoints. R.I.P. Can't attack!"
            << NORMAL << std::endl;
            return ;
    }
    if (this->getEnergyPoints() <= 0)
    {
        std::cout 
            << RED << "FragTrap "
            << this->getName()
            << " has no EnregyPoints. It's tired. Can't attack!"
            << NORMAL << std::endl;
            return ;
    }
    
    std::cout 
        << GREEN << "FragTrap "
        << this->getName() << " attacks " << target
        << " , causing " << this->getAttackDamage() << " points of damage!"
        << NORMAL << std::endl;
    this->_energy_points -= 1;
    return ;
	
}

std::ostream& operator<<(std::ostream &out, FragTrap const &fragtrap)
{
	out << "FragTrap: " << fragtrap.getName();
	out << "\nHit Points: " << fragtrap.getHitPoints();
	out << "\nEnergy Points: " << fragtrap.getEnergyPoints();
	out << "\nAttack Damage: " << fragtrap.getAttackDamage();
	return (out);
}