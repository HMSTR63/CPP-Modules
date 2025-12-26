#pragma once
#include <cstdlib>
#include <iostream>
class ScalarConverter
{
   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& O);
    ScalarConverter& operator=(const ScalarConverter& O);

   public:
    ~ScalarConverter();
    static void convert(std::string s);
};
