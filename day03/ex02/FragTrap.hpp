/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:21:44 by adian             #+#    #+#             */
/*   Updated: 2023/03/23 19:09:22 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap    &operator=(const FragTrap &copy);

        void        highFivesGuys();
        void        attack(const std::string& target);
};

std::ostream& operator << (std::ostream &out, const FragTrap &fragtrap);

#endif