/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:21:10 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 16:55:37 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
   	try
    {
        Bureaucrat  bureaucrat("Bob", 5);
        Form        form1("26B", 20, 12);
        Form        form2("1A", 2, 3);
		Form		form3(form1);
		Form		form4;
		form4 = form2;

        std::cout << "---------------------------------------------------------------------------" << std::endl;

		std::cout << bureaucrat << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		std::cout << "---------------------------------------------------------------------------" << std::endl;

        bureaucrat.signForm(form1);
        bureaucrat.signForm(form2);

        std::cout << "---------------------------------------------------------------------------" << std::endl;

		bureaucrat.incrementGrade();
		bureaucrat.incrementGrade();
		bureaucrat.incrementGrade();

		std::cout << bureaucrat << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		std::cout << "---------------------------------------------------------------------------" << std::endl;

		bureaucrat.signForm(form2);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		std::cout << "---------------------------------------------------------------------------" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}
