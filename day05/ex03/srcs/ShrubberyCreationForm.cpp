/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:35:21 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 19:36:06 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", SIGN_GRADE_SHRUBBERY, EXECUTE_GRADE_SHRUBBERY)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	this->setTarget("default_target");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) 
    : AForm("Shrubbery Creation Form", SIGN_GRADE_SHRUBBERY, EXECUTE_GRADE_SHRUBBERY)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) 
    : AForm("Shrubbery Creation Form", SIGN_GRADE_SHRUBBERY, EXECUTE_GRADE_SHRUBBERY)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);

	this->setName(copy.getName());
	this->_isSigned = copy.getIsSign();

	if (copy.getSignGrade() < MAX_GRADE || copy.getExecuteGrade() < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (copy.getSignGrade() > MIN_GRADE || copy.getExecuteGrade() > MIN_GRADE)
		throw AForm::GradeTooLowException();

	this->setSignGrade(copy.getSignGrade());
	this->setExecuteGrade(copy.getExecuteGrade());
	this->setTarget(copy.getTarget());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	std::string	*tmp = (std::string *)&this->_target;
	*tmp = target;
}

std::string const	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSign() == false)
		throw AForm::NotSignedFormException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooHighException();
	
	std::ofstream	outputFile;
	std::string		nameFile = this->getTarget();
	
	nameFile.append("_shrubbery");
	outputFile.open(nameFile.c_str()); //c_str - string to array

	if (!outputFile.is_open())
		throw ShrubberyCreationForm::OpenFileException();

	outputFile << TREE_PICTURE << std::endl;
	outputFile.close();
}

char const	*ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return ("File can't be opened!!!");
}
