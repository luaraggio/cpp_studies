/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:31:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/14 23:19:57 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor calledr" << std::endl;
};

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
};

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
};

