/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:31:54 by adian             #+#    #+#             */
/*   Updated: 2022/12/20 12:49:14 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) 
{
    set_count_contacts(-1, 0);
    set_count_contacts(0, 1);
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

//присваевает значение для numberContact и следит за лимитом
void PhoneBook::set_count_contacts(int num, int flag)
{
    if (flag == 0)
        PhoneBook::numberContacts_ = num;
    else
        PhoneBook::rewriteContact_ = num;
}

//возвращает колличество numberContact  и следит за лимитом
int PhoneBook::get_count_contacts(int flag)
{
    if (flag == 1 && PhoneBook::rewriteContact_)
        return 7;
    return (PhoneBook::numberContacts_);
}

void PhoneBook::AddContact(void)
{
    if (7 <= get_count_contacts(0))
    {
        set_count_contacts(-1, 0);
        set_count_contacts(1, 1);
    }
    set_count_contacts(get_count_contacts(0) + 1, 0);
    std::cout << "Add contact: " << PhoneBook::numberContacts_ + 1 << std::endl;
    RequestInfo("first name");
    RequestInfo("last name");
    RequestInfo("nickname");
    RequestInfo("phone number");
    RequestInfo("darkest secret");
    if (contact_[PhoneBook::numberContacts_].IsEmpty())
    {
        std::cout << "Try again" << std::endl;
        PhoneBook::numberContacts_ -= 1;
        return;
    }
    std::cout << "Contact added" << std::endl;
}

void PhoneBook::RequestInfo(std::string message)
{
    std::string str;

    std::cout << "Enter your " << message << ": " << std::endl;
    std::getline(std::cin >> std::ws, str);
    if (std::cin.eof())
        return;
    contact_[PhoneBook::numberContacts_].set_field(message, str);
}

std::string PhoneBook::get_format(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void PhoneBook::SearchContact(void)
{
    std::string str;
    int			num;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i <= get_count_contacts(1); i++)
	{
		std::cout << "|         " << i + 1 << "|";
		std::cout << std::setw(10) << std::right << get_format(contact_[i].get_field("first name")) << "|";
		std::cout << std::setw(10) << std::right << get_format(contact_[i].get_field("last name")) << "|";
		std::cout << std::setw(10) << std::right << get_format(contact_[i].get_field("nickname")) << "|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "Enter index: ";
	std::cin >> str;
	if (std::cin.eof())
		return;
	if (str.length() != 1 || !isdigit(str[0]))
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	num = (str[0] - '0') - 1;
	if ( num < 0 || num > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (contact_[num].IsEmpty())
	{
		std::cout << "Contact is empty" << std::endl;
		return;
	}
	else
		contact_[num].PrintField();
}
