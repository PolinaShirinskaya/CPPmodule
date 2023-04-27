/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:41:05 by adian             #+#    #+#             */
/*   Updated: 2023/04/27 17:07:54 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {
    private:
        unsigned int        _maxSize;
        std::vector<int>    _intVector;

    public:
        Span();
        Span(unsigned int N);
        Span(Span const &copy);
        Span    &operator=(Span const &copy);
        ~Span();

        size_t          getSize() const;
        int const       &getElem(unsigned int index) const;

        void            addNumber(int num);
        void            addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int    shortestSpan();
        unsigned int    longestSpan();

        class InvalidIndexException : public std::exception 
        {
            virtual char const *what() const throw();
        };

        class VectorIsFullException : public std::exception
        {
            virtual char const *what() const throw();
        };

        class NoSpaceInVectorException : public std::exception 
        {
            virtual char const *what() const throw();
        };

        class TooFewElementsException : public std::exception 
        {
            virtual char const *what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &outstream, Span const &src);

#endif