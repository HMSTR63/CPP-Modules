#pragma once

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T* arr, size_t size, F func)
{
    if (!arr) return;
    size_t h = 0;
    while (h < size)
    {
        func(arr[h]);
        h++;
    }
}

template <typename T>
void print(const T& ar)
{
    std::cout << "'" << ar << "'" << " ";
}
