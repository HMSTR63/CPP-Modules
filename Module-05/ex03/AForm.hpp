#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

#include <exception>
#include <iostream>
#include <ostream>
#include <string>
class AForm
{
   private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExec;

   public:
    AForm();
    virtual ~AForm();
    AForm(const std::string name, const int gradeToSign, const int gradeToExec);
    AForm(const AForm& O);
    AForm& operator=(const AForm& O);

    std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    virtual void execute(Bureaucrat const& executor) const = 0;

    class GradeTooHighException : public std::exception
    {
       public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
       public:
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
       public:
        const char* what() const throw();
    };

    void beSigned(Bureaucrat& B);
};

std::ostream& operator<<(std::ostream& OUT, AForm const& O);

#endif
