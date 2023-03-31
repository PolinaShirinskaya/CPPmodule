/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:36:01 by adian             #+#    #+#             */
/*   Updated: 2023/03/31 14:24:30 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define NORMAL	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define VIOLET	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[1;37m"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat& operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        std::string const   getName() const;
        int                 getGrade() const;

        void                incrementGrade();
        void                decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &out, Bureaucrat const &src);

#endif