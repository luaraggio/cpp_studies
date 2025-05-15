/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:31:31 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/14 23:15:20 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixedPointValue; // Number of bits used to store the fixed-point value
		static const int _fractionalBits = 8;

	public:
		Fixed(); // Default Constructor
		Fixed(const Fixed &other); // Copy Constructor
		~Fixed(); // Destructor
		Fixed& operator=(const Fixed &other); // Copy Assignment Operator
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
