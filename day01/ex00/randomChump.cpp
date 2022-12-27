/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:40:52 by adian             #+#    #+#             */
/*   Updated: 2022/12/27 13:34:15 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Create a zombie ---> allocate memory on stack
//because it hasn't be returned

void	randomChump(std::string name)
{
	Zombie obj = Zombie(name);
	obj.announce();
}
