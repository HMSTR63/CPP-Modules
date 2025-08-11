#include <iostream>

int main()
{
    std::string brain_str = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain_str;
    std::string &stringREF = brain_str;

    std::cout << "The memory address of the string variable: " <<&brain_str << '\n';
    std::cout << "The memory address held by stringPTR: " << stringPTR << '\n';
    std::cout << "The memory address held by stringREF: " << &stringREF << '\n';
    std::cout << '\n';
    std::cout << "The value of the string variable: " << brain_str << '\n';
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << '\n';
    std::cout << "The value pointed to by stringREF: " << stringREF << '\n';
}
