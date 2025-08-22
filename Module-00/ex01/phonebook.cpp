/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 03:49:39 by sojammal          #+#    #+#             */
/*   Updated: 2025/08/16 03:49:40 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::adduser()
{
    static int user_count = 0;
    std::cout << "Adding user " << (user_count % 8) << '\n';
    users[user_count % 8].setData();
    std::cout << "User " << (user_count % 8) << " added successfully." << '\n';
    user_count++;
}


void    PhoneBook::searchuser()
{
    std::cout << std::setw(10) << "user_dex" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "|" << '\n';
    int h = -1;
    while (++h < 8)
        users[h].showDataRow(h);
    
    std::cout << "Enter Dex to show: ";
    std::string dex;
    std::getline(std::cin, dex);
    if (dex.length() == 1 && std::isdigit(dex[0]))
    {
        int user_dex = std::atoi(dex.c_str());
        if (user_dex >= 0 && user_dex < 8)
            users[user_dex].showData();
        else
            std::cout << "Invalid Dex" << '\n';
    }
    else
        std::cout << "Just Single Digit" << '\n'; 
}
