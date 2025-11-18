#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(const Brain &original)
{
    std::cout << "Brain copy constructed" << std::endl;
    *this = original;
}

Brain &Brain::operator=(const Brain &original)
{
    std::cout << "Brain copy assigmant constructed" << std::endl;
    if (this != &original)
    {
        int i = 0;
        while (i < 100)
        {
            this->ideas[i] = original.ideas[i];
            i++;
        }
    }
    return *this;
}