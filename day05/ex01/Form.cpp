/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:28:46 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 16:54:45 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() 
    : _name("NoName"), _signGrade(42), _executeGrade(42)
{
    std::cout
        << GREEN
        << "Form Default constructor called"
        << NORMAL << std::endl;
    _isSigned = false;
} 

Form::Form(std::string const &name, int sign, int execute) 
    : _name(name), _signGrade(sign), _executeGrade(execute)
{
    std::cout
        << GREEN
        << "Form Constructor called"
        << NORMAL << std::endl;
    
    _isSigned = false;
    if(_signGrade < 1 || _executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (_signGrade >150 || _executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy.getName()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
    std::cout
        << GREEN
        << "Form Copy constructor called"
        << NORMAL << std::endl;
    
    if(_signGrade < 1 || _executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (_signGrade >150 || _executeGrade > 150)
        throw Form::GradeTooLowException();
    if (this != &copy)
        *this = copy;
}

Form    &Form::operator=(const Form &copy) 
{ 
     std::cout
        << GREEN
        << "Form Copy assignment operator called"
        << NORMAL << std::endl;

    if (this == &copy)
        return (*this);

    if (copy.getSignGrade() < MAX_GRADE || copy.getExecuteGrade() < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (copy.getSignGrade() > MIN_GRADE || copy.getExecuteGrade() > MIN_GRADE)
		throw Form::GradeTooLowException();

    this->setName(copy.getName());
    this->_isSigned = copy.getIsSign();
    this->setSignGrade(copy.getSignGrade());
    this->setExecuteGrade(copy.getExecuteGrade());
    return (*this);
}

Form::~Form() { std::cout << GREEN << "Form Destructor called" << NORMAL << std::endl; }


//beSigned function
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned)
        throw Form::AlreadySignedException();
    if (bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else 
        throw Form::GradeTooLowException();
}


// GETTERS AND SETTERS
std::string const	Form::getName() const { return (_name); }

bool				Form::getIsSign() const { return (_isSigned); }

int					Form::getSignGrade() const { return (_signGrade); }

int					Form::getExecuteGrade() const { return (_executeGrade); }

void                Form::setName(std::string const name)
{
    std::string	*tmp = (std::string *)&this->_name;
	*tmp = name;
}

void	Form::setSignGrade(int grade)
{
	int	*tmp = (int *)&this->_signGrade;
	*tmp = grade;
}

void	Form::setExecuteGrade(int grade)
{
	int	*tmp = (int *)&this->_executeGrade;
	*tmp = grade;
}


//exceptions
char const	*Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high!!!");
}

char const	*Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low!!!");
}

char const	*Form::AlreadySignedException::what() const throw()
{
    return ("Form is already signed!!!");
}


// overload << operator
std::ostream    &operator<<(std::ostream &out,  const Form &form)
{
    out 
        << VIOLET
        << "Form: " << form.getName() << " | "
        << "Signed: ";
    if (form.getIsSign())
        out << "yes | ";
    else
        out << "no | ";
    out << "Grade to signed: " << form.getSignGrade() << " | ";
    out << "Grade to execute: " << form.getExecuteGrade() << NORMAL;
    return (out);
}

           