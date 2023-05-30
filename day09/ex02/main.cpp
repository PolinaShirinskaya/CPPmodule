/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:05 by adian             #+#    #+#             */
/*   Updated: 2023/05/30 19:48:37 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int inputValidation(char **argv)
{
    for (size_t i = 1; argv[i]; ++i)
    {
        for (size_t j = 0; argv[i][j]; ++j)
        {
            if (argv[i][j] > '9' || argv[i][j] < '0')
            {
                std::cerr << "Error: Invalid input. Accept only digits" << std::endl;
                return 1;
            }
        }
        try { PMergeMe::inputToInt(argv[i]); }
        catch (const char *e) { std::cerr << "Error: " << e << '\n'; exit (1); }
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Error: Invalid number of arguments.\n";
        std::cerr << "Usage: ./PMergeMe <int int ...> " << std::endl;
        return 1;
    }
    
    inputValidation(argv);

    try { PMergeMe sorting(argv,argc); }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return (0);
}