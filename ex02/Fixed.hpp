/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:28:02 by simao             #+#    #+#             */
/*   Updated: 2023/07/14 23:33:53 by simao            ###   ########.fr       */
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
        Fixed& operator=(const Fixed& obj);
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);
        ~Fixed();
        static Fixed& max(Fixed &one, Fixed &two);
        static Fixed& min(Fixed &one, Fixed &two);
        static const Fixed& max(const Fixed &one, const Fixed  &two);
        static const Fixed& min(const Fixed &one, const Fixed  &two);
        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
        int		toInt( void ) const;
        float	toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &val);
bool operator>(const Fixed one, const Fixed two);
bool operator<(const Fixed one, const Fixed two);
bool operator>=(const Fixed one, const Fixed two);
bool operator<=(const Fixed one, const Fixed two);
bool operator==(const Fixed one, const Fixed two);
bool operator!=(const Fixed one, const Fixed two);
float operator+(const Fixed one, const Fixed two);
float operator-(const Fixed one, const Fixed two);
float operator*(const Fixed one, const Fixed two);
float operator/(const Fixed one, const Fixed two);


#endif