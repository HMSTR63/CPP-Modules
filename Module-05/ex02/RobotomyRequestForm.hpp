#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
   private:
    std::string _target;

   public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& O);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& O);

    void execute(const Bureaucrat& executor) const;
};

#endif  // !ROBOTOMYREQUESTFORM_HPP
