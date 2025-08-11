#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact users[8];
    public:
        void    adduser();
        void    searchuser();
};

#endif