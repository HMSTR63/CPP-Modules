#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
   private:
    std::string _target;

   public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& O);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& O);

    void execute(const Bureaucrat& executor) const;
};

#endif  // !SHRUBBERYCREATIONFORM_HPP
