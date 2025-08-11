#include "Contact.hpp"

bool space(const std::string &str)
{
    for (size_t h = 0; h < str.length(); h++)
    {
        if (str[h] == ' ')
            return true;
    }
    return false;  
}

std::string getinput(const std::string &ms)
{
    std::string line;
    while (line.empty() || space(line))
    {
        std::cout << ms;
        std::getline(std::cin, line);
        if (line.empty() || space(line))
            std::cout << "First name cannot be empty. Please try again" << '\n';
    }
    return line;
}

void    Contact::setData()
{
    this->f_name = getinput("Enter the first name ");
    this->l_name = getinput("Enter the last name ");
    this->n_name = getinput("Enter the nickname ");
    this->p_number = getinput("Enter the phone number ");
    this->dark = getinput("Enter the darkest secret ");
}

void    Contact::showData()
{
    std::cout << "First Name: " << f_name << '\n';
    std::cout << "Last Name " << l_name << '\n';
    std::cout << "Nickname " << n_name << '\n';
    std::cout << "Phone Number: " << p_number << '\n';
    std::cout << "Darkest Secret: " << dark << '\n';
}

std::string Contact::formatLine(std::string &line)
{
    if (line.length() > 10)
        return line.substr(0, 9) + ".";
    else
        return std::string(10 - line.length(), ' ') + line;
}

void    Contact::showDataRow(int dex)
{
    std::cout << std::setw(10) << dex << "|" << formatLine(f_name) << "|" << formatLine(l_name) << "|" << formatLine(n_name) << "|" << '\n';
}