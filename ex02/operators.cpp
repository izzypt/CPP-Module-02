/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:27:07 by simao             #+#    #+#             */
/*   Updated: 2023/07/14 23:27:26 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
The 4 arithmetic operators
*/

float operator+(Fixed one, Fixed two)
{
	return(one.toFloat() + two.toFloat());
}

float operator-(Fixed one, Fixed two)
{
	return(one.toFloat() - two.toFloat());
}

float operator*(Fixed one, Fixed two)
{
	return(one.toFloat() * two.toFloat());
}

float operator/(Fixed one, Fixed two)
{
	return(one.toFloat() / two.toFloat());
}

/*
The 6 comparison operators: >, <, >=, <=, == and !=.
*/
bool operator<(Fixed one, Fixed two)
{
	if (one.toFloat() < two.toFloat())
		return true;
	return false;
}

bool operator>(Fixed one, Fixed two)
{
	if (one.toFloat() > two.toFloat())
		return true;
	return false;
}

bool operator>=(Fixed one, Fixed two)
{
	if (one.toFloat() >= two.toFloat())
		return true;
	return false;
}

bool operator<=(Fixed one, Fixed two)
{
	if (one.toFloat() <= two.toFloat())
		return true;
	return false;
}

bool operator==(Fixed one, Fixed two)
{
	if (one.toFloat() == two.toFloat())
		return true;
	return false;
}

bool operator!=(Fixed one, Fixed two)
{
	if (one.toFloat() != two.toFloat())
		return true;
	return false;
}
