/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:03:52 by sojammal          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:25 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{	
}


void Harl::warning()
{
	std::cout << "[WARNING]" << '\n';
}

void Harl::debug()
{
	std::cout << "[DEBUG]" << '\n';
}

void Harl::error()
{
	std::cout << "[ERROR]" << '\n';
}

void Harl::info()
{
	std::cout << "[INFO]" << '\n';
}

void Harl::comlain(std::string level)
{
	std::string tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*hold[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int h = 0;
	while (h < 4)
	{
		if (level.compare(tab[h]) == 0)
			return (this->*hold[h])();
		h++;
	}
}