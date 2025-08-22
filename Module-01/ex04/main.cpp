#include "Sed.hpp"

int main(int c, char **v)
{
    if (c != 4)
    {
        std::cout << "check num of args" << '\n';
        return (1);
    }
    Sed sed(v[1], v[2], v[3]);
    if (!sed.f_replace())
    {
        std::cout << "fail processe string" << '\n';
        return (1);
    }
    return (0);
}