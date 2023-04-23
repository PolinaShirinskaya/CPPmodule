/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:21:10 by adian             #+#    #+#             */
/*   Updated: 2023/04/23 14:32:10 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void    iter(T *addr, size_t lenArray, void (*func)(T &))
{
    for (size_t i = 0; i < lenArray; i++)
        (*func)(addr[i]);
}

#endif