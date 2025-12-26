/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 03:50:22 by sojammal          #+#    #+#             */
/*   Updated: 2025/08/18 01:08:45 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t hammer_time = std::time(NULL);
    struct tm *ht = std::localtime(&hammer_time);
    char time_buff[20];
    std::strftime(time_buff, sizeof(time_buff), "[%Y%m%d_%H%M%S]", ht);
    std::cout << time_buff;
    std::cout << " ";
}

Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << '\n';
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << '\n';
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

int Account::checkAmount() const
{
    return (this->_amount);
}

void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << '\n';
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << '\n';
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->checkAmount() << ";";
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->checkAmount() << ";";
    if (withdrawal > this->checkAmount())
    {
        std::cout << "withdrawal:refused" << '\n';
        return true;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals += 1;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << '\n';
    return false;
}
