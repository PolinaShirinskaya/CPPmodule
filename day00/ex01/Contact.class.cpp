/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:10:56 by adian             #+#    #+#             */
/*   Updated: 2022/12/20 12:51:27 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) //конструктор по умолчанию
{
    firstName_ = "";
    lastName_ = "";
    nickName_ = "";
    phoneNumber_ = "";
    darkestSecret_ = "";
    return;
}

Contact::~Contact(void) //деструктор
{
    return;
}

//сеттер - присваивает значение переменным класса Contact
void Contact::set_field(std::string field, std::string value)
{
	if (field == "first name")
		firstName_ = value;
	else if (field == "last name")
		lastName_ = value;
	else if (field == "nickname")
		nickName_ = value;
	else if (field == "phone number")
		phoneNumber_ = value;
	else if (field == "darkest secret")
		darkestSecret_ = value;
}


//геттер - возвращает значение переменных класса Contact
std::string Contact::get_field(std::string field)
{
	if (field == "first name")
		return (firstName_);
	else if (field == "last name")
		return (lastName_);
	else if (field == "nickname")
		return (nickName_);
	else if (field == "phone number")
		return (phoneNumber_);
	else if (field == "darkest secret")
		return (darkestSecret_);
	return ("");
}

void Contact::PrintField(void)
{
	std::cout << "First name: " << firstName_ << std::endl;
	std::cout << "Last name: " << lastName_ << std::endl;
	std::cout << "Nickname: " << nickName_ << std::endl;
	std::cout << "Phone number: " << phoneNumber_ << std::endl;
	std::cout << "Darkest secret: " << darkestSecret_ << std::endl;
}

int Contact::IsEmpty(void)
{
	if (firstName_ == ""
		|| lastName_ == ""
		|| nickName_ == ""
		|| phoneNumber_ == ""
		|| darkestSecret_ == "")
		return 1;
	return 0;
}
