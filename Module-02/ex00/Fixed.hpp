#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int nb;
		static const int n_bit;
	public :
		Fixed();
		~Fixed();
		Fixed(const Fixed &original);
		Fixed &operator=(const Fixed &original);
		void setRawBits(int const raw);
		int getRawBits() const;

};

#endif