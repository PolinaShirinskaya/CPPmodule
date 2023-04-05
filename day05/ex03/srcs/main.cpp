/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:42:39 by adian             #+#    #+#             */
/*   Updated: 2023/04/05 14:44:19 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

#define SEP "-----------------------------------------------------------------------------------------------"

static void	freeData(Bureaucrat **bureaucrat, AForm **form)
{
	if (*bureaucrat)
	{
		delete *bureaucrat;
		*bureaucrat = NULL;
	}
	if (*form)
	{
		delete *form;
		*form = NULL;
	}
}

int	main()
{
	Intern		someIntern;
	Bureaucrat	*bureaucrat;
	AForm		*form;

	std::cout << SEP << std::endl;

	form = someIntern.makeForm("presidential pardon form", "26B");

	std::cout << SEP << std::endl;

	try
	{
		bureaucrat = new Bureaucrat("Bob", 3);

		std::cout << SEP << std::endl;

		bureaucrat->signForm(*form);
		
		std::cout << SEP << std::endl;
		
		bureaucrat->executeForm(*form);

		std::cout << SEP << std::endl;
	}
	catch(const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << SEP << std::endl;
	freeData(&bureaucrat, &form);

	return 0;

}
