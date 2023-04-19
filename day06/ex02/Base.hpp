/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:26:45 by adian             #+#    #+#             */
/*   Updated: 2023/04/19 13:57:40 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

class Base {
    public:
        virtual ~Base();
};

Base*   generate();
void    identify(Base *p);
void    identify(Base &p);

class   A : public Base {};
class   B : public Base {};
class   C : public Base {};

#endif