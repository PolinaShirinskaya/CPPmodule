/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:45:47 by adian             #+#    #+#             */
/*   Updated: 2023/03/27 14:41:17 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &src);
		virtual ~Dog();

		virtual void	makeSound() const;
		Brain			&getBrain() const;
		void			showIdeaFrom(unsigned int index) const;
		void			setIdeaIn(std::string idea, unsigned int index);
};
#endif