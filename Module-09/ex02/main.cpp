#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/select.h>
#include <vector>
#include <iomanip>

bool isValidNum(const std::string& s) {
	if (s.empty())
		return false;
	for (size_t x = 0; x < s.length(); ++x) {
		if (!std::isdigit(s[x]))
			return false;
	}
	return true;
}

std::vector<int> parsArg(int c, char **v) {
	std::vector<int> input;

	for (int x = 1; x < c; ++x) {
		std::string arg = v[x];
		if (!isValidNum(arg))
			throw std::invalid_argument("Error");
		long v = std::atol(arg.c_str());
		if (v > 2147483647) {
			throw std::invalid_argument("Error");
		}
		input.push_back(static_cast<int>(v));
	}
	return input;
}

void ft_print(const std::string& pref, const std::vector<int>& vec) {
	std::cout << pref;
	for (size_t x = 0; x < vec.size(); ++x) {
		if (x == 4 && vec.size() > 5) {
			std::cout << "[...]";
			break;
		}
		std::cout << vec[x] << " ";
	}
	std::cout << std::endl;
}

int main(int c, char **v) {
	if (c < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		std::vector<int> input = parsArg(c, v);
		ft_print("Before: ", input);
		PmergeMe s;
		struct timeval start, end;
		gettimeofday(&start, NULL);
		s.sortVector(input);
		gettimeofday(&end, NULL);

		double v_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

		ft_print("After:  ", s.getVecResult());
		std::cout << "Time to process a range of " << input.size() 
					<< " elements with std::vector : " 
					<< std::fixed << std::setprecision(5) << v_time << " us" << std::endl;

		gettimeofday(&start, NULL);
		s.sortDeque(input);
		gettimeofday(&end, NULL);

		double d_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

		std::cout << "Time to process a range of " << input.size() 
					<< " elements with std::deque  : " 
					<< std::fixed << std::setprecision(5) << d_time << " us" << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}