/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:31:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/19 19:16:27 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
	//std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed &other) {
	//std::cout << "Assignment operator called" << std::endl;
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
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(const float n) {
	//std::cout << "Float constructor called" << std::endl;
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

bool	Fixed::operator>(const Fixed &other) const {
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;

	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;

	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long	temp_result;

	temp_result = (long)this->_fixedPointValue * (long)other._fixedPointValue;
	result.setRawBits((int)(temp_result >> _fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	long	temp_result;

	if (other._fixedPointValue == 0) {
		std::cout << "error: division by zero in 'Fixed::operator/'" << std::endl;
		return (result); //retorna o default 0.0f.
	}

	temp_result = (((long)this->_fixedPointValue << this->_fractionalBits) / (long)other._fixedPointValue);
	result.setRawBits((int)(temp_result));
	return (result);
}

Fixed& Fixed::operator++() {
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed& Fixed::operator--() {
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed result;

	result = *this;
	this->_fixedPointValue += 1;
	return (result);
}

Fixed Fixed::operator--(int) {
	Fixed result;

	result = *this;
	this->_fixedPointValue -= 1;
	return (result);
}

Fixed& Fixed::min(Fixed &n1, Fixed &n2) {
	if (n1 < n2) {
		return (n1);
	}
	return (n2);
}

const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2) {
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed& Fixed::max(Fixed &n1, Fixed &n2) {
	if (n1 > n2) {
		return (n1);
	}
	return (n2);
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2) {
	if (n1 > n2)
		return (n1);
	return (n2);
}
