#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat
{
   private:
    const std::string _name;
    int _grade;

   public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& O);
    Bureaucrat& operator=(const Bureaucrat& O);
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
    int getGrade() const;
    std::string getName() const;
    void incGrade();
    void decGrade();
};

std::ostream& operator<<(std::ostream& OUT, Bureaucrat const& O);

#endif
