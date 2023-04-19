/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:50:11 by adian             #+#    #+#             */
/*   Updated: 2023/04/19 13:13:01 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
    Data      obj;
    Data      *ptr = NULL;
    uintptr_t num;

    std::cout
        << "Test Object before serialize (* ->> unsigned int):"
        << obj.str
        << std::endl;
    num = obj.serialize(&obj);

    std::cout
        << "Test Object after serialize (* ->> unsigned int):"
        << num
        << std::endl;
    ptr = obj.deserialize(num);
    std::cout
        << "String after deserialize (unsigned int ->> *):"
        << ptr->str
        << std::endl;
}