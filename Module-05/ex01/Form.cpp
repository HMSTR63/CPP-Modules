#include "Form.hpp"

#include <ostream>

#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _gradeToSign(63), _gradeToExec(63)
{
    this->_isSigned = false;
    if (this->_gradeToSign < 1 || this->_gradeToExec < 1) throw GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExec > 150) throw GradeTooLowException();
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    this->_isSigned = false;
    if (this->_gradeToSign < 1 || this->_gradeToExec < 1) throw GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExec > 150) throw GradeTooLowException();
}

Form::~Form() { std::cout << "kill " << this->getName() << std::endl; }

Form::Form(const Form& O)
    : _name(O._name), _isSigned(false), _gradeToSign(O._gradeToSign), _gradeToExec(O._gradeToExec)
{
}

Form& Form::operator=(const Form& O)
{
    if (this != &O) this->_isSigned = O._isSigned;
    return *this;
}

void Form::beSigned(Bureaucrat& B)
{
    if (B.getGrade() > this->_gradeToSign) throw GradeTooLowException();
    this->_isSigned = true;
}

std::string Form::getName() const { return this->_name; }

bool Form::getSign() const { return this->_isSigned; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExec() const { return this->_gradeToExec; }

std::ostream& operator<<(std::ostream& OUT, Form const& O)
{
    OUT << O.getName() << " " << ((O.getSign() == true) ? " Signed " : " Not Signed ") << " "
        << O.getGradeToSign() << " " << O.getGradeToExec();
    return OUT;
}
const char* Form::GradeTooLowException::what() const throw() { return "Grade is too low !!"; }

const char* Form::GradeTooHighException::what() const throw() { return "Grade is too high !!"; }
