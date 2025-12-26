#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
Intern::Intern() {}

Intern::~Intern() { std::cout << "Kill Intern!!" << std::endl; }

Intern::Intern(const Intern& O) { (void)O; }

Intern& Intern::operator=(const Intern& O)
{
    (void)O;
    return *this;
}

AForm* Intern::makeFormPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeFormRobotomy(std::string target) { return new RobotomyRequestForm(target); }

AForm* Intern::makeFormShrubbery(std::string target) { return new ShrubberyCreationForm(target); }

AForm* Intern::makeForm(std::string form, std::string target)
{
    std::string FormTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::* FormMaker[3])(std::string target) = {
        &Intern::makeFormShrubbery,
        &Intern::makeFormRobotomy,
        &Intern::makeFormPresidential,
    };

    int h = 0;
    while (h < 3)
    {
        if (form == FormTypes[h])
        {
            std::cout << "Intren creates " << form << std::endl;
            return (this->*FormMaker[h])(target);
        }
        h++;
    }
    std::cout << "Error: Intern does not recognize the form: " << form << std::endl;
    return NULL;
}
