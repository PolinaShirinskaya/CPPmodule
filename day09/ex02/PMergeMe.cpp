/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:34:14 by adian             #+#    #+#             */
/*   Updated: 2023/05/30 20:09:39 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe(char **argv, int argc) : argv(argv), argc(argc)
{
    try
    {
        //create base vector from input
        for (size_t i = 1; argv[i]; ++i)
        {
            input.push_back(inputToInt(argv[i]));
        }
        printContainers(this->input, "Before");


        //create VECTOR container
        for (size_t i = 0; i < input.size(); ++i)
        {
            vect.push_back(input[i]);
        }

        //create DEQUE container
        std::copy(this->vect.begin(), this->vect.end(), std::back_inserter(this->deq));

        double time_vect = sortVector();
		double time_deq = sortDeque();

        printContainers(this->vect, "After");
        std::cout << '\n';
        
        printTime(this->vect, "vector", time_vect);
		printTime(this->vect, "deque", time_deq);

        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

long PMergeMe::inputToInt(std::string str)
{
    long    l;
    const char *s = str.c_str();

    l = strtol(s, NULL, 10);
    if (l < 0 )
    {
        throw NonPositiveArgumentException();
    }
    if (l == LONG_MAX || l == LONG_MIN || l == INT_MAX || l == INT_MIN)
    {
        throw NumberOutOfRangeException();
    }
    return l;
}


double PMergeMe::sortVector()
{
    clock_t start = clock();

    mergeSort(this->vect);

    clock_t end = clock();

    double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC;
    
    return elapsed_time;
}

double PMergeMe::sortDeque()
{
    clock_t start = clock();

    mergeSort(this->deq);

    clock_t end = clock();

    double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC;
    
    return elapsed_time;
}

template <typename T>
void    PMergeMe::mergeSort(T& container)
{
	if (container.size() <= THRESHOLD)
		insertSort(container);
	else
	{
		T	left(container.begin(), container.begin() + container.size() / 2);
		T	right(container.begin() + container.size() / 2, container.end());

		mergeSort(left);
		mergeSort(right);

		std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
	}

}

template <typename T>
void    PMergeMe::insertSort(T& container)
{
	for (size_t i = 1; i != container.size(); i++)
	{
		long key = container[i];
		long j = i - 1;

		while (j >= 0 && container[j] > key)
		{
			container[j + 1] = container[j];
			j -= 1;
		}
		container[j + 1] = key;
	}
}

template <typename T>
void    PMergeMe::printContainers(const T& container, std::string output)
{
    typename T::const_iterator   it;
	std::cout << output << ": ";
	
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
}

template <typename T>
void    PMergeMe::printTime(const T& container, std::string name, double time)
{
	std::cout << "Time to process a range of " << container.size() << " elements ";
	std::cout << "with std::" << name << " : " << time << " us\n"; 
}
const char *PMergeMe::NonPositiveArgumentException::what() const throw() { return "Argument must be posite" ;}
const char *PMergeMe::NumberOutOfRangeException::what() const throw() { return "Argument out of range" ;}

PMergeMe::PMergeMe(const PMergeMe& copy) { *this = copy; }
PMergeMe& PMergeMe::operator=(const PMergeMe& copy) { input = copy.input; return *this; }

PMergeMe::~PMergeMe() {}