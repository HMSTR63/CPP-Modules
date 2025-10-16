/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:13:45 by sojammal          #+#    #+#             */
/*   Updated: 2025/10/16 23:13:46 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		bool operator>(const Fixed &op) const;
		bool operator<(const Fixed &op) const;
		bool operator>=(const Fixed &op) const;
		bool operator<=(const Fixed &op) const;
		bool operator==(const Fixed &op) const;
		bool operator!=(const Fixed &op) const;

		Fixed	operator+(const Fixed &op) const;
		Fixed	operator-(const Fixed &op) const;
		Fixed	operator*(const Fixed &op) const;
		Fixed	operator/(const Fixed &op) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed &min(Fixed &p1, Fixed &p2);
		static const Fixed &min(const Fixed &p1, const Fixed &p2);
		static Fixed &max(Fixed &p1, Fixed &p2);
		static const Fixed &max(const Fixed &p1, const Fixed &p2);


		Fixed(const int h);
		Fixed(const float h);
		int	toInt(void) const;
		float	toFloat(void) const;
		void setRawBits(int const raw);
		int getRawBits() const;
};

std::ostream &operator<<(std::ostream &OUT, Fixed const &obj);

#endif