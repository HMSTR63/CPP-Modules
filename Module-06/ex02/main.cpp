#include <cstdlib>
#include <ctime>
#include <exception>
#include <typeinfo>
#include "Base.hpp"

Base* generate(void)
{
    int x = std::rand() % 3;
    switch (x)
    {
        case 0:
            std::cout << "Generate => A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generate => B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generate => C" << std::endl;
            return new C();
        default:
            std::cout << "Generate Error" << std::endl;
            return NULL;
    }
}

void identify(Base* p)
{
	if (p == NULL)
    {
        std::cout << "Pointer is NULL" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &e){}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        std::cout << "Unknown" << std::endl;
    }
}

int main()
{
    std::srand(time(NULL));
    int x = 0;
    while (x < 10)
    {
        Base* papa = generate();
        identify(papa);
        identify(*papa);
        delete papa;
		std::cout << "----------------" << std::endl;
        x++;
    }
    return 0;
}
