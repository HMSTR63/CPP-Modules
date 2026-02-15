#pragma once

#include <stack>
template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
		typedef typename std::stack<T>::container_type::iterator  iterator;

		MutantStack() {};
		MutantStack(const MutantStack &O) : std::stack<T>(O) {};
		MutantStack &operator=(const MutantStack &O) {
			if (this != &O)
				std::stack<T>::operator=(O);
			return *this;
		};
		~MutantStack() {};
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};