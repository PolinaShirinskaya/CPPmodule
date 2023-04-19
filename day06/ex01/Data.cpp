/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:56:26 by adian             #+#    #+#             */
/*   Updated: 2023/04/19 13:03:35 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"


Data::Data() { 
    this->str = "hey! u'r nice today!"; 
}

Data::Data(Data const &copy) {
    if(this != &copy)
        *this = copy;
}

Data::~Data() { return ;}

Data&	Data::operator=(Data const &data)
{
	if (this != &data) {
		this->str = data.str;
	}
	return (*this);
}

uintptr_t   Data::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*       Data::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
