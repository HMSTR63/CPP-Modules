#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() 
{
	std::cout << "=====vector test=====" << std::endl;
	{
		std::vector<int> F;
		int x = 0;
		while (x < 10)
		{
			F.push_back(x * 10);
			x++;
		}
		std::vector<int>::iterator it = F.begin();
		while (it != F.end())
			std::cout << *it++ << " ";
		std::cout << std::endl;
		try {
			std::cout << "Fount it => " << *easyfind(F, 20)<< std::endl;
			*easyfind(F, 99);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=====List test=====" << std::endl;
	{
		std::list<int> l;
		int arr[] = {63, 12, 44, 16, 33, 11, 77, 4};
		int arr_size = sizeof(arr) / sizeof(arr[0]);
		int x = 0;
		while (x < arr_size)
			l.push_back(arr[x++]);
		std::list<int>::iterator p_l = l.begin();
		while (p_l != l.end())
			std::cout << *p_l++ << " ";
		std::cout << std::endl;
		try {
			std::cout << "Found it => " << *easyfind(l, 77) << std::endl;
			easyfind(l, 3);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=====Edge cases=====" << std::endl;
	{
		std::vector<int> v;
		try {
			easyfind(v, 0);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}