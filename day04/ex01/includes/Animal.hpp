/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:21:52 by adian             #+#    #+#             */
/*   Updated: 2023/03/26 17:39:18 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

# define NORMAL	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define VIOLET	"\033[1;35m"
# define CYAN	"\033[1;36m"

class Animal
{
	protected:
		std::string	_type;
	
	public:
		Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &src);
		virtual ~Animal();

		std::string			getType()const;
		virtual void		makeSound() const;
};

#endif