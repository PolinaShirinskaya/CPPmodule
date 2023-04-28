/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:33:06 by adian             #+#    #+#             */
/*   Updated: 2023/04/28 15:01:37 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack (MutantStack<T> const &copy);
        MutantStack<T>     &operator=(MutantStack<T> const &copy);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator                iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
		
        iterator                begin();
		iterator                end();

		reverse_iterator        rbegin(); 
		reverse_iterator        rend(); 
};

# include "MutantStack.tpp"

#endif 