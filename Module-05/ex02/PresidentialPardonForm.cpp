#include "PresidentialPardonForm.hpp"

#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("PresidentialPardonForm")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm(target, 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& O)
    : AForm(O), _target(O._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& O)
{
    if (this != &O)
    {
        AForm::operator=(O);
        this->_target = O._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "kill PresidentialPardonForm!!" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSign()) throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec()) throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
