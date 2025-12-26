#include "Bureaucrat.hpp"

#include <ostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(63)
{
    if (_grade < 1) throw GradeTooHighException();
    if (_grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& O) : _name(O._name), _grade(O._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& O)
{
    if (this != &O) this->_grade = O._grade;
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

void Bureaucrat::incGrade()
{
    if (this->_grade == 1) throw GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::decGrade()
{
    if (this->_grade == 150) throw GradeTooLowException();
    this->_grade += 1;
}

int Bureaucrat::getGrade() const { return this->_grade; }

std::string Bureaucrat::getName() const { return this->_name; }

std::ostream& operator<<(std::ostream& OUT, Bureaucrat const& O)
{
    OUT << O.getName() << ", bureaucrat grade " << O.getGrade() << ".";
    return OUT;
}

Bureaucrat::~Bureaucrat() { std::cout << "Kill " << this->getName() << std::endl; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low !!"; }

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high !!";
}
