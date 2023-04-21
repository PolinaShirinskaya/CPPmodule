/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:27:40 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 17:47:03 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "SomeClass.hpp"

int	main()
{
	{
        std::cout << "----------------------INT-------------------------" << std::endl;
        //INTS
		int a = 2;
		int b = 3;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
        std::cout << "----------------------STRING-----------------------" << std::endl;
        //STRINGS
		std::string c = "chaine1";
		std::string d = "chaine2";
		
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

        std::cout << "-------------------------FLOAT-----------------------" << std::endl;
        //FLOATS
        float e = -42.42f;
		float f = 21.21f;

		std::cout << "e = " << e << ", f = " << f << std::endl;
		::swap( e, f );
		std::cout << "e = " << e << ", f = " << f << std::endl;
		std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
		std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	}

    std::cout << "-------------------------CLASS------------------------" << std::endl;

	{
		SomeClass	a(2), b(4);

		std::cout << "a = " << a << " | " << "b = " << b << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << " | " << "b = " << b << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	}

	return (0);

}