

#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <vector>
Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &O)
{
	*this = O;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->holder = other.holder;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (holder.size() >= _N)
		throw FullSpanException();
	holder.push_back(n);
}

int Span::shortestSpan()
{
	if (holder.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp_v = holder;
	std::sort(tmp_v.begin(), tmp_v.end());
	int diff = tmp_v[1] - tmp_v[0];
	size_t x = 1;
	while (x < tmp_v.size())
	{
		int curr_diff = tmp_v[x] - tmp_v[x - 1];
		if (curr_diff < diff)
			diff = curr_diff; 
		x++;
	}
	return diff;
}

int Span::longestSpan()
{
	if (holder.size() <= 1)
		throw NoSpanException();
	int min_v = *std::min_element(holder.begin(), holder.end()); 
	int max_v =	*std::max_element(holder.begin(), holder.end());
	return (max_v - min_v);
}

const char* Span::FullSpanException::what() const throw()
{
	return "No space Left!!";
}

const char* Span::NoSpanException::what() const throw()
{
	return "No Span Found!!";
}