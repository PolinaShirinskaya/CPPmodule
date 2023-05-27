/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:05 by adian             #+#    #+#             */
/*   Updated: 2023/05/27 15:29:59 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool inputValidation(const std::string input)
{
    if (input.empty())
    {
        std::cerr << "Error: Invalid number of arguments.\n";
        std::cerr << "Usage: ./PMergeMe <int int int ...> " << std::endl;
        return false;
    }
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            std::cerr << "Error: Invalid input." << std::endl;
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Invalid number of arguments.\n";
        std::cerr << "Usage: ./PMergeMe <int int int ...> " << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        if (!inputValidation(argv[i]))
            return (1);
    }
    return (0);
}