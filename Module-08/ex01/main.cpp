#include "Span.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <vector>

int main()
{
	srand(time(NULL));
	std::cout << "=== Normal Test ===" << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;		
	}
	std::cout << "=== Empty Span Test ===" << std::endl;
	Span empty_sp(0);
	try {
		empty_sp.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "=== 63,000 number test ===" << std::endl;
	Span bigSpan(63000);
	try {
		std::vector<int> random_num;
		int i = 0;
		while (i < 63000)
		{
			random_num.push_back(rand());
			i++;
		}
		bigSpan.addNumber(random_num.begin(), random_num.end());
		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << bigSpan.longestSpan() << std::endl;
	} catch (std::exception &e) {	
		std::cout << e.what() << std::endl;
	}
	return 0;
}