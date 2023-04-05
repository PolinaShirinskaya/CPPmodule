/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:41:41 by adian             #+#    #+#             */
/*   Updated: 2023/04/05 14:06:55 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
    std::cout << VIOLET << "Intern Default constructor called" << NORMAL << std::endl;
}

Intern::Intern(Intern const &copy)
{
    std::cout << VIOLET << "Yuo don't need copy Intern. There aren't attributes to  assign" << NORMAL << std::endl;
    (void)copy;
    return;
}

Intern  &Intern::operator=(Intern const &copy)
{
    std::cout << VIOLET << "Does not make sense to assign intern" << NORMAL << std::endl;
    (void)copy;
    return (*this);
}

Intern::~Intern() { std::cout << VIOLET << "Intern Destructor called" << NORMAL << std::endl; }


//Create form: give name and give target
AForm    *Intern::makeForm(std::string name, std::string target) const
{
    std::string formNames[3] = {"shrubbery creation form",
                                "robotomy request form",
                                "presidential pardon form"};

    AForm   *forms[3] = {new ShrubberyCreationForm(target),
                        new RobotomyRequestForm(target),
                        new PresidentialPardonForm(target)};

    std::string nameLowCase = "";
    for(int i = 0; i < name.size(); i++)
        nameLowCase += std::tolower(name[i]);

    AForm	*resForm = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (nameLowCase == formNames[i])
		{
			resForm = forms[i];
			std::cout << GREEN << "Intern creates " << resForm->getName() << NORMAL << std::endl;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (resForm != forms[i])
			delete forms[i];
	}

	if (!resForm)
		std::cout << RED << "Intern doesn't create " << name << NORMAL << std::endl;
	return (resForm);
}

