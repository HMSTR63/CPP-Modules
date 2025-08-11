#include <iostream>
#include <fstream>
int main()
{
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        std::cerr << "no file open" << '\n';
        return (1);
    }
    std::ofstream out("output.txt");
    if (!out.is_open())
    {
        std::cerr << "no file open" << '\n';
        return (1);      
    }
    std::string read;
    while (std::getline(in, read))
    {

        out << read << '\n';
    }
    in.close();
    out.close();
}