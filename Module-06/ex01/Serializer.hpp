#pragma once

#include <stdint.h>

#include <iostream>

struct Data
{
    int x;
};

class Serializer
{
   private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& O);
    Serializer& operator=(const Serializer& O);

   public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
