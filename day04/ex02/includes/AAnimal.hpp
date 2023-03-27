/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:21:52 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 15:04:56 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

# define NORMAL	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define VIOLET	"\033[1;35m"
# define CYAN	"\033[1;36m"

class AAnimal
{
	protected:
		std::string	_type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal& operator=(const AAnimal &src);
		virtual ~AAnimal();

		std::string			getType()const;
		virtual void		makeSound() const = 0;
};

#endif