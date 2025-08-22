/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 04:54:22 by sojammal          #+#    #+#             */
/*   Updated: 2025/08/22 05:04:28 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private :
		void debug();
		void info();
		void warning();
		void error();
	public :
		void comlain(std::string level);
		Harl();
		~Harl();
};

#endif