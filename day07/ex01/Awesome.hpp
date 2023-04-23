/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:53:34 by adian             #+#    #+#             */
/*   Updated: 2023/04/22 18:54:17 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>

class Awesome
{
public:
	Awesome(): _n(42) {}

	int		get() const {return (this->_n);}

private:
	int	_n;
};

std::ostream	&operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get(); return (o);}

template<typename T>
void	print(T &x) {std::cout << x << std::endl;}

#endif