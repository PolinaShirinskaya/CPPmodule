/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:30:13 by adian             #+#    #+#             */
/*   Updated: 2023/04/04 19:42:47 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

# define SIGN_GRADE_ROBOTOMY 72
# define EXECUTE_GRADE_ROBOTOMY 45

class RobotomyRequestForm : public AForm
{
    private:
        std::string const   _target;

    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
    virtual ~RobotomyRequestForm();

    std::string const   getTarget() const;
    void                setTarget(std::string target);
    virtual void        execute(Bureaucrat const &executor) const;
};

#endif




