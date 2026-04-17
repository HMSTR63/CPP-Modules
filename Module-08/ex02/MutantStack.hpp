#pragma once

#include <stack>
template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
		typedef typename std::stack<T>::container_type::iterator  iterator;
		typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

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
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_reverse_iterator crbegin() const { return this->c.rbegin(); }
		const_reverse_iterator crend() const { return this->c.rend(); }
};