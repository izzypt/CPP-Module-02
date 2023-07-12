/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:42:06 by simao             #+#    #+#             */
/*   Updated: 2023/07/12 20:46:50 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
- Constructor using initialization list.
*/
Fixed::Fixed() : fixedPointNum(0) {}

/* 
- Destructor 
*/
Fixed::~Fixed() {}

/*
- The copy constuctor takes a reference to another class object.
- It creates a copy of the referenced object.
- It is specially usefull when data is passed by value instead of reference.
*/
Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNum = obj.fixedPointNum;
}

/*
- The copy assignment operator assigns the value from another instance to the current instance
- It is invoked when an object is being assigned the value of another object using the assignment operator (=).
*/
Fixed &Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
        this->fixedPointNum = obj.fixedPointNum;
        return *this;
}

const int Fixed::getRawBits(void)
{
    return this->fixedPointNum;    
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointNum = raw;
}

