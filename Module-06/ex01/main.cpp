#include "Serializer.hpp"

int main()
{
    Data ptrHMSTR;

    Data* HMSTR = &ptrHMSTR;
    HMSTR->x = 63;
    std::cout << "The value of Data before ";
    std::cout << HMSTR->x << std::endl;
    std::cout << "Data Address => " << HMSTR << std::endl;
    uintptr_t uHMSTR = Serializer::serialize(HMSTR);
    std::cout << "=== Serializing ===" << std::endl;
    std::cout << "uintptr value => " << uHMSTR << std::endl;
    HMSTR->x = 44;
    std::cout << "=== DeSerializing ===" << std::endl;
    Data* OHMSTR = Serializer::deserialize(uHMSTR);
    std::cout << "The value of Data after ";
    std::cout << OHMSTR->x << std::endl;
    std::cout << "Data Address => " << OHMSTR << std::endl;
}
