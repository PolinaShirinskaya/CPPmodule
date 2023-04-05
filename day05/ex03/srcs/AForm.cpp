/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:05:19 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 17:59:26 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() 
    : _name("NoName"), _signGrade(42), _executeGrade(42)
{
    std::cout
        << GREEN
        << "AForm Default constructor called"
        << NORMAL << std::endl;
    _isSigned = false;
} 

AForm::AForm(std::string const &name, int sign, int execute) 
    : _name(name), _signGrade(sign), _executeGrade(execute)
{
    std::cout
        << GREEN
        << "AForm Constructor called"
        << NORMAL << std::endl;
    
    _isSigned = false;
    if(_signGrade < 1 || _executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (_signGrade >150 || _executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : _name(copy.getName()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
    std::cout
        << GREEN
        << "AForm Copy constructor called"
        << NORMAL << std::endl;
    
    if(_signGrade < 1 || _executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (_signGrade >150 || _executeGrade > 150)
        throw AForm::GradeTooLowException();
    if (this != &copy)
        *this = copy;
}

AForm    &AForm::operator=(const AForm &copy) 
{ 
     std::cout
        << GREEN
        << "AForm Copy assignment operator called"
        << NORMAL << std::endl;

    if (this == &copy)
        return (*this);

    if (copy.getSignGrade() < MAX_GRADE || copy.getExecuteGrade() < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (copy.getSignGrade() > MIN_GRADE || copy.getExecuteGrade() > MIN_GRADE)
		throw AForm::GradeTooLowException();

    this->setName(copy.getName());
    this->_isSigned = copy.getIsSign();
    this->setSignGrade(copy.getSignGrade());
    this->setExecuteGrade(copy.getExecuteGrade());
    return (*this);
}

AForm::~AForm() { std::cout << GREEN << "AForm Destructor called" << NORMAL << std::endl; }


//beSigned function
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned)
        throw AForm::AlreadySignedException();
    if (bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else 
        throw AForm::GradeTooLowException();
}


// GETTERS AND SETTERS
std::string const	AForm::getName() const { return (_name); }

bool				AForm::getIsSign() const { return (_isSigned); }

int					AForm::getSignGrade() const { return (_signGrade); }

int					AForm::getExecuteGrade() const { return (_executeGrade); }

void                AForm::setName(std::string const name)
{
    std::string	*tmp = (std::string *)&this->_name;
	*tmp = name;
}

void	AForm::setSignGrade(int grade)
{
	int	*tmp = (int *)&this->_signGrade;
	*tmp = grade;
}

void	AForm::setExecuteGrade(int grade)
{
	int	*tmp = (int *)&this->_executeGrade;
	*tmp = grade;
}


//exceptions
char const	*AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade is too high!!!");
}

char const	*AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade is too low!!!");
}

char const	*AForm::AlreadySignedException::what() const throw()
{
    return ("AForm is already signed!!!");
}

char const	*AForm::NotSignedFormException::what() const throw()
{
    return ("AForm isn't signed, it can't be execute!!!");
}


// overload << operator
std::ostream    &operator<<(std::ostream &out,  const AForm &form)
{
    out 
        << VIOLET
        << "AForm: " << form.getName() << " | "
        << "Signed: ";
    if (form.getIsSign())
        out << "yes | ";
    else
        out << "no | ";
    out << "Grade to signed: " << form.getSignGrade() << " | ";
    out << "Grade to execute: " << form.getExecuteGrade() << NORMAL;
    return (out);
}

           