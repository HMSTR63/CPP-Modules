#include "Sed.hpp"

Sed::Sed(const std::string &fname, const std::string &str1, const std::string &str2)
{
    this->filename = fname;
    this->s1 = str1;
    this->s2 = str2;
}

bool Sed::f_replace()
{
    std::ifstream in_file(this->filename);
    if (!in_file.is_open())
    {
        std::cerr << "cant open the file" << '\n';
        return (false);
    }
    std::ofstream out_file(this->filename + ".replace");
    if (!out_file.is_open())
    {
        std::cerr << "cant open the file" << '\n';
        return (false);
    }
    std::string read_file;
    while (std::getline(in_file, read_file))
    {
        size_t read_pos = 0;
        while (true)
        {
            read_pos = read_file.find(this->s1, read_pos);
            // if (!read_pos)
            //     break;
            read_file.erase(read_pos, this->s1.length());
            read_file.insert(read_pos, this->s2);
            read_pos += this->s2.length();
        }
        out_file << read_file << '\n';
    }
    return (true);

}