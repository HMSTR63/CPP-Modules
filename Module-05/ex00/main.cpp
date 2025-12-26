#include "Bureaucrat.hpp"
// catch by reference!

int main()
{
    try
    {
        Bureaucrat h("HMSTR", 2);
        std::cout << h << std::endl;
        h.incGrade();
        std::cout << h << std::endl;
        h.incGrade();
        std::cout << h << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
