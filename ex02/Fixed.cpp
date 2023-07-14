/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:21:46 by simao             #+#    #+#             */
/*   Updated: 2023/07/14 23:34:59 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0) 
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNum = obj.fixedPointNum;
}

Fixed::Fixed(const int num) 
{
    //std::cout << "Int constructor called" << std::endl;
    this->fixedPointNum = (num * (1 << Fixed::fractional_bit));
}

Fixed::Fixed(const float num) 
{
    //std::cout << "Float constructor called" << std::endl;
    this->fixedPointNum = roundf(num * (1 << Fixed::fractional_bit));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &obj)
        this->fixedPointNum = obj.fixedPointNum;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointNum;    
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointNum = raw;
}

int Fixed::toInt(void) const
{
	return this->fixedPointNum / (1 << Fixed::fractional_bit);
}

float Fixed::toFloat(void) const
{
	return (float)this->fixedPointNum / (1 << Fixed::fractional_bit);
}

std::ostream& operator<<(std::ostream& out, const Fixed &val)
{
	out << val.toFloat();
	return out;
}

/*
The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
*/
Fixed Fixed::operator++()
{
	this->fixedPointNum++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedPointNum++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->fixedPointNum--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedPointNum--;
	return (tmp);
}

/*
Limits
*/

Fixed const &Fixed::max(Fixed const &one, Fixed const &two)
{
	if (one.toFloat() > two.toFloat())
		return (one);
	return(two);
}
Fixed const &Fixed::min(Fixed const &one, Fixed const &two)
{
	if (one.toFloat() > two.toFloat())
		return (two);
	return(one);
}

Fixed& Fixed::max(Fixed &one, Fixed &two)
{
	if (one.toFloat() > two.toFloat())
		return (one);
	return(two);
}

Fixed& Fixed::min(Fixed &one, Fixed &two)
{
	if (one.toFloat() > two.toFloat())
		return (two);
	return(one);
}