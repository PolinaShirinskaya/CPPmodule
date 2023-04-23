/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:45:05 by adian             #+#    #+#             */
/*   Updated: 2023/04/23 14:40:30 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "Awesome.hpp"

template<typename T>
void    printArray(T *ptrArray, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (i == len - 1)
            std::cout << ptrArray[i];
        else
            std::cout << ptrArray[i] << ",  ";
    }
}

template<typename T>
void	secondDegree(T &num)
{
	num *= num;
}

void	toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return ;
}


int main() {
    std::cout << "-------------------------INT ARRAY----------------------" << std::endl;
    
    {
        int	intArray[] = {1, 2, 3, 4, 5};
		int	lenIntArray = sizeof(intArray) / sizeof(intArray[0]);

		std::cout << "Before intArray: ";
		printArray(intArray, lenIntArray);
		std::cout << std::endl;

		::iter(intArray, lenIntArray, &::secondDegree);

		std::cout << "After intArray: ";
		printArray(intArray, lenIntArray);
		std::cout << std::endl;
    }
    
    std::cout << "----------------------STING ARRAY----------------------" << std::endl;
    
    {
        char	charArray[] = {'H', 'e', 'l', 'l', 'o'};
        size_t	lenCharArray = sizeof(charArray) / sizeof(charArray[0]);

		std::cout << "before charArray: ";
		printArray(charArray, lenCharArray);
		std::cout << std::endl;

		::iter(charArray, lenCharArray, &::toUpper);

		std::cout << "after charArray: ";
		printArray(charArray, lenCharArray);
		std::cout << std::endl;
    }

    std::cout << "----------------------CLASS---------------------------" << std::endl;


	{
		int		tab[] = {0, 1, 2, 3, 4};
		Awesome	tab2[5];

		::iter(tab, 5, &print);
		::iter(tab2, 5, &print);
	}
}