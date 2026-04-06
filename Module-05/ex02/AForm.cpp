#include "AForm.hpp"

#include <ostream>

#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(63), _gradeToExec(63)
{
    this->_isSigned = false;
    if (this->_gradeToSign < 1 || this->_gradeToExec < 1) throw GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExec > 150) throw GradeTooLowException();
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    this->_isSigned = false;
    if (this->_gradeToSign < 1 || this->_gradeToExec < 1) throw GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExec > 150) throw GradeTooLowException();
}

AForm::~AForm() { std::cout << "kill " << this->getName() << "!!" << std::endl; }

AForm::AForm(const AForm& O)
    : _name(O._name), _isSigned(false), _gradeToSign(O._gradeToSign), _gradeToExec(O._gradeToExec)
{
}

AForm& AForm::operator=(const AForm& O)
{
    if (this != &O) this->_isSigned = O._isSigned;
    return *this;
}

void AForm::beSigned(Bureaucrat& B)
{
    if (B.getGrade() > this->_gradeToSign) throw GradeTooLowException();
    this->_isSigned = true;
}

std::string AForm::getName() const { return this->_name; }

bool AForm::getSign() const { return this->_isSigned; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExec() const { return this->_gradeToExec; }

std::ostream& operator<<(std::ostream& OUT, AForm const& O)
{
    OUT << O.getName() << " " << ((O.getSign() == true) ? " Signed " : " Not Signed ") << " "
        << O.getGradeToSign() << " " << O.getGradeToExec();
    return OUT;
}
const char* AForm::GradeTooLowException::what() const throw() { return "Grade is too low !!"; }

const char* AForm::GradeTooHighException::what() const throw() { return "Grade is too high !!"; }

const char* AForm::FormNotSignedException::what() const throw() { return "Form Not Signed !!"; }

const char* AForm::FileOpenException::what() const throw() { return "File Not Open !!"; }

void AForm::checkExecution(Bureaucrat const& executor) const
{
    if (this->getSign() == false) throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec()) throw AForm::GradeTooLowException();
}
