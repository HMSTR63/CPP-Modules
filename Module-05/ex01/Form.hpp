#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include <exception>
#include <iostream>
#include <ostream>
class Form
{
   private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExec;

   public:
    Form();
    ~Form();
    Form(const std::string name, const int gradeToSign, const int gradeToExec);
    Form(const Form& O);
    Form& operator=(const Form& O);

    std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

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

    void beSigned(Bureaucrat& B);
};

std::ostream& operator<<(std::ostream& OUT, Form const& O);

#endif
