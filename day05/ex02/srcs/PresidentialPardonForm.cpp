/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:54:08 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 20:00:23 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Creation Form", SIGN_GRADE_PRESIDENTIAL, EXECUTE_GRADE_PRESIDENTIAL)
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	this->setTarget("default_target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) 
    : AForm("Presidential Creation Form", SIGN_GRADE_PRESIDENTIAL, EXECUTE_GRADE_PRESIDENTIAL)
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) 
    : AForm("Presidential Creation Form", SIGN_GRADE_PRESIDENTIAL, EXECUTE_GRADE_PRESIDENTIAL)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
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

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void	PresidentialPardonForm::setTarget(std::string target)
{
	std::string	*tmp = (std::string *)&this->_target;
	*tmp = target;
}

std::string const	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSign() == false)
		throw AForm::NotSignedFormException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooHighException();
	
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}