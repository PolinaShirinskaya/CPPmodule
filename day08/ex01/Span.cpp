/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:50:37 by adian             #+#    #+#             */
/*   Updated: 2023/04/27 18:37:43 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    std::cout << "Default constructor without parametrs is called" << std::endl;
    _maxSize = 0;
}

Span::Span(unsigned int N)
{
    std::cout << "Default constructor is called" << std::endl;
    _maxSize = N;
}

Span::Span(Span const &copy)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = copy;
}

Span    &Span::operator=(Span const &copy)
{
    std::cout << "Copy assignment is called" << std::endl;
    if (this == &copy)
        return (*this);
    _maxSize = copy._maxSize;
    _intVector = copy._intVector;
    return (*this);
}

Span::~Span() { std::cout << "Destructor is called" << std::endl; }

size_t Span::getSize() const { return (_intVector.size()); }

int const   &Span::getElem(unsigned int index) const
{
    if (index >= this->_intVector.size())
        throw Span::InvalidIndexException();
    return (_intVector[index]);
}

void    Span::addNumber(int number)
{
    if (_intVector.size() == _maxSize)
        throw Span::VectorIsFullException();
    _intVector.push_back(number);
}

void    Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>    tmp(begin, end);

    if ((_maxSize - _intVector.size()) < tmp.size())
        throw Span::NoSpaceInVectorException();
    std::copy(tmp.begin(), tmp.end(), std::back_inserter(_intVector));
}

unsigned int    Span::shortestSpan()
{
    if(_intVector.size() < 2)
        throw Span::TooFewElementsException();

    std::vector<int>    tmp = _intVector;
    unsigned int    min;
    unsigned int    result;

    std::sort(tmp.begin(), tmp.end());
    result = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end() - 1; ++it)
    {
        min = *(it +  1) - *it;
        if (result > min)
            result = min;
        if (!result)
            return result;
    }
    return result;
}

unsigned int    Span::longestSpan()
{
    if(_intVector.size() < 2)
        throw Span::TooFewElementsException();

    std::vector<int>    tmp = _intVector;

    std::sort(tmp.begin(), tmp.end());

    unsigned int result = *(tmp.end() - 1) - *tmp.begin();

    return result;
}

char const	*Span::InvalidIndexException::what() const throw()
{
	return ("Invalid index!!!");
}

char const	*Span::VectorIsFullException::what() const throw()
{
	return ("Container is full. New item cannot be added!!!");
}

char const	*Span::NoSpaceInVectorException::what() const throw()
{
    return ("Container hasn't space !!!");
}

char const	*Span::TooFewElementsException::what() const throw()
{
	return ("There're not enought elems!!!");
}

std::ostream	&operator<<(std::ostream &outstream, Span const &src)
{
	outstream << "Span[ " << src.getSize() << " ]\n";
	outstream << "Span >>> intVector: ";
	for (unsigned int i = 0; i < src.getSize(); i++)
	{
		if (i == src.getSize() - 1)
			outstream << src.getElem(i);
		else
			outstream << src.getElem(i) << ", ";
	}
	return (outstream);
}
