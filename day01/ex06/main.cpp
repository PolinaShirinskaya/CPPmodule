/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:58:22 by adian             #+#    #+#             */
/*   Updated: 2023/01/10 19:20:36 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen		karen;
	std::string	level;
	
	if (argc != 2)
	{
		std::cout << "Please enter: ./a.out [DEBUG || INFO || WARNING || ERROR || something]" << std::endl;
		return (1);
	}
	level = argv[1];
	if ("DEBUG" != level && "INFO" != level
		&& "WARNING" != level && "ERROR" != level)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	karen.complain(level);
	return (0);
}
