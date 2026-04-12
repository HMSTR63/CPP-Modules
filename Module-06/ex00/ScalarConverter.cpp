#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
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
    if (s.empty())
    {
        std::cout << "Error: empty input" << std::endl;
        return;
    }
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
    bool isNan = (amount != amount);
    bool isInf = (amount == std::numeric_limits<double>::infinity() ||
                  amount == -std::numeric_limits<double>::infinity());
    std::cout << "char: ";
    if (isInf || isNan || amount < 0 || amount > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<char>(amount)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(amount) << "'" << std::endl;

    std::cout << "int: ";
    if (isInf || isNan || amount > std::numeric_limits<int>::max() ||
        amount < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(amount) << std::endl;

    std::cout << "float: ";
    float amountf = static_cast<float>(amount);
    std::cout << amountf;
    if (!isNan && !isInf && amountf == std::floor(amountf)) std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: ";
    std::cout << amount;
    if (!isNan && !isInf && amount == std::floor(amount)) std::cout << ".0";
    std::cout << std::endl;
    return;
}
