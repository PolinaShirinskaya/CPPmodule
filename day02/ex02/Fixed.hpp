/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:59:04 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 16:30:21 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _fixPoint;
        static const int    _fracBit;

    public:
        Fixed();
        Fixed(int const intNum);
        Fixed(const float floatNum);
        Fixed(const Fixed &copy);
        ~Fixed();
        Fixed&	operator= (const Fixed &copy);

        // overload arithmetics operators
		Fixed	operator+(Fixed const &copy) const;
		Fixed	operator-(Fixed const &copy) const;
		Fixed	operator*(Fixed const &copy) const;
		Fixed	operator/(Fixed const &copy) const;
        
        // overload comparison operators
		bool	operator==(Fixed const &copy) const;
		bool	operator!=(Fixed const &copy) const;
		bool	operator<=(Fixed const &copy) const;
		bool	operator>=(Fixed const &copy) const;
		bool	operator<(Fixed const &copy) const;
		bool	operator>(Fixed const &copy) const;

        // overload increment/decrement
		Fixed	operator ++ ();
	    Fixed	operator -- ();
	    Fixed	operator ++ (int unused);
	    Fixed	operator -- (int unused);
        
		int		getRawBits() const;
		void	setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        
        static Fixed		&min(Fixed &f1, Fixed &f2);
	    static Fixed		&max(Fixed &f1, Fixed &f2);
	    static Fixed const	&min(Fixed const &f1, Fixed const &f2);
	    static Fixed const	&max(Fixed const &f1, Fixed const &f2);

};

        std::ostream   &operator<<(std::ostream &out, const Fixed &fixed);
#endif