/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:42:10 by simao             #+#    #+#             */
/*   Updated: 2023/07/14 01:38:53 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

/* Libraries */

#include <iostream>
#include <string>
#include <cmath>

/* Colors */

#define BLUE			"\e[0;34m"
#define GREEN			"\e[0;32m"
#define MAGENTA			"\e[0;35m"
#define RED				"\e[0;31m"
#define RESET			"\e[0m"

/* Classes */

class Fixed
{
    private:
        int fixedPointNum;
        static const int fractional_bit = 8;
    public:
        Fixed(); // default constructor
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &obj); // copy constructor
        Fixed& operator=(const Fixed &obj); // assignment operator
        ~Fixed(); // destructor
        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
        int		toInt( void ) const;
        float	toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &val);

#endif