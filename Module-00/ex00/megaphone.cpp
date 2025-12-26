/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 03:50:16 by sojammal          #+#    #+#             */
/*   Updated: 2025/10/16 19:47:51 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int c, char **v)
{
	if (c < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	else
	{
		int h = 1;
		while (h < c)
		{
			int m = 0;
			while (v[h][m])
				std::cout << (char)toupper(v[h][m++]);
			h++;
		}
		std::cout << '\n';
	}

}

