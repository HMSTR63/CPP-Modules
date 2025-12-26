#include "ScalarConverter.hpp"

#include <cctype>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& O) { (void)O; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& O)
{
    (void)O;
    return *this;
}

void ScalarConverter::convert(std::string s)
{
    double amount = 0.0;

    if (s.length() == 1 && !std::isdigit(s[0]))
        amount = static_cast<double>(s[0]);
    else
    {
        char* ends;
        amount = strtod(s.c_str(), &ends);
        if (*ends != '\0' && !(*ends == 'f' && *(ends + 1) == '\0'))
        {
            std::cout << "Error: impossible conversion" << std::endl;
            return;
        }
    }
    std::cout << "char: ";
    if (amount != amount || amount < 0 || amount > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<char>(amount)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(amount) << "'" << std::endl;
    std::cout << "int: ";
    if (amount != amount || amount > 2147483647 || amount < -2147483648)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(amount) << std::endl;
    std::cout << "float: ";
    float amountf = static_cast<float>(amount);
    std::cout << amountf;
    if (amount == amount && (amountf - static_cast<int>(amountf) == 0) &&
        (amount != std::numeric_limits<double>::infinity() &&
         amount != -std::numeric_limits<double>::infinity()))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: ";
    std::cout << amount;
    if (amount == amount && (amount - static_cast<int>(amount) == 0) &&
        (amount != std::numeric_limits<double>::infinity() &&
         amount != -std::numeric_limits<double>::infinity()))
        std::cout << ".0";
    std::cout << std::endl;
    return;
}
