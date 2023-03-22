/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:19:14 by adian             #+#    #+#             */
/*   Updated: 2023/03/22 18:30:04 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "----------------------------------------------------------------------\n";
	std::cout << "--                  Initiation of ClapTrap series                   --\n";
	std::cout << "----------------------------------------------------------------------\n";
	std::cout << ">> Initiation ScavTrap scavtrap_1..." << std::endl; 
	ScavTrap	scavtrap_1("Master Yoda");
    
	std::cout << "----------------------------------------------------------------------\n";
    std::cout << ">> Initiation ScavTrap scavtrap_2..." << std::endl; 
	ScavTrap	scavtrap_2("C-3PO");

	std::cout << "----------------------------------------------------------------------\n";
    std::cout << ">> Initiation ScavTrap scavtrap_3..." << std::endl; 
	ScavTrap	scavtrap_3(scavtrap_1);

	std::cout << "----------------------------------------------------------------------\n";
    std::cout << ">> Initiation ScavTrap scavtrap_4..." << std::endl; 
	ScavTrap	scavtrap_4;
	scavtrap_4 = scavtrap_2;
	



    std::cout << "----------------------------------------------------------------------\n";
	std::cout << "--                            BigDuel                               --\n";
	std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << scavtrap_1 << "\n\n" << scavtrap_2 << "\n\n";
	std::cout << scavtrap_3 << "\n\n" << scavtrap_4 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
    
	
    scavtrap_1.attack(scavtrap_2.getName());
	scavtrap_2.takeDamage(scavtrap_1.getAttackDamage());

    std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << scavtrap_1 << "\n\n" << scavtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    scavtrap_2.takeDamage(60);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << scavtrap_1 << "\n\n" << scavtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	scavtrap_2.beRepaired(20);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << scavtrap_1 << "\n\n" << scavtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    scavtrap_2.takeDamage(60);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << scavtrap_1 << "\n\n" << scavtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	scavtrap_2.beRepaired(20);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << scavtrap_1 << "\n\n" << scavtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	scavtrap_1.guardGate();
	scavtrap_1.guardGate();
	scavtrap_1.guardGate();
	scavtrap_1.guardGate();
	scavtrap_1.guardGate();
	
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << scavtrap_1 << "\n\n" << scavtrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

   	std::cout << "----------------------------------------------------------------------\n";
	std::cout << "--                           Destructor                             --\n";
	std::cout << "----------------------------------------------------------------------" << std::endl;


    return 0;
}