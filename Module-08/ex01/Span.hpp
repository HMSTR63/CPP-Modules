#pragma once 

#include <exception>
#include <iterator>
#include <vector>

class Span {
	private:
		unsigned int _N;
		std::vector<int> holder;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &O);
		Span &operator=(const Span &O);

		void	addNumber(int number);
		template<typename iT>
		void	addNumber(iT begin, iT end)
		{
			int range = std::distance(begin, end);
			if (holder.size() + static_cast<unsigned int>(range) > _N)
				throw FullSpanException();
			holder.insert(holder.end(), begin, end);
		}

		int	shortestSpan();
		int	longestSpan();

		class FullSpanException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};