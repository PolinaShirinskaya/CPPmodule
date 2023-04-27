/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:07:56 by adian             #+#    #+#             */
/*   Updated: 2023/04/27 18:35:48 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    std::cout << "--------------------------------------------------\n";
	std::cout << "------------    TEST 1 (5) addNumber    ----------\n";
	std::cout << "--------------------------------------------------";
	std::cout << std::endl;    
    {
        Span test = Span(5);

        test.addNumber(1);
        test.addNumber(2);
        test.addNumber(3);
        test.addNumber(4);
        test.addNumber(5);

        std::cout << test << std::endl;
        std::cout << "shortestSpan >>> " << test.shortestSpan() << std::endl;
        std::cout << "longestSpan >>> " << test.longestSpan() << std::endl;

    }

    std::cout << "--------------------------------------------------\n";
	std::cout << "------------    TEST 2 (10) addManyNumber    -----\n";
	std::cout << "--------------------------------------------------";
	std::cout << std::endl;
    {
        Span                test(10);
        std::vector<int>    srcVect(10);

        std::srand(std::time(NULL));
        for (int i = 0; i < 10; i++)
            srcVect[i] = std::rand() % 100;

        try
        {
            test.addManyNumbers(srcVect.begin(), srcVect.end());

            std::cout << test << std::endl;
            std::cout << "shortestSpan >>> " << test.shortestSpan() << std::endl;
            std::cout << "longestSpan >>> " << test.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        } 
    }

    std::cout << "--------------------------------------------------\n";
	std::cout << "------------    TEST 3 (10 000) addManyNumber    -----\n";
	std::cout << "--------------------------------------------------";
	std::cout << std::endl;
    {
        Span                test(10000);
        std::vector<int>    srcVect(10000);

        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; i++)
            srcVect[i] = std::rand();

        try
        {
            test.addManyNumbers(srcVect.begin(), srcVect.end());

            std::cout << "shortestSpan >>> " << test.shortestSpan() << std::endl;
            std::cout << "longestSpan >>> " << test.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        } 
    }

	std::cout << "--------------------------------------------------\n";
	std::cout << "------------    TEST 4 EXCEPTION   ---------------\n";
	std::cout << "--------------------------------------------------";
	std::cout << std::endl;
    {
		Span	test(1);

		try
		{
			test.addNumber(100);

			std::cout << test << std::endl;
			std::cout << "shortestSpan >>> " << test.shortestSpan() << std::endl;
			std::cout << "longtestSpan >>> " << test.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        } 
	}
}