/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:01:11 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 13:52:05 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct Data {
	std::string str;
} Data;

class	Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &copy);
		Serializer	&operator=(Serializer const &copy);
		~Serializer(void);
	
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif