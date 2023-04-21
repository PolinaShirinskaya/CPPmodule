/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:50:11 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 14:03:33 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *start = new Data;
    start->str = "Yes... stop screaming";
    
    uintptr_t test1 = Serializer::serialize(start);
    std::cout << "Hey!\t\t" << test1<< std::endl;

    Data *test2 = Serializer::deserialize(test1);
    std::cout << "Heeeeey!\t" << test2->str << std::endl;

    delete start;
}