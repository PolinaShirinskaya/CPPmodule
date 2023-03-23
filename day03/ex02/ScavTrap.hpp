/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:53:20 by adian             #+#    #+#             */
/*   Updated: 2023/03/22 17:40:45 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap		&operator=(const ScavTrap &copy);
        
		void			attack(const std::string& target);
		void			guardGate(); 
        
};
std::ostream& operator<<(std::ostream &out, ScavTrap const &scavtrap);

#endif