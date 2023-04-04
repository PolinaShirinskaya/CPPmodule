/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:26:30 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 20:02:25 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#define SEP "-----------------------------------------------------------------------------------------------"

static void	freeData(Bureaucrat **bureaucrat, AForm **formA, AForm **formB, AForm **formC)
{
	if (*bureaucrat)
	{
		delete *bureaucrat;
		*bureaucrat = NULL;
	}
	if (*formA)
	{
		delete *formA;
		*formA = NULL;
	}
	if (*formB)
	{
		delete *formB;
		*formB = NULL;
	}
	if (*formC)
	{
		delete *formC;
		*formC = NULL;
	}
}

int	main()
{
	Bureaucrat	*bureaucrat = NULL;
	AForm		*formA = NULL;
	AForm		*formB = NULL;
	AForm		*formC = NULL;

	std::cout << SEP << std::endl;
	std::cout << "-----------------------           Test 1          ";
	std::cout << "---------------------------------------------\n";
	std::cout << SEP << std::endl;

	try
	{
		bureaucrat = new Bureaucrat("Jack", 4);
		formA = new ShrubberyCreationForm("tree_1");
		formB = new RobotomyRequestForm("ClapTrap");
		formC = new PresidentialPardonForm("Archer");

		std::cout << SEP << std::endl;

		std::cout << *bureaucrat << std::endl;
		std::cout << *formA << std::endl;
		std::cout << *formB << std::endl;
		std::cout << *formC << std::endl;
		
		std::cout << SEP << std::endl;
		
		bureaucrat->signForm(*formA);
		bureaucrat->signForm(*formB);
		bureaucrat->signForm(*formC);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		bureaucrat->executeForm(*formB);
		bureaucrat->executeForm(*formC);
		
		std::cout << SEP << std::endl;
	}
	catch(const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}
	
	std::cout << SEP << std::endl;
	freeData(&bureaucrat, &formA, &formB, &formC);
	std::cout << SEP << std::endl;

	std::cout << SEP << std::endl;
	std::cout << "-----------------------           Test 2          ";
	std::cout << "---------------------------------------------\n";
	std::cout << SEP << std::endl;

	try
	{
		bureaucrat = new Bureaucrat("Adlin", 146);
		formA = new ShrubberyCreationForm("tree_2");

		std::cout << SEP << std::endl;
		
		std::cout << *bureaucrat << std::endl;
		std::cout << *formA << std::endl;
		
		std::cout << SEP << std::endl;
		
		bureaucrat->signForm(*formA);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->incrementGrade();
		
		std::cout << SEP << std::endl;
		
		bureaucrat->signForm(*formA);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		
		std::cout << SEP << std::endl;
		
		std::cout << *formA << std::endl;
		
		std::cout << SEP << std::endl;
		
		for (int i = 0; i < 10; i++)
			bureaucrat->incrementGrade();
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		
		std::cout << SEP << std::endl;
	}
	catch(const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << SEP << std::endl;
	freeData(&bureaucrat, &formA, &formB, &formC);
	std::cout << SEP << std::endl;

	std::cout << SEP << std::endl;
	std::cout << "-----------------------           Test 3          ";
	std::cout << "---------------------------------------------\n";
	std::cout << SEP << std::endl;

	try
	{
		bureaucrat = new Bureaucrat("Boris", 46);
		formA = new RobotomyRequestForm("ScavTrap");

		std::cout << SEP << std::endl;
		
		std::cout << *bureaucrat << std::endl;
		std::cout << *formA << std::endl;
		
		std::cout << SEP << std::endl;
		
		bureaucrat->signForm(*formA);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->incrementGrade();
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		
		std::cout << SEP << std::endl;
	}
	catch(const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << SEP << std::endl;
	freeData(&bureaucrat, &formA, &formB, &formC);
	std::cout << SEP << std::endl;

	std::cout << SEP << std::endl;
	std::cout << "-----------------------           Test 4          ";
	std::cout << "---------------------------------------------\n";
	std::cout << SEP << std::endl;

	try
	{
		bureaucrat = new Bureaucrat("Boris", 6);
		formA = new PresidentialPardonForm("Berserk");

		std::cout << SEP << std::endl;
		
		std::cout << *bureaucrat << std::endl;
		std::cout << *formA << std::endl;
		
		std::cout << SEP << std::endl;
		
		bureaucrat->signForm(*formA);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->incrementGrade();
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*formA);
		
		std::cout << SEP << std::endl;
	}
	catch(const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << SEP << std::endl;
	freeData(&bureaucrat, &formA, &formB, &formC);
	std::cout << SEP << std::endl;

	return (0);
}
