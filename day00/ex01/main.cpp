/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:07:54 by adian             #+#    #+#             */
/*   Updated: 2022/12/20 11:00:47 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "Enter your command (UPPERSPASE): ";
		std::cin >> command;
		if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
