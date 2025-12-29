#pragma once

#include <exception>
template <typename T>

class Array
{
   private:
    T* _data;
    unsigned int _size;

   public:
    Array();
    Array(unsigned int size);
    Array(const Array& O);
    Array& operator=(const Array& O);
    ~Array();

    T& operator[](unsigned int dex);
    const T& operator[](unsigned int dex) const;
    unsigned int size() const;

    class OutOfRange : public std::exception
    {
       public:
        const char* what() const throw();
    };
};

#include "Array.tpp"
