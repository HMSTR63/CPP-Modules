/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:13:49 by sojammal          #+#    #+#             */
/*   Updated: 2025/10/17 00:31:35 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


/*
	The Formula To Calculat the triangle is to split them to 3 areas 
	with the pos we need to find 
	ex :
	A -> x = 0 y = 0
	B -> x = 10 y = 0
	C -> x = 0 y = 10
	P -> x = 2 y = 2

	we split them to 3 areas 
	PAB + PBC + PCA == ABC 

	this is the formula
		Area=∣(x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​))∣/2
*/

int main(void)
{
	Point A(0, 0);
	Point B(10, 0);
	Point C(0, 10);
	Point P(2, 2);

	std::cout << bsp(A, B, C, P) << std::endl;
}
