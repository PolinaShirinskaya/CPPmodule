/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:33:10 by adian             #+#    #+#             */
/*   Updated: 2023/04/28 15:08:13 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "---------------------------------------------\n";
	std::cout << "---------   TEST 1 (MutantStack)   ----------\n";
	std::cout << "---------------------------------------------" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << mstack.top() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		mstack.pop();

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << mstack.size() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		
		std::cout << "---------------------------------------------\n";
		std::cout << "--  MutantStack: input >>                  --\n";
		std::cout << "---------------------------------------------" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "---------------------------------------------" << std::endl;
	}

	std::cout << "---------------------------------------------\n";
	std::cout << "-----------   TEST 2 (List)    --------------\n";
	std::cout << "---------------------------------------------" << std::endl;
	{
		std::list<int>	intList;

		intList.push_back(5);
		intList.push_back(17);

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << intList.back() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		intList.pop_back();

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << intList.size() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		intList.push_back(3);
		intList.push_back(5);
		intList.push_back(737);
		intList.push_back(0);

		std::list<int>::iterator it = intList.begin();
		std::list<int>::iterator ite = intList.end();

		++it;
		--it;
		
		std::cout << "---------------------------------------------\n";
		std::cout << "--  List: input >>>  --\n";
		std::cout << "---------------------------------------------" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "---------------------------------------------" << std::endl;
	}
}
