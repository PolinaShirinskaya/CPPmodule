/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:21:10 by adian             #+#    #+#             */
/*   Updated: 2023/03/31 14:48:55 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	//TRY WITH --->  10 <--- GRADE
	try
	{
		
		std::cout << "--------------------------------------------------\n";
		std::cout << WHITE << "   Initialization Bureaucrat - Grade 10\n" << NORMAL;
		std::cout << "--------------------------------------------------" << std::endl;

		Bureaucrat	burBob("Bob", 10);
		
		std::cout << burBob << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		for (int i = 0; i < 5; i++)
			burBob.decrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burBob << std::endl;
		for (int i = 0; i < 5; i++)
			burBob.incrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burBob << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	}
	catch(const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << "--------------------------------------------------\n";
	std::cout << "--------------------------------------------------" << std::endl;

	//TRY WITH --->  1 <--- GRADE
	try
	{
		std::cout << "--------------------------------------------------\n";
		std::cout << WHITE << ">> Initialization Bureaucrat - Grade 1\n" << NORMAL;
		std::cout << "--------------------------------------------------" << std::endl;

		Bureaucrat	burMartin("Martin", 1);
		
		std::cout << burMartin << std::endl;
		burMartin.incrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burMartin << std::endl;
		burMartin.incrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burMartin << std::endl;
		burMartin.incrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
	}
	catch(const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << "--------------------------------------------------\n";
	std::cout << "--------------------------------------------------" << std::endl;

	//TRY WITH --->  0 <--- GRADE
	try
	{
		std::cout << "--------------------------------------------------\n";
		std::cout << WHITE << ">> Initialization Bureaucrat - Grade 0\n" << NORMAL;
		std::cout << "--------------------------------------------------" << std::endl;

		Bureaucrat	burZero("Zero", 0);

		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burZero << std::endl;
		burZero.decrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
	}
	catch(const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << "--------------------------------------------------\n";
	std::cout << "--------------------------------------------------" << std::endl;

	//TRY WITH --->  151 <--- GRADE
	try
	{
		std::cout << "--------------------------------------------------\n";
		std::cout << WHITE << ">> Initialization Bureaucrat - Grade 151\n" << NORMAL;
		std::cout << "--------------------------------------------------" << std::endl;

		Bureaucrat	burJohn("John", 151);
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burJohn << std::endl;
		burJohn.decrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
	}
	catch(const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << "--------------------------------------------------\n";
	std::cout << "--------------------------------------------------" << std::endl;

	//TRY WITH --->  150 <--- GRADE
	try
	{
		std::cout << "--------------------------------------------------\n";
		std::cout << WHITE << ">> Initialization Bureaucrat - Grade 150\n" << NORMAL;
		std::cout << "--------------------------------------------------" << std::endl;

		Bureaucrat	burJack("Jack", 150);
		
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burJack << std::endl;
		burJack.incrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burJack << std::endl;
		burJack.decrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burJack << std::endl;
		burJack.decrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << burJack << std::endl;
		burJack.decrementGrade();
		std::cout << "--------------------------------------------------" << std::endl;
	}
	catch(const std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}

	return (0);

}

