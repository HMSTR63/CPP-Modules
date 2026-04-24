#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int c, char** v)
{
    if (c != 2)
    {
        std::cerr << "Error: Bad arguments." << std::endl;
        std::cerr << "Usage: ./RPN \"8 9 * 9 -\"" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn;
        rpn.calcul(v[1]);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
