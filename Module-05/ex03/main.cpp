#include <cstdlib>
#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::srand(time(NULL));
    {
        try  // ShrubberyCreationForm
        {
            Bureaucrat ham("HAMILTON", 132);
            ShrubberyCreationForm merForm("MERCEDES-FORM");
            Intern bono;
            AForm* toto;
            toto = bono.makeForm("shrubbery creation", "AMG");
            std::cout << *toto << std::endl;
            ham.signForm(merForm);
            ham.executeForm(merForm);
            delete toto;
        }
        catch (std::exception& e)
        {
            std::cout << "Shrubbery -> " << e.what() << std::endl;
        }
            try  // RobotomyRequestForm
            {
                Bureaucrat ver("VERSTAPEN", 33);
                RobotomyRequestForm redbullForm("REDBULL-FORM");
                ver.signForm(redbullForm);
                ver.executeForm(redbullForm);
            }
            catch (std::exception& e)
            {
                std::cout << "Robotomy -> " << e.what() << std::endl;
            }
            try  // PresidentialPardonForm
            {
                Bureaucrat nor("NORIS", 5);
                PresidentialPardonForm McLaren("McLaren-FORM");
                nor.signForm(McLaren);
                nor.executeForm(McLaren);
            }
            catch (std::exception& e)
            {
                std::cout << "PresidentialPardonForm ->" << e.what() << std::endl;
            }
    }
    return 0;
}
