#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    private:
        std::string f_name;
        std::string l_name;
        std::string n_name;
        std::string p_number;
        std::string dark;
    public:
        void    setData();
        void    showData();
        void    showDataRow(int dex);
        std::string formatLine(std::string &line);
};

#endif