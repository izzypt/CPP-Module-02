/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:42:06 by simao             #+#    #+#             */
/*   Updated: 2023/08/28 16:17:39 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
- Constructor using initialization list.
*/
Fixed::Fixed() : fixedPointNum(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

/* 
- Destructor 
*/
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/*
- The copy constuctor takes a reference to another class object.
- It creates a copy of the referenced object.
- It is specially usefull when data is passed by value instead of reference.
*/
Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNum = obj.fixedPointNum;
}

/*
- The copy assignment operator assigns the value from another instance to the current instance
- It is invoked when an object is being assigned the value of another object using the assignment operator (=).
*/
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

