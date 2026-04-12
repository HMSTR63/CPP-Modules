#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
class Intern
{
   private:
    AForm* makeFormShrubbery(std::string target);
    AForm* makeFormRobotomy(std::string target);
    AForm* makeFormPresidential(std::string target);

   public:
    Intern();
    ~Intern();
    Intern(const Intern& O);
    Intern& operator=(const Intern& O);

    AForm* makeForm(std::string form, std::string target);
};
#endif  // !INTERN_HPP
