/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:26:55 by adian             #+#    #+#             */
/*   Updated: 2022/12/27 14:47:37 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int size, std::string nameHorde)
{
    int     i;
    Zombie  *Horde;

    i = 0;
    Horde = new Zombie[size + 1];
    while (i <= size)
    {
        Horde[i].setGetId(i);
        Horde[i].setName(nameHorde);
        ++i;
    }
    return (Horde);
}