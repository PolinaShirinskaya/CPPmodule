/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:40:49 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 13:16:28 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	
	public:
		Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &src);
		virtual ~Cat();

		virtual void	makeSound() const;
		Brain			&getBrain() const;
		void			showIdeaFrom(unsigned int index) const;
		void			setIdeaIn(std::string idea, unsigned int index);
};
#endif