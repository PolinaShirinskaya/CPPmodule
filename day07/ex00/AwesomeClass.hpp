/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwesomeClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:19:18 by adian             #+#    #+#             */
/*   Updated: 2023/04/22 19:13:03 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOMECLASS_HPP
# define AWESOMECLASS_HPP

# include <iostream>

class AwesomeClass {
    private:
        int _n;
    
    public:
        AwesomeClass(): _n(0) {}
	    AwesomeClass(int n) : _n(n) {}
	    AwesomeClass	&operator=(AwesomeClass &a) {_n = a._n; return *this;}
	    bool	operator==(AwesomeClass const &rhs) const {return (this->_n == rhs._n);}
	    bool	operator!=(AwesomeClass const &rhs) const {return (this->_n != rhs._n);}
	    bool	operator>(AwesomeClass const &rhs) const {return (this->_n > rhs._n);}
	    bool	operator<(AwesomeClass const &rhs) const {return (this->_n < rhs._n);}
	    bool	operator>=(AwesomeClass const &rhs) const {return (this->_n >= rhs._n);}
	    bool	operator<=(AwesomeClass const &rhs) const {return (this->_n <= rhs._n);}
	    int		get_n() const {return (_n);}

};

std::ostream	&operator<<(std::ostream &o, const AwesomeClass &a) {o << a.get_n(); return (o);}


#endif