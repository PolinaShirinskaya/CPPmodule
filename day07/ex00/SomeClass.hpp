/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SomeClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:52:49 by adian             #+#    #+#             */
/*   Updated: 2023/04/21 16:56:36 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOMECLASS_HPP
# define SOMECLASS_HPP

# include <iostream>

class SomeClass {
    private:
        int _n;
    
    public:
        SomeClass(): _n(0) {}
	    SomeClass(int n) : _n(n) {}
	    SomeClass	&operator=(SomeClass &a) {_n = a._n; return *this;}
	    bool	operator==(SomeClass const &src) const {return (this->_n == src._n);}
	    bool	operator!=(SomeClass const &src) const {return (this->_n != src._n);}
	    bool	operator>(SomeClass const &src) const {return (this->_n > src._n);}
	    bool	operator<(SomeClass const &src) const {return (this->_n < src._n);}
	    bool	operator>=(SomeClass const &src) const {return (this->_n >= src._n);}
	    bool	operator<=(SomeClass const &src) const {return (this->_n <= src._n);}
	    int		get_n() const {return (_n);}

};

std::ostream	&operator<<(std::ostream &out, const SomeClass &a) {out << a.get_n(); return (out);}


#endif