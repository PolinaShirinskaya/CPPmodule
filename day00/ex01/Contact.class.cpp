/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:10:56 by adian             #+#    #+#             */
/*   Updated: 2022/12/19 19:24:18 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) //конструктор по умолчанию
{
    _firstName = "";
    _lastName = "";
    _nickName = "";
    _phoneNumber = "";
    _darkestSecret = "";
    return;
}

Contact::~Contact(void)
{
    return;
}

void Contact::_setField(std::string field, std::string value)
{
	if (field == "first name")
		_firstName = value;
	else if (field == "last name")
		_lastName = value;
	else if (field == "nickname")
		_nickName = value;
	else if (field == "phone number")
		_phoneNumber = value;
	else if (field == "darkest secret")
		_darkestSecret = value;
}

std::string Contact::_getField(std::string field)
{
	if (field == "first name")
		return (_firstName);
	else if (field == "last name")
		return (_lastName);
	else if (field == "nickname")
		return (_nickName);
	else if (field == "phone number")
		return (_phoneNumber);
	else if (field == "darkest secret")
		return (_darkestSecret);
	return ("");
}

void Contact::_printField(void)
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

int Contact::_isEmpty(void)
{
	if (_firstName == ""
		|| _lastName == ""
		|| _nickName == ""
		|| _phoneNumber == ""
		|| _darkestSecret == "")
		return 1;
	return 0;
}