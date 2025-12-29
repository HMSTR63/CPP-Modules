// #include <cstdlib>
#include <exception>
#include <iostream>

#include "Array.hpp"
int main()
{
    // ============================================
    // TEST 1: Default Constructor (Empty Array)
    // ============================================
    std::cout << "--- TEST 1: EMPTY ARRAY ---" << std::endl;
    Array<int> h;
    std::cout << "Size of h: " << h.size() << std::endl;
    // ============================================
    // TEST 2: String Array & Access Operator []
    // ============================================
    std::cout << "--- TEST 2: STRING ARRAY ---" << std::endl;
    Array<std::string> a(2);
    a[0] = "HMSTR";
    a[1] = "HAMILTON";

    // Access & Size
    std::cout << "Size of a: " << a.size() << std::endl;
    std::cout << "Content:   " << a[0] << " " << a[1] << std::endl;
    // ============================================
    // TEST 3: Exception Handling (Out of Bounds)
    // ============================================
    std::cout << "--- TEST 3: EXCEPTION HANDLING ---" << std::endl;
    try
    {
        std::cout << a[2] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }
    // ============================================
    // TEST 4: Deep Copy Verification
    // ============================================
    std::cout << "--- TEST 4: DEEP COPY CHECK ---" << std::endl;
    Array<int> b(2);
    b[0] = 63;
    Array<int> c(b);
    c[0] = 44;
    if (b[0] == 63)
        std::cout << "SUCCESS: Deep Copy OK! Original 'b' is still: " << b[0] << std::endl;
    else
        std::cout << "FAILURE: Deep Copy FAILED! Original 'b' changed to: " << b[0] << std::endl;

    std::cout << "Copy 'c' value is: " << c[0] << std::endl;
    return 0;
}  // the main.cpp
// #include <iostream>
//
// #include "Array.hpp"
//
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     // SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[0] = 0;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete[] mirror;  //
//     return 0;
// }
