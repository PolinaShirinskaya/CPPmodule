/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:51:22 by adian             #+#    #+#             */
/*   Updated: 2023/03/22 18:36:31 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout
        << VIOLET
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
        << VIOLET
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
        << VIOLET
        << " ClapTrap Copy constructor called"
        << NORMAL << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout
		<< VIOLET
		<< " ClapTrap Destructor called"
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
		<< " ClapTrap Copy assignment operator called"
		<< NORMAL << std::endl;
	return (*this);
}

std::string	ClapTrap::getName(void) const { return (_name); }

unsigned int	ClapTrap::getHitPoints(void) const { return (_hit_points); }

unsigned int	ClapTrap::getEnergyPoints(void) const { return (_energy_points); }

unsigned int	ClapTrap::getAttackDamage(void) const { return (_attack_damage); }

void    ClapTrap::attack(const std::string& target)
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
        << BLUE << "ClapTrap "
        << this->getName() << " attacks " << target
        << " , causing " << this->getAttackDamage() << " points of damage!"
        << NORMAL << std::endl;
    this->_energy_points -= 1;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHitPoints() <= 0)
    {
        std::cout 
            << RED << "ClapTrap "
            << this->getName()
            << " has no HitPoints. R.I.P."
            << NORMAL << std::endl;
            return ;
    }

    std::cout 
        << CYAN << "ClapTrap "
        << this->getName() << " take damage. "
        << amount << " HitPoints were lost!"
        << NORMAL << std::endl;
    if (this->_hit_points >= amount)
		this->_hit_points -= amount;
	else
		this->_hit_points = 0;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getHitPoints() <= 0)
	{
		std::cout 
            << RED << "ClapTrap " 
            << this->getName() 
            << " has no HitPoints. R.I.P. It can't be repaired!!!"
		    << NORMAL << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout 
            << RED << "ClapTrap " 
            << this->getName() 
            << " has no EnergyPoints. It's tired. It can't be repaired!!!"
            << NORMAL << std::endl;
		return ;
	}
	std::cout 
        << GREEN << "ClapTrap "
        << this->getName() 
        << " was repaired. "
        << amount 
        << " Hit Points have been restored." 
        << NORMAL << std::endl;
	this->_hit_points += amount;
	this->_energy_points -= 1;
	return ;
}

std::ostream&   operator << (std::ostream &out, const  ClapTrap &claptrap)
{
	out << "ClapTrap: " << claptrap.getName();
	out << "\nHit Points: " << claptrap.getHitPoints();
	out << "\nEnergy Points: " << claptrap.getEnergyPoints();
    out << "\nAttack Damage: " << claptrap.getAttackDamage();
	return (out);
}