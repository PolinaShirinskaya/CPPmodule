/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:59:34 by adian             #+#    #+#             */
/*   Updated: 2023/01/10 18:10:12 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
    return;
}

Karen::~Karen(void)
{
    return;
}

void    Karen::complain(std::string level)
{
    void (Karen::*funcs[4])(void);
    std::string levels[4];
    int i;

    funcs[0] = &Karen::debug;
    funcs[1] = &Karen::info;
    funcs[2] = &Karen::warning;
    funcs[3] = &Karen::error;
    
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    i = -1;
    while (++i <= 3)
        if (levels[i] == level)
            break ;
    switch (i)
    {
        case 0:
            (this->*funcs[0])();
            break ;
        case 1:
            (this->*funcs[1])();
            break ;
        case 2:
            (this->*funcs[2])();
            break ;
        case 3:
            (this->*funcs[3])();
            break ;
    }
}

void    Karen::debug(void)
{
    std::cout
        << "_______DEBUG______" << std::endl
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl
        << "I really do!" << std::endl;
}

void	Karen::info(void)
{
	std::cout
		<< "_______INFO_______" << std::endl
		<< "I cannot believe adding extra bacon cost more money. You don’t put enough!" << std::endl
		<< "If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout
		<< "_______WARNING_______" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout
		<< "_______ERROR_______" << std::endl
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}
