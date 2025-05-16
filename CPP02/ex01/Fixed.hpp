/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:31:31 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/16 17:56:24 by lraggio          ###   ########.fr       */
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
		~Fixed(); // Destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed(const int n); // Constructor that takes a constant integer as a parameter
		Fixed(const float n); // Constructor that takes a constant float as a parameter
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
