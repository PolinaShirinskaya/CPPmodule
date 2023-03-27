/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:56:16 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 13:17:26 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

# define NORMAL	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define VIOLET	"\033[1;35m"
# define CYAN	"\033[1;36m"


class Brain
{
    private:
		std::string* _ideas;
	
	public:
		Brain();
		Brain(const Brain &copy);
		Brain& operator=(const Brain &copy);
		~Brain();

		std::string const		&getIdeaByIndex(unsigned int const index) const;
		void					setIdeaByIndex(std::string idea, unsigned int index);
};

#endif