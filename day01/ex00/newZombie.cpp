/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:38:03 by adian             #+#    #+#             */
/*   Updated: 2022/12/27 13:24:42 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Creating a new zombie ----> allocate memory on HEAP
//because it has to be returned

Zombie *newZombie(std::string name)
{
    return (new Zombie(name));
}
