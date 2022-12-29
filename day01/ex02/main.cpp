/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:13:34 by adian             #+#    #+#             */
/*   Updated: 2022/12/28 23:20:32 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str;
    std::string *stringPTR;
    std::string &stringREF = str;
    
    str = "HI THIS IS BRAIN";
    stringPTR = &str;
    std::cout
        << "string addr:"
        << &str << std::endl;
    std::cout
        << "stringPTR addr:"
        << stringPTR << std::endl;
    std::cout
        << "stringREF addr:"
        << &stringREF << std::endl;
    std::cout
        << "string string:"
        << str << std::endl;
    std::cout
        << "stringPTR string:"
        << *stringPTR << std::endl;
    std::cout
        << "stringREF string:"
        << stringREF << std::endl;
}