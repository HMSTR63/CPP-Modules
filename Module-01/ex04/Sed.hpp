#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
    private :
        std::string filename;
        std::string s1;
        std::string s2;
    public :
        Sed(const std::string &fname, const std::string &str1, const std::string &str2);
        bool f_replace();
};  

#endif