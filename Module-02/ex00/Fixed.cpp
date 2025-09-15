#include "Fixed.hpp"

const int Fixed::n_bit = 8;

Fixed::Fixed() : nb(0)
{
	std::cout << "Default constructor called" << '\n';
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << '\n';
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << '\n';
	*this = original;
	
}

Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &original)
		this->nb = original.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << '\n';
	return (this->nb);
}

void Fixed::setRawBits(int const raw)
{
	this->nb = raw;
}