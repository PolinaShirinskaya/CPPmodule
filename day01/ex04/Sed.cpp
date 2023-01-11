/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:05:18 by adian             #+#    #+#             */
/*   Updated: 2023/01/11 17:30:13 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string file_name) : _out_file(file_name)
{
    this->_in_file = file_name;
    this->_out_file = this->_out_file.append(".replace");
    this->_open = 0;
    return ;
}

Sed::~Sed(void)
{
    if (this->_open == 2)
        this->_out_fd.close();
    if (this->_open > 0)
        this->_in_fd.close();
}

int Sed::open(int flag)
{
    if (flag == 1)
    {
        _in_fd.open(_in_file);
        if (_in_fd.fail())
            return 0;
        _open += 1;
    }
    else if (flag == 2)
    {
         _out_fd.open(_out_file);
        if (_out_fd.fail())
            return 0;
        _open += 1;
    }
    return 1;
}

std::ifstream	*Sed::getFd(void)
{
	return (&_in_fd);
}

void	Sed::recording(std::string str)
{
	_out_fd << str;
}
