/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmstrx <hmstrx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:03:52 by sojammal          #+#    #+#             */
/*   Updated: 2025/08/23 19:16:36 by hmstrx           ###   ########.fr       */
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
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << '\n';
}

void Harl::debug()
{
	std::cout << "[DEBUG]" << '\n';
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << '\n';
}

void Harl::error()
{
	std::cout << "[ERROR]" << '\n';
	std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}

void Harl::info()
{
	std::cout << "[INFO]" << '\n';
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << '\n';
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