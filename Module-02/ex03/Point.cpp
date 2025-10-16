/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:31:58 by sojammal          #+#    #+#             */
/*   Updated: 2025/10/16 22:37:08 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{

}

Point::Point(Point const &op) : _x(op._x), _y(op._y)
{

}

Point	&Point::operator=(Point const &op)
{
	(void)op;
	return *this;
}

Fixed	Point::getX() const
{
	return this->_x;
}

Fixed	Point::getY() const
{
	return this->_y;
}

Point::~Point()
{

}

