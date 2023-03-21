/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:41:18 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 15:36:45 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	std::cout << "____________________A make" << std::endl;
	Fixed a;
	std::cout << "____________________B make" << std::endl;
	Fixed const b( 10 );
	std::cout << "____________________C make" << std::endl;
	Fixed const c( 42.42f );
	std::cout << "_____________D copy from B" << std::endl;
	Fixed const d( b );

	std::cout << "____________________A new" << std::endl;
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
