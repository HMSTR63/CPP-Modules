#include <exception>
#include <ostream>

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc;

        btc.loadDb("data.csv");
        btc.processInput(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
