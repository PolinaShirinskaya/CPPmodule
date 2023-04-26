/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:40:35 by adian             #+#    #+#             */
/*   Updated: 2023/04/26 20:13:16 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iterator>
# include <algorithm>

template<typename T>
typename T::iterator    easyfind(T &array, int find);

class NoElemenFoundException : public std::exception
{
    virtual char const *what() const throw()
    {
        return ("Element is not found in the array");
    }
}

# include "easyfind.tpp"

#endif