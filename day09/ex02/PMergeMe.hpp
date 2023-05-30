/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:34:11 by adian             #+#    #+#             */
/*   Updated: 2023/05/30 20:09:47 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <climits>
# include <vector>
# include <deque>
# include <ctime>

# include <algorithm>

# define THRESHOLD 5

class PMergeMe {
    private:
        char**              argv;
        int                 argc;
        std::vector<int>    input;
        std::vector<int>    vect;
        std::deque<int>     deq;

    public:
        PMergeMe();
        PMergeMe(char **argv, int argc);
        PMergeMe(const PMergeMe& copy);
        PMergeMe& operator=(const PMergeMe& copy);
        ~PMergeMe();
        
    
        static long inputToInt(std::string str);
        double      sortVector();
        double      sortDeque();
        
        template <typename T>
		void    printContainers(const T& container, std::string output);

        template <typename T>
		void    printTime(const T& container, std::string name, double time);

		template <typename T>
		void	mergeSort(T& container);

		template <typename T>
		void    insertSort(T& container);
       
        class NonPositiveArgumentException : public std::exception { const char *what() const throw(); };
        class NumberOutOfRangeException : public std::exception { const char *what() const throw(); };

};

#endif