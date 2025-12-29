#include "iter.hpp"

int main()
{
    int const iarr[] = {63, 44, 33, 16, 12};
    std::string arr[] = {"HMSTR", "HAMILTON"};
    iter(iarr, 5, print<int>);
    std::cout << std::endl;
    iter(arr, 2, print<std::string>);
    std::cout << std::endl;
}
