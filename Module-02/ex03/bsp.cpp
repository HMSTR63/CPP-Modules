/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:37:27 by sojammal          #+#    #+#             */
/*   Updated: 2025/10/16 23:10:40 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	ft_area(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed part_1 = p1.getX() * (p2.getY() - p3.getY());
	Fixed part_2 = p2.getX() * (p3.getY() - p1.getY());
	Fixed part_3 = p3.getX() * (p1.getY() - p2.getY());

	Fixed area_res = part_1 + part_2 + part_3;

	if (area_res < Fixed(0))
		area_res = area_res * Fixed(-1);

	area_res = area_res / Fixed(2);
	
	return area_res;
}

bool  bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_ABC = ft_area(a, b, c);
	Fixed area_PAB = ft_area(point, a, b);
	Fixed area_PBC = ft_area(point, b, c);
	Fixed area_PCA = ft_area(point, c, a);

	if (area_PAB == Fixed(0) || area_PBC == Fixed(0) || area_PCA == Fixed(0))
		return false;
	return area_ABC == area_PAB + area_PBC + area_PCA;
}

