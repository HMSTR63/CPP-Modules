#pragma once

#include <iostream>
#include <map>
#include <string>
class BitcoinExchange
{
   private:
    std::map<std::string, float> _db;

   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& O);
    BitcoinExchange& operator=(const BitcoinExchange& O);

    void loadDb(const std::string& db_filename);
    void processInput(const std::string& input_filename);
    ~BitcoinExchange();
};
