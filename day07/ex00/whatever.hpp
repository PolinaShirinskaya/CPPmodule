/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:35:26 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 16:50:20 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void    swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
const T& min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template<typename T>
const T& max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif