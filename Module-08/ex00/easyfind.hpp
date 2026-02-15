#pragma once

#include <algorithm>
#include <exception>

class NoElementFound : public std::exception
{
	public:
		const char * what() const throw() {
			return "No Element Found!!";
		}
};

template<typename T>

typename T::iterator easyfind(T &holder, int Tofind)
{
	typename T::iterator F = std::find(holder.begin(), holder.end(), Tofind);
	if (F == holder.end())
		throw NoElementFound();
	return F;
}