#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
   private:
    std::string _target;

   public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& O);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& O);

    void execute(const Bureaucrat& executor) const;
};

#endif  // !PRESIDENTIALPARDONFORM_HPP
