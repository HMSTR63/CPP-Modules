#include "Serializer.hpp"

int main()
{
    Data ptrHMSTR;
    Data* HMSTR = &ptrHMSTR;
    HMSTR->x = 63;

    std::cout << "--- BEFORE SERIALIZATION ---" << std::endl;
    std::cout << "Original Pointer Address : " << HMSTR << std::endl;
    std::cout << "Original Data Value (x)  : " << HMSTR->x << std::endl;

    std::cout << "\n=== Serializing ===" << std::endl;
    uintptr_t uHMSTR = Serializer::serialize(HMSTR);
    std::cout << "Raw uintptr_t value      : " << uHMSTR << std::endl;

    HMSTR->x = 44;

    std::cout << "\n=== DeSerializing ===" << std::endl;
    Data* OHMSTR = Serializer::deserialize(uHMSTR);

    std::cout << "--- AFTER DESERIALIZATION ---" << std::endl;
    std::cout << "Restored Pointer Address : " << OHMSTR << std::endl;
    std::cout << "Restored Data Value (x)  : " << OHMSTR->x << std::endl;

    std::cout << "\n=== FINAL CHECK ===" << std::endl;
    if (HMSTR == OHMSTR)
        std::cout << "SUCCESS: Both pointers hold the exact same memory address!" << std::endl;
    else
        std::cout << "ERROR: Pointers do not match!" << std::endl;

    return 0;
}
