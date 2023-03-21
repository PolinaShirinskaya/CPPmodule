/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:50:25 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 12:58:10 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int                 _fixPoint;
        static const int    _fracBit;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        ~Fixed();
        Fixed&	operator= (const Fixed &copy);

		int		getRawBits() const;
		void	setRawBits(int const raw);

};

#endif