/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:03:48 by adian             #+#    #+#             */
/*   Updated: 2023/04/26 20:11:21 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

# ifndef EASYFIND_HPP
# error easyfind.tpp should be included from easyfind.hpp
# endif

template<typename T>
typename T::iterator    easyfind(T &array, int find)
{
    typename T::iterator it;

    it = std::find(array.begin(), array.end(), find);
    
    if (it == array.end())
        throw NoElementFoundException();
    return it;
    
};

#endif