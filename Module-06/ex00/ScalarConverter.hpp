#pragma once
#include <cstdlib>
#include <iostream>
class ScalarConverter
{
   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& O);
    ScalarConverter& operator=(const ScalarConverter& O);
    ~ScalarConverter();

   public:
    static void convert(std::string s);
};
