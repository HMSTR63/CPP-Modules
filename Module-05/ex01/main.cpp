#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        try
        {
            Form form1("BadForm", 0, 0);
            std::cout << form1 << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat ham("HAMILTON", 1);
            Form mer("MERCEDES", 50, 50);
            std::cout << mer << std::endl;
            ham.signForm(mer);
            std::cout << mer << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat ver("VERSTAPEN", 150);
            Form mer("MERCEDES", 50, 50);
            std::cout << mer << std::endl;
            ver.signForm(mer);
            std::cout << mer << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
