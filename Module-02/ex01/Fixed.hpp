#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
		Fixed(const int h);
		Fixed(const float h);
		int	toInt(void) const;
		float	toFloat(void) const; 
		void setRawBits(int const raw);
		int getRawBits() const;
};

std::ostream &operator<<(std::ostream &OUT, Fixed const &obj);

#endif