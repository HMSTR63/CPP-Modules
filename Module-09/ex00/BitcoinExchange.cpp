#include "BitcoinExchange.hpp"

#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& O) {
    *this = O;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& O) {
    if (this != &O) {
        this->_db = O._db;
    }
    return *this;
}

std::string ft_trim(const std::string& s)
{
    size_t f = s.find_first_not_of(" \f\r\n");
    if (f == std::string::npos) return "";
    size_t l = s.find_last_not_of(" \f\r\n");
    return s.substr(f, l - f + 1);
}

bool isValidDate(const std::string& date)
{
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());
    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    return true;
}

void BitcoinExchange::loadDb(const std::string& db_filename)
{
    std::ifstream file(db_filename.c_str());
    if (!file.is_open()) throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line);
    while (getline(file, line))
    {
        size_t p_comma = line.find(',');
        if (p_comma != std::string::npos)
        {
            std::string date = ft_trim(line.substr(0, p_comma));
            float v = std::atof(line.substr(p_comma + 1).c_str());
            _db[date] = v;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& input_filename)
{
    std::ifstream file(input_filename.c_str());
    if (!file.is_open()) throw std::runtime_error("Error: could not open input file.");
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        size_t p_pip = line.find('|');
        if (p_pip == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = ft_trim(line.substr(0, p_pip));
        std::string v_str = ft_trim(line.substr(p_pip + 1));
        if (v_str.empty())
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
		bool valid_number = true;
        int dot_count = 0;
        for (size_t i = 0; i < v_str.length(); ++i) {
            if (v_str[i] == '.') 
				dot_count++;
            else if (!isdigit(v_str[i]) && !(i == 0 && v_str[i] == '-')) 
				valid_number = false;
        }
        if (!valid_number || dot_count > 1) {
            std::cout << "Error: not a number => " << v_str << std::endl;
            continue;
        }
        float v = atof(v_str.c_str());
        if (v < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (v > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = _db.lower_bound(date);

        if (it == _db.end())
        {
            it--;
        }
        else if (it->first != date)
        {
            if (it == _db.begin())
            {
                std::cout << "Error: date it too early." << std::endl;
                continue;
            }
            it--;
        }
        float res = v * it->second;
        std::cout << date << " => " << v << " = " << res << std::endl;
    }
    file.close();
}
