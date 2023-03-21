/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:58:31 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 12:58:32 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	std::cout << "____________________A make" << std::endl;
    Fixed	a;
    std::cout << "_____________B copy from A" << std::endl;
	Fixed	b(a);
    std::cout << "_____________C copy from B" << std::endl;
	Fixed	c;

	c = b;

    std::cout << "_____________________get A" << std::endl;
	std::cout << a.getRawBits() << std::endl;
    std::cout << "_____________________get B" << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << "_____________________get C" << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}
