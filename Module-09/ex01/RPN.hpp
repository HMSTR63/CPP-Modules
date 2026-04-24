#pragma once

#include <exception>
#include <iostream>
#include <stack>
#include <string>
class RPN
{
   private:
    std::stack<int> _box;

   public:
    RPN();
    RPN(const RPN& O);
    RPN& operator=(const RPN& O);
    ~RPN();

    void calcul(const std::string& in);
};
