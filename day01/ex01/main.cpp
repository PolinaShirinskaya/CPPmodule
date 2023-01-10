/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:43:08 by adian             #+#    #+#             */
/*   Updated: 2023/01/10 11:58:18 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int     size_horde;
    int     cout;

    size_horde = 3;
    cout = 0;
    Zombie *horde = zombieHorde(size_horde, "Zombie_with_name");
    while (cout <= size_horde)
        horde[cout++].announce();
    delete [] horde;
    return 0;
}
