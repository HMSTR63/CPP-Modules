#include <iostream>

int main(int c, char **v)
{
	if (c < 2)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << '\n';
	else
	{
		int h = 1;
		while (h < c)
		{
			int m = 0;
			while (v[h][m])
			{
				std::cout << (char)toupper(v[h][m++]);
			}
			h++;
		}
		std::cout << '\n';
	}

}
