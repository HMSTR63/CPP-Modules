/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 03:49:42 by sojammal          #+#    #+#             */
/*   Updated: 2025/08/16 03:49:43 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    std::string line;
    PhoneBook   list;
    while (63)
    {
        std::cerr << "what is ur Command" << '\n';
        if (!std::getline(std::cin, line))
        {
            std::cout << "EOF, EXIT\n";
            break;
        }
        if (line == "ADD")
        {
            list.adduser();
        }
        else if (line == "SEARCH")
        {
            list.searchuser();
        }
        else if (line == "EXIT")
            break;
        else
            std::cerr << "Invalid Command" << '\n';
    }
    return  (0);
}