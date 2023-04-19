/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:55:17 by adian             #+#    #+#             */
/*   Updated: 2023/04/19 12:56:06 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class	Data
{
	public:
		std::string	str;

		Data(void);
		Data(Data const &copy);
		Data&		operator=(Data const &data);
		~Data(void);

		uintptr_t	serialize(Data *ptr);
		Data*		deserialize(uintptr_t raw);
};

#endif