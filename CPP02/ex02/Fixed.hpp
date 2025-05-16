/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:31:31 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/16 19:55:09 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
	private:
		int _fixedPointValue; // Number of bits used to store the fixed-point value
		static const int _fractionalBits = 8;

	public:
		Fixed(); // Default Constructor
		Fixed(const Fixed &other); // Copy Constructor
		Fixed& operator=(const Fixed &other); // Copy Assignment Operator
		Fixed(const int n); // Constructor that takes a constant integer as a parameter
		Fixed(const float n); // Constructor that takes a constant float as a parameter
		~Fixed(); // Destructor

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed& operator++(); // Modify state and returns itself
		Fixed operator++(int n); // Returns before modify
		Fixed& operator--();
		Fixed operator--(int n);

		static Fixed& min(Fixed &n1, Fixed &n2);
		const static Fixed& min(const Fixed &n1, const Fixed &n2);
		static Fixed& max(Fixed &n1, Fixed &n2);
		const static Fixed& max(const Fixed &n1, const Fixed &n2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
