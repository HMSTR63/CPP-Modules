#include "ShrubberyCreationForm.hpp"

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
    if (this->getSign() == false) throw AForm::FormNotSignedException();
    if (executer.getGrade() > this->getGradeToExec()) throw AForm::GradeTooLowException();

    std::ofstream ofile((this->_target + "_shrubbery").c_str());
    if (!ofile.is_open())
    {
        std::cerr << "Cant open this File" << std::endl;
        return;
    }
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
