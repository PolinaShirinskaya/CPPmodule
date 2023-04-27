/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:30:12 by adian             #+#    #+#             */
/*   Updated: 2023/04/27 14:07:35 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "------------------------------INTS-----------------------------------------" << std::endl;   
    {
        std::vector<int> indexVector(10);
        std::vector<int> iteratorVector(10);

        //work with [index]
        for (size_t i = 0; i < indexVector.size(); i++)
            indexVector[i] = i;

        //work with iterator
        int value = 0;
        for (std::vector<int>::iterator it = iteratorVector.begin(); 
                it != iteratorVector.end(); it++)
        {
            *it = value;
            value += 10;
        }

        std::cout << "indexVector[ " << indexVector.size() << " ]: ";
        for (size_t i = 0; i < indexVector.size(); i++)
        {
            if (i == indexVector.size() - 1)
                std::cout << indexVector[i] << std::endl;
            else
                std::cout << indexVector[i] << " ";
        }

        std::cout << "iteratorVector[ " << indexVector.size() << " ]: ";
        for (std::vector<int>::iterator it = iteratorVector.begin(); 
                it != iteratorVector.end(); it++)
        {
            if (it == iteratorVector.end() - 1)
                std::cout << *it << std::endl;
            else
                std::cout << *it << " ";
        }

        std::cout << "---------------------------------------------------------------------------" << std::endl;

        std::vector<int>::iterator	iter;

		try
		{
			std::cout << "easyfind( indexVector, 5 ) >>> ";
			std::cout << *easyfind(indexVector, 5) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}
		
		try
		{
			std::cout << "easyfind( indexVector, 11 ) >>> ";
			std::cout << *easyfind(indexVector, 11) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}

		try
		{
			std::cout << "easyfind( iteratorVector, 50 ) >>> ";
			std::cout << *easyfind(iteratorVector, 50) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}
		
		try
		{
			std::cout << "easyfind( iteratorVector, 100 ) >>> ";
			std::cout << *easyfind(iteratorVector, 100) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

    std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "------------------------------LISTS----------------------------------------" << std::endl;
    {
		std::list<int>				intList1;
		std::list<int>				intList2;

		for (size_t i = 0; i < 10; i++)
			intList1.push_front(i);
		
		for (size_t i = 0; i < 10; i++)
			intList2.push_back(i * i);
		
		std::cout << "intList1[ " << intList1.size() << " ]: ";
		for (std::list<int>::iterator it = intList1.begin(); it != intList1.end(); ++it)
		{
			if (it == --intList1.end())
				std::cout << *it << std::endl;
			else
				std::cout << *it << " ";
		}

		std::cout << "intList2[ " << intList2.size() << " ]: ";
		for (std::list<int>::iterator it = intList2.begin(); it != intList2.end(); ++it)
		{
			if (it == --intList2.end())
				std::cout << *it << std::endl;
			else
				std::cout << *it << " ";
		}

		std::cout << "---------------------------------------------------------------------------" << std::endl;

		std::list<int>::iterator	iter;

		try
		{
			std::cout << "easyfind( intList1, 5 ) >>> ";
			std::cout << *easyfind(intList1, 5) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}
		
		try
		{
			std::cout << "easyfind( intList1, 10 ) >>> ";
			std::cout << *easyfind(intList1, 10) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}

		try
		{
			std::cout << "easyfind( intList2, 25 ) >>> ";
			std::cout << *easyfind(intList2, 25) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}
		
		try
		{
			std::cout << "easyfind( intList2, 100 ) >>> ";
			std::cout << *easyfind(intList2, 100) << std::endl;
		}
		catch(const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	return (0);
}