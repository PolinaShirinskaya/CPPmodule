/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:36:09 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 19:53:04 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Creation Form", SIGN_GRADE_ROBOTOMY, EXECUTE_GRADE_ROBOTOMY)
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	this->setTarget("default_target");
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) 
    : AForm("Robotomy Creation Form", SIGN_GRADE_ROBOTOMY, EXECUTE_GRADE_ROBOTOMY)
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) 
    : AForm("Robotomy Creation Form", SIGN_GRADE_ROBOTOMY, EXECUTE_GRADE_ROBOTOMY)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
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

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	std::string	*tmp = (std::string *)&this->_target;
	*tmp = target;
}

std::string const	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSign() == false)
		throw AForm::NotSignedFormException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooHighException();
	
	std::srand(std::time(NULL));
    std::cout << "BEEP BOOP BEEP BOOP BEEP" << std::endl;
	if (std::rand() % 100 < 50)
        std::cout << this->getTarget() << " robotomized not successfully" << std::endl;
	else
        std::cout << this->getTarget() << " robotomized successfully" << std::endl;
}