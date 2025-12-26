#include "RobotomyRequestForm.hpp"

#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("RobotomyRequestForm")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm(target, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& O)
    : AForm(O), _target(O._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& O)
{
    if (this != &O)
    {
        AForm::operator=(O);
        this->_target = O._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "kill RobotomyRequestForm!!" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSign()) throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec()) throw AForm::GradeTooLowException();
    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully 50% of the time"
                  << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;
}
