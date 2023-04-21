/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:36:34 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 12:55:28 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "ERROR: Invalid num of argument!" << std::endl;
        std::cout << "Usage: ./convert + 'your argument'" << std::endl;
        return (false);
    }
    
    return (ScalarConverter::convertAll(argv[1]));
}