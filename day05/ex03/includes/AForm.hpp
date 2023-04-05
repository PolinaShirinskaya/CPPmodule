/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:04:11 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 18:44:05 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        std::string const   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _executeGrade;

    public:
        AForm();
        AForm(std::string const &name, int sign, int execute);
        virtual ~AForm();
        AForm(const AForm &copy);
        AForm&   operator=(const AForm &copy);

        std::string const   getName() const;
        bool                getIsSign() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;
        void                setName(std::string const name);
        void                setIsSigned();
        void                setSignGrade(int grade);
        void                setExecuteGrade(int grade);

        void                beSigned(const Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const &executor) const = 0;

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

        class AlreadySignedException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };

        class NotSignedFormException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &out, const AForm &form);

#endif