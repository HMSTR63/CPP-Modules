#include "RPN.hpp"

#include <cctype>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& O) { *this = O; }

RPN& RPN::operator=(const RPN& O)
{
    if (this != &O) this->_box = O._box;
    return *this;
}

RPN::~RPN() {}

void RPN::calcul(const std::string& in)
{
    std::istringstream tokens(in);
    std::string token;

    while (tokens >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
        {
            int n = std::atoi(token.c_str());
            _box.push(n);
        }
        else if (token == "+" || token == "-" || token == "/" || token == "*")
        {
            if (_box.size() < 2)
                throw std::runtime_error("Error: not enough numbers for operation");
            int r_num = _box.top();
            _box.pop();
            int l_num = _box.top();
            _box.pop();
            switch (token[0])
            {
                case '+':
                    _box.push(l_num + r_num);
                    break;
                case '-':
                    _box.push(l_num - r_num);
                    break;
                case '*':
                    _box.push(l_num * r_num);
                    break;
                case '/':
                    if (r_num == 0) throw std::runtime_error("Error: cant divide by zero");
                    _box.push(l_num / r_num);
                    break;
            }
        }
        else
        {
            throw std::runtime_error("Error: invalid Character");
        }
    }
    if (_box.size() != 1) throw std::runtime_error("Error: invalid RPN expression");
    std::cout << _box.top() << std::endl;
}
