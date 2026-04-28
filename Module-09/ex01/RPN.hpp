#pragma once

#include <exception>
#include <iostream>
#include <stack>
#include <list>
#include <string>
class RPN
{
   private:
    std::stack<int, std::list<int> > _box;

   public:
    RPN();
    RPN(const RPN& O);
    RPN& operator=(const RPN& O);
    ~RPN();

    void calcul(const std::string& in);
};
