/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:03:11 by adian             #+#    #+#             */
/*   Updated: 2023/03/26 19:09:18 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

# define NORMAL	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define VIOLET	"\033[1;35m"
# define CYAN	"\033[1;36m"

class WrongAnimal
{
	protected:
		std::string	_type;
	
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal &src);
		//no virtual here
        ~WrongAnimal();

		std::string	getType()const;

		//this function isn't virtual here
        void		makeSound() const; 
};

#endif