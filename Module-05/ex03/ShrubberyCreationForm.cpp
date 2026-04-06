#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("ShrubberyCreationForm")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm(target, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& O)
    : AForm(O), _target(O._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& O)
{
    if (this != &O)
    {
        AForm::operator=(O);
        this->_target = O._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "kill ShrubberyCreationForm!!" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{
    this->checkExecution(executer);
    std::ofstream ofile((this->_target + "_shrubbery").c_str());
    if (!ofile.is_open()) throw AForm::FileOpenException();
    ofile << "       _-_" << std::endl;
    ofile << "    /~~   ~~\\" << std::endl;
    ofile << " /~~         ~~\\" << std::endl;
    ofile << "{               }" << std::endl;
    ofile << " \\  _-     -_  /" << std::endl;
    ofile << "   ~  \\\\ //  ~" << std::endl;
    ofile << "_- -   | | _- _" << std::endl;
    ofile << "  _ -  | |   -_" << std::endl;
    ofile << "      // \\\\" << std::endl;
    ofile.close();
}
