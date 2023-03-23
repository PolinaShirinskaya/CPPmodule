/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:19:14 by adian             #+#    #+#             */
/*   Updated: 2023/03/23 17:19:40 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
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
	std::cout << "--                 Duel on Cloud City                               --\n";
	std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << claptrap_1 << "\n\n" << claptrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
    
    claptrap_2.attack(claptrap_1.getName());
	claptrap_1.takeDamage(claptrap_2.getAttackDamage());

    std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << claptrap_1 << "\n\n" << claptrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    claptrap_2.takeDamage(5);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << claptrap_1 << "\n\n" << claptrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	claptrap_2.beRepaired(2);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << claptrap_1 << "\n\n" << claptrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    claptrap_2.takeDamage(5);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << claptrap_1 << "\n\n" << claptrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());
    claptrap_2.attack(claptrap_1.getName());

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << claptrap_1 << "\n\n" << claptrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    claptrap_2.takeDamage(2);

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << claptrap_1 << "\n\n" << claptrap_2 << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

    claptrap_2.attack(claptrap_1.getName());
    
    std::cout << "----------------------------------------------------------------------\n";
	std::cout << "--                 The force is with you, young Skywalker           --\n";
    std::cout << "--                      But you're not a Jedi yet...                --\n";
	std::cout << "----------------------------------------------------------------------" << std::endl;
    
    return 0;
}