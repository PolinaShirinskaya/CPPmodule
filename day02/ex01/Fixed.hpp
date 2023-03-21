/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:59:04 by adian             #+#    #+#             */
/*   Updated: 2023/03/21 13:03:27 by adian            ###   ########.fr       */
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

		int		getRawBits() const;
		void	setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

};

        std::ostream   &operator<<(std::ostream &out, const Fixed &fixed);
#endif