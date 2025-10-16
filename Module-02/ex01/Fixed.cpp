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

Fixed::Fixed(const int h)
{
	std::cout << "Int constructor called" << std::endl;
	nb = h * (1 << n_bit); // 1 << 8 == 256
}

Fixed::Fixed(const float h)
{
	std::cout << "Float constructor called" << std::endl;
	nb = roundf(h * (1 << n_bit));
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
	return (this->nb);
}

void Fixed::setRawBits(int const raw)
{
	this->nb = raw;
}

int Fixed::toInt(void) const
{
	return nb / (1 << n_bit); 
}

float	Fixed::toFloat(void) const
{
	return (float)nb / (1 << n_bit);
}

std::ostream &operator<<(std::ostream &OUT, Fixed const &obj)
{
	OUT << obj.toFloat();
	return OUT;
}