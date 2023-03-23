/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:19:14 by adian             #+#    #+#             */
/*   Updated: 2023/03/23 19:03:18 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << "--                  Initiation of ClapTrap series                   --\n";
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << ">> Initiation ClapTrap claptrap_1..." << std::endl; 
		ClapTrap	claptrap_1("Darth Vader");
		std::cout << "----------------------------------------------------------------------\n";
		
		std::cout << ">> Initiation ClapTrap claptrap_2..." << std::endl; 
		ClapTrap	claptrap_2("Luke Skywalker");
		std::cout << "----------------------------------------------------------------------\n";

		std::cout << ">> Initiation ClapTrap claptrap_3..." << std::endl; 
		ClapTrap	claptrap_3(claptrap_1);
		std::cout << "----------------------------------------------------------------------\n";

		std::cout << ">> Initiation ClapTrap claptrap_4..." << std::endl; 
		ClapTrap	claptrap_4;
		claptrap_4 = claptrap_2;
		
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << "--                           Destructor                             --\n";
		std::cout << "----------------------------------------------------------------------" << std::endl;
	}

	{
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << "--                  Initiation of ScavTrap series                   --\n";
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << ">> Initiation ScavTrap fragtrap_1..." << std::endl; 
		ScavTrap	fragtrap_1("Master Yoda");
		
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << ">> Initiation ScavTrap scavtrap_2..." << std::endl; 
		ScavTrap	scavtrap_2("C-3PO");

		std::cout << "----------------------------------------------------------------------\n";
		std::cout << ">> Initiation ScavTrap scavtrap_3..." << std::endl; 
		ScavTrap	scavtrap_3(fragtrap_1);

		std::cout << "----------------------------------------------------------------------\n";
		std::cout << ">> Initiation ScavTrap scavtrap_4..." << std::endl; 
		ScavTrap	scavtrap_4;
		scavtrap_4 = scavtrap_2;
		
		std::cout << "----------------------------------------------------------------------\n";
		std::cout << "--                           Destructor                             --\n";
		std::cout << "----------------------------------------------------------------------" << std::endl;
	}
	
	std::cout << "----------------------------------------------------------------------\n";
	std::cout << "----------------------------------------------------------------------\n";
	std::cout << "----------------------------------------------------------------------\n";
	std::cout << "--                  Initiation of FragTrap series                   --\n";
	std::cout << "----------------------------------------------------------------------\n";
	std::cout << ">> Initiation FragTrap FragTrap_1..." << std::endl; 
	FragTrap	fragtrap_1("R2-D2");
		
	std::cout << "----------------------------------------------------------------------\n";
	std::cout << ">> Initiation FragTrap FragTrap_2..." << std::endl; 
	FragTrap	fragtrap_2("BB-8");

	std::cout << "----------------------------------------------------------------------\n";
	std::cout << ">> Initiation FragTrap FragTrap_3..." << std::endl; 
	FragTrap	fragtrap_3(fragtrap_1);

	std::cout << "----------------------------------------------------------------------\n";
	std::cout << ">> Initiation FragTrap FragTrap_4..." << std::endl; 
	FragTrap	fragtrap_4;
	fragtrap_4 = fragtrap_2;

    std::cout << "----------------------------------------------------------------------\n";
	std::cout << "--                     Battle of the machines                       --\n";
	std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << fragtrap_1 << "\n\n" << fragtrap_2 << "\n\n";
	std::cout << fragtrap_3 << "\n\n" << fragtrap_4 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
    
	
    fragtrap_1.attack(fragtrap_2.getName());
	fragtrap_2.takeDamage(fragtrap_1.getAttackDamage());

    std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << fragtrap_1 << "\n\n" << fragtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    fragtrap_2.takeDamage(60);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << fragtrap_1 << "\n\n" << fragtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	fragtrap_2.beRepaired(20);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << fragtrap_1 << "\n\n" << fragtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    fragtrap_2.takeDamage(60);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << fragtrap_1 << "\n\n" << fragtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	fragtrap_2.beRepaired(20);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << fragtrap_1 << "\n\n" << fragtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	fragtrap_1.highFivesGuys();
	fragtrap_1.highFivesGuys();
	fragtrap_2.highFivesGuys();
	fragtrap_2.highFivesGuys();
	
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << fragtrap_1 << "\n\n" << fragtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

   	std::cout << "----------------------------------------------------------------------\n";
	std::cout << "--                           Destructor                             --\n";
	std::cout << "----------------------------------------------------------------------" << std::endl;


    return 0;
}