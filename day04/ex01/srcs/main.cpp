/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:58:57 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 14:10:03 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "------------------------- Deep Copy CAT----------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	{
		Cat	cat;

		std::cout << "-------------------------------------------------------------" << std::endl;
		
		cat.showIdeaFrom(0);
		cat.showIdeaFrom(1);
		cat.setIdeaIn("i wanna sleep!!!", 1);
		cat.showIdeaFrom(1);

		std::cout << "-------------------------------------------------------------" << std::endl;
		{
			Cat	tmp = cat;
			
			std::cout << "tmp ==> " << std::ends;
			tmp.showIdeaFrom(0);
			std::cout << "tmp ==> " << std::ends;
			tmp.showIdeaFrom(1);
			tmp.setIdeaIn("always wanna eat!!!", 1);
			std::cout << "tmp ==> " << std::ends;
			tmp.showIdeaFrom(1);

			std::cout << "-------------------------------------------------------------" << std::endl;

			cat.showIdeaFrom(1);
		}
		std::cout << "-------------------------------------------------------------" << std::endl;
		
		cat.showIdeaFrom(1);

		std::cout << "-------------------------------------------------------------" << std::endl;
	}
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "------------------------- Deep Copy DOG ---------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	{
		Dog	dog;

		std::cout << "-------------------------------------------------------------" << std::endl;
		
		dog.showIdeaFrom(0);
		dog.showIdeaFrom(1);
		dog.setIdeaIn("i wanna go for a walk!!!", 1);
		dog.showIdeaFrom(1);

		std::cout << "-------------------------------------------------------------" << std::endl;
		{
			Dog	tmp = dog;
			
			std::cout << "tmp ==> " << std::ends;
			tmp.showIdeaFrom(0);
			std::cout << "tmp ==> " << std::ends;
			tmp.showIdeaFrom(1);
			tmp.setIdeaIn("hate squirrels!!!", 1);
			std::cout << "tmp ==> " << std::ends;
			tmp.showIdeaFrom(1);

			std::cout << "-------------------------------------------------------------" << std::endl;

			dog.showIdeaFrom(1);
		}
		std::cout << "-------------------------------------------------------------" << std::endl;
		
		dog.showIdeaFrom(1);

		std::cout << "-------------------------------------------------------------" << std::endl;
	}
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------- Test 1 ---------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	{
		Animal const	*cat = new Cat();
		Animal const	*dog = new Dog();

		std::cout << "-------------------------------------------------------------" << std::endl;

		delete cat;
		delete dog;
	}
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------- Test 2 ---------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	{
		size_t	size = 6;
		Animal	*animals[size];

		std::cout << ">> Initiation of array animals" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		for (size_t i = 0; i < size; i++)
		{
			if (i < size / 2)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		std::cout << "-------------------------------------------------------------" << std::endl;
		}

		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << ">> Deletion of array animals" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		
		for (size_t i = 0; i < size; i++)
		{
			delete animals[i];
			std::cout << "-------------------------------------------------------------" << std::endl;
		}
	}

	return (0);
}