/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:31:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/16 18:14:09 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return (*this);
};

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue); //returns the raw value of the fixed-point value
};

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

//Essa função me permite utilizar std::cout << fixed;
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}
