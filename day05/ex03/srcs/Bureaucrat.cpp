/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:45:13 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 18:42:39 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"


Bureaucrat::Bureaucrat() 
    : _name("No")
{
    std::cout
        << GREEN
        << "Bureaucrat default constructor called"
        << NORMAL << std::endl;
    _grade = MIN_GRADE;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) 
    : _name(name)
{
    std::cout
        << GREEN
        << "Bureaucrat constructor called"
        << NORMAL << std::endl;

    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) 
    : _name(copy.getName())
{
    std::cout
        << GREEN
        << "Bureaucrat Copy constructor called"
        << NORMAL << std::endl;
    if (copy.getGrade() > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    if (copy.getGrade() < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();

    if (this != &copy)
        *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) 
{
    std::cout
        << GREEN
        << "Bureaucrat Copy assignment called"
        << NORMAL << std::endl;

    if (this == &copy)
        return (*this);
    if (copy.getGrade() > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    if (copy.getGrade() < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();

    this->_grade = copy.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << GREEN << "Bureaucrat Destructor called" << NORMAL << std::endl; }

std::string const   Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }


void    Bureaucrat::incrementGrade()
{
    std::cout
        << VIOLET
        << "Bureaucrat wanna increment grade"
        << NORMAL << std::endl;
    if (this->_grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
    this->_grade -= 1;
}

void    Bureaucrat::decrementGrade()
{
    std::cout
        << VIOLET
        << "Bureaucrat wanna decrement grade"
        << NORMAL << std::endl;
    if (this->_grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
    this->_grade += 1;
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high!!!");
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low!!!");
}

std::ostream    &operator<<(std::ostream &out, Bureaucrat const &src)
{
    out
        << BLUE
        << src.getName()
        << ", bureaucrat grade "
        << src.getGrade() << "."
        << NORMAL << std::endl;
    return (out);
}

void    Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception &excecption)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName();
        std::cout << " because " << excecption.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout
            << BLUE << this->getName()
            << " execute " << form.getName()
            << NORMAL << std::endl;

    }
    catch(const std::exception &exc)
    {
        std::cout
            << BLUE << this->getName()
            << " can't executed " << form.getName()
            << NORMAL << std::endl;
        std::cout << " because " << exc.what() << NORMAL << std::endl;
    }
}