#include "phonebook.hpp"

int main()
{
    std::string line;
    PhoneBook   list;

    while (63)
    {
        std::cout << "what is ur Command" << '\n';
        if (!std::getline(std::cin, line))
        {
            std::cout << "EOF, EXIT\n";
            break;
        }
        if (line == "ADD")
        {
            list.adduser();
        }
        else if (line == "SEARCH")
        {
            list.searchuser();
        }
        else if (line == "EXIT")
            break;
        else
            std::cout << "Invalid Command" << '\n';
    }
    return  (0);
}