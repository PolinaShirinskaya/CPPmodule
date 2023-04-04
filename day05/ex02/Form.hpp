/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:02:02 by adian             #+#    #+#             */
/*   Updated: 2023/04/03 13:37:45 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _executeGrade;

    public:
        Form();
        Form(std::string const &name, int sign, int execute);
        ~Form();
        Form(const Form &copy);
        Form&   operator=(const Form &copy);

        std::string const   getName() const;
        bool                getIsSign() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;

        void                beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                char const *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                char const *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &out, const Form &form);

#endif