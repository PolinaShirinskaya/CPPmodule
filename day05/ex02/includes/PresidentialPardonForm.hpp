/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:54:02 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 19:56:17 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define SIGN_GRADE_PRESIDENTIAL 25
# define EXECUTE_GRADE_PRESIDENTIAL 5

class PresidentialPardonForm : public AForm
{
    private:
        std::string const   _target;

    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
    virtual ~PresidentialPardonForm();

    std::string const   getTarget() const;
    void                setTarget(std::string target);
    virtual void        execute(Bureaucrat const &executor) const;
};

#endif