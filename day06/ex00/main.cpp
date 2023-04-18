/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:16:34 by adian             #+#    #+#             */
/*   Updated: 2023/04/18 19:00:13 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
    ScalarConverter convert;
    
    try
    {
        if (argc != 2)
            throw ScalarConverter::InvalidAmountInputArgs();
        convert.setInput(argv[1]);
        convert.convert();

        std::cout << convert;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}